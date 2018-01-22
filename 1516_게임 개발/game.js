/*

2018 Jan 22, made by Moon

*/
var fs = require('fs');
var input = fs.readFileSync('/dev/stdin').toString().split('\n');
var N = parseInt(input[0]);
input.shift();

var M = input.map(function(row){
    var data = row.split(' ');
    data.pop();
    return data.map(function(d){
        return parseInt(d);
    });
});

var graph = {};
var visited = [];

function initGraph() {
    var ix, ixLen, needTime, outDegree = [], inDegree = 0;

    for (ix = 1, ixLen = N; ix <= ixLen; ix++) {
        graph[ix] = {
            needTime  : 0,
            totalTime : 0,
            inDegree  : 0,
            outDegree : []
        };
        visited[ix] = false;
    }

    for (ix = 1, ixLen = N; ix <= ixLen; ix++) {
        needTime = M[ix-1][0];
        M[ix-1].shift();

        while (M[ix - 1].length) {
            inDegree++;
            graph[M[ix-1].shift()].outDegree.push(ix);
        }

        graph[ix] = {
            needTime  : needTime,
            totalTime : needTime,
            outDegree : outDegree,
            inDegree  : inDegree
        };

        inDegree  = 0;
        outDegree = [];
    }
}

function getShortestTime(){
    var queue = [];

    getZeroIndegree(queue);

    var curNode, children;
    while(visited.indexOf(false) !== -1) {
        while (queue.length) {
            curNode = queue.shift();
            children = graph[curNode].outDegree;
            children.map(function (node) {
                graph[node].inDegree--;
                graph[node].totalTime = Math.max(graph[node].totalTime, graph[node].needTime + graph[curNode].totalTime);
            });
            console.log(graph[curNode].totalTime);

            visited[curNode] = true;
        }
        getZeroIndegree(queue);
    }
}

function getZeroIndegree(queue){
    var ix, ixLen;
    for (ix = 1, ixLen = N; ix <= ixLen; ix++) {
        if(graph[ix].inDegree === 0 && !visited[ix]){
            queue.push(ix);
        }
    }
}

function main(){
    initGraph();
    getShortestTime();
}
main();
