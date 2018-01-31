/*

2018 Jan 31, made by Moon

*/
var fs = require('fs');
var input = fs.readFileSync('./txt.txt').toString().split('\n');

var N = parseInt(input[0].split(' ')[0]);
var root = parseInt(input[1]);
var graph = { length: 0 };
var dist = [];
var visited = [];
var isEmpty = true;

input.splice(0,2);

function initGraph(){
    var ix, ixLen;

    for (ix = 0, ixLen = N; ix <= ixLen; ix++) {
        dist[ix] = Infinity;
        visited[ix] = false;
        graph[ix] = {};
    }

    input.map(function(data){
        var d = data.trim().split(' ');
        var u = parseInt(d[0]);
        var v = parseInt(d[1]);
        var w = parseInt(d[2]);
        if(!graph[u]){
            graph[u] = {};
        }
        graph[u][v] = w;
    });
}

function findNeighbor(){
    var ix, ixLen, minDist = Infinity, minNode = -1;

    for (ix = 0, ixLen = N; ix <= ixLen; ix++) {
        if(!visited[ix] && dist[ix] <= minDist){
            minDist = dist[ix];
            minNode = ix;
        }
    }
    return minNode;
}

function dijkstra(){
    var v, ixLen, jx, jxLen, u, queue = [];

    dist[root] = 0;
    queue.push(root);
    // for(jx = 1, jxLen = N; jx <= jxLen; jx++){
    //     u = findNeighbors();
    //     visited[u] = true;
    //     for(v = 1, ixLen = N; v <= ixLen; v++){
    //         if(graph[v]){
    //             if(!visited[v] && dist[u] !== Infinity && dist[u] + graph[u][v] < dist[v]){
    //                 dist[v] = dist[u] + graph[u][v];
    //             }
    //         }
    //     }
    // }

    while(queue.length){
        u = findNeighbor();
        visited[u] = true;
        queue.shift();
        for(v = 1, ixLen = N; v <= ixLen; v++){
            if(graph[v]){
                if(!visited[v] && dist[u] !== Infinity && dist[u] + graph[u][v] < dist[v]){
                    dist[v] = dist[u] + graph[u][v];
                    queue.push(v);
                }
            }
        }
    }
}

function printPath(){
    var ix, ixLen;

    for (ix = 1, ixLen = dist.length; ix < ixLen; ix++) {
        if(dist[ix] === Infinity){
            dist[ix] = 'INF';
        }
        console.log("%s", dist[ix]);
    }
}

initGraph();
dijkstra();
printPath();