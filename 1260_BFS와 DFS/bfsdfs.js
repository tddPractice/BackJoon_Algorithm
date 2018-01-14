/*

2018 Jan 14, made by Moon

*/
var fs = require('fs');
var input = fs.readFileSync('/dev/stdin').toString().split('\n');
var [nodeN, edgeN, root] = input[0].split(' ').map(function(data){return parseInt(data)});

var ix, ixLen, jx, jxLen, graph = [];
for(ix = 0, ixLen = nodeN; ix <= ixLen; ix++){
    graph[ix] = new Array(ixLen + 1);
    for(jx = 0, jxLen = ixLen + 1; jx < jxLen; jx++){
        graph[ix][jx] = 0;
    }
}
input.map(function(data, i){
    if(i === 0) return;
    var r,c;
    r = parseInt(data.split(' ')[0]);
    c = parseInt(data.split(' ')[1]);
    graph[r][c] = graph[c][r] = 1;
});

var visited = [];
for(ix = 0, ixLen = nodeN; ix <= ixLen; ix++){
    visited[ix] = false;
}

var path = root + ' ';
visited[root] = true;

function dfs(nodeN, edgeN, root, graph){
    var ix, ixLen, jx, jxLen, current;

    for(ix = 1, ixLen = nodeN; ix <= nodeN; ix++){
        current = graph[root];
        for(jx = 1, jxLen = nodeN; jx <= jxLen; jx++){
            if(current[jx] === 1 && visited[jx] === false){
                visited[jx] = true;
                path += jx + ' ';
                dfs(nodeN, edgeN, jx, graph);
            }
        }
    }

    return;
}

function bfs(nodeN, edgeN, root, graph){
    var ix, ixLen, nodeObj, path;

    nodeObj = {};
    for(ix = 1, ixLen = nodeN; ix <= ixLen; ix++){
        nodeObj[ix] = Infinity;
    }
    nodeObj[root] = 0;

    var queue;
    queue = [root];

    var current, neighborNode = [], path = '';
    while(queue.length > 0){
        current = queue.shift();
        path += current + ' ';

        neighborNode = graph[current];
        for(ix = 1, ixLen = neighborNode.length; ix < ixLen; ix++){
            if(neighborNode[ix] !== 0){
                if(nodeObj[ix] === Infinity){
                    nodeObj[ix] = nodeObj[current] + 1;
                    queue.push(ix);
                }
            }
        }
    }

    console.dir(path.trim());
}

dfs(nodeN, edgeN, root, graph);
console.dir(path.trim());
bfs(nodeN, edgeN, root, graph);