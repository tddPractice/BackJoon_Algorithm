/*

2018 Jan 14, made by Moon

*/
var fs = require('fs');
var input = fs.readFileSync('/dev/stdin').toString().split('\n');
var n = parseInt(input[0]);
var sizeOfSoon = [], soonArr = [];

input.map(function(data, index){
    if(index !== 0){
        if(index % 2 === 1){
            sizeOfSoon.push(parseInt(data));
        }else{
            soonArr.push(
                data.split(' ').map(function(v){return parseInt(v)})
            )
        }
    }
});

function circle(size, graph){
    var ix, ixLen, visited = [];

    for(ix = 0, ixLen = size; ix <= ixLen; ix++){
        visited[ix] = false;
    }

    var current, bool = false, queue = [], numberOfCircle = 0;
    for(ix = 1, ixLen = size; ix < ixLen; ix++){
        queue.push(ix);
        while(queue.length !== 0){
            current = queue.shift();
            if(graph[current] && !visited[current]){
                visited[current] = true;
                queue.push(graph[current]);
                bool = true;
            }
        }
        if(bool){numberOfCircle++;}
        bool = false;
    }

    console.log(numberOfCircle);
}

function main(n, sizeOfSoon, soonArr){
    var ix, ixLen, graph;

    for(ix = 0, ixLen = n; ix < ixLen; ix++){
        graph = makeGraph(sizeOfSoon[ix], soonArr[ix]);
        circle(sizeOfSoon[ix], graph);
    }

    function makeGraph(sizeOfSoon, soonArr){
        var ix, ixLen, orderedArr = [], graph = {};

        for(ix = 0, ixLen = soonArr.length; ix < ixLen; ix++){
            orderedArr[ix] = ix + 1;
        }

        for(ix = 0; ix < sizeOfSoon; ix++){
            if(!graph[orderedArr[ix]]){
                graph[orderedArr[ix]] = soonArr[ix];
            }
        }

        return graph;
    }
}

main(n, sizeOfSoon, soonArr);