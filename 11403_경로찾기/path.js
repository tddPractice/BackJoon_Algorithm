/*

2018 Jan 29, made by Moon

*/
var fs = require('fs');
var input = fs.readFileSync('./txt.txt').toString().split('\n');
var N = parseInt(input[0]);
input.shift();
var ix, ixLen, jx, jxLen, pathInfo = [], rowData;
for(ix = 0, ixLen = input.length; ix < ixLen; ix++){
    pathInfo[ix] = [];
    rowData = input[ix].split(' ');
    for(jx = 0, jxLen = rowData.length; jx < jxLen; jx++){
        pathInfo[ix].push(parseInt(rowData[jx]));
    }
}

var graph = [];
var path = [];
var visited = [];

function initGraph(){
    var ix, ixLen, jx, jxLen;
    for(ix = 0, ixLen = pathInfo.length; ix < ixLen; ix++){
        graph[ix] = pathInfo[ix].slice();
    }

    for(ix = 0, ixLen = N; ix < ixLen; ix++){
        path[ix] = [];
        for(jx = 0, jxLen = N; jx < jxLen; jx++){
            path[ix][jx] = 0;
        }
    }

    initVisited();
}

function dfs(curNode, head, isStart) {
    var ix, ixLen;

    if(!isStart) {
        visited[curNode] = true;
        path[head][curNode] = 1;
    }

    for (ix = 0, ixLen = graph[curNode].length; ix < ixLen; ix++) {
        if(graph[curNode][ix] !== 0 && !visited[ix]){
            dfs(ix, head);
        }
    }
}

function initVisited() {
    var ix, ixLen;
    for (ix = 0, ixLen = N; ix < ixLen; ix++) {
        visited[ix] = false;
    }
}

function dfsAll() {
    var i, ixLen, head;
    for (i = 0, ixLen = graph.length; i < ixLen; i++) {
        head = i;
        dfs(i, head, true);
        initVisited();
    }
}

function printPath(){
    var ix, ixLen, result;
    for (ix = 0, ixLen = path.length; ix < ixLen; ix++) {
        result = path[ix].join(' ')
        console.log("%s", result);
    }
}

function main(){
    initGraph();
    dfsAll();
    printPath();
}

main();