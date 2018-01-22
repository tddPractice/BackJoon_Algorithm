/*

2018 Jan 22, made by Moon

*/
var fs = require('fs');
var input = fs.readFileSync('/dev/stdin').toString().split('\n');
var N = parseInt(input[0].split(' ')[0]);
var M = parseInt(input[0].split(' ')[1]);
input.shift();
var compareHeightInfo = input.map(function(data){
    return data.split(' ').map(function(d){return parseInt(d)});
});

// Line up nodes by a certain order.
// In this case, the order is ASC of in-degree values.
var graph = {};
function lineUpStudents(){
    var ix, ixLen, zDegreeStack = [], path = '';

    // Fill zDegreeStack, which means Zero Degree Stack, with the nodes of 0 in-degree
    findEdgeInZero(zDegreeStack);
    if(zDegreeStack.length === 0){
        return;
    }

    // Loop over zDegreeStack until it has no elements in it,
    // decreasing children's outDegree value by 1, that are from curNode, which's current node.
    var curNode, childNodeNum;
    while(zDegreeStack.length){
        curNode = zDegreeStack.pop();
        curNode.visited = true;
        path += curNode.node + ' ';
        for (ix = 0, ixLen = curNode.outDegree.length; ix < ixLen; ix++) {
            childNodeNum = curNode.outDegree[ix];
            graph[childNodeNum].inDegree--;
        }
        if(!zDegreeStack.length){
            findEdgeInZero(zDegreeStack);
        }
    }
    console.dir(path.trim());
}

// Find all nodes of 0 in-degree which hasn't been visited yet
function findEdgeInZero(zDegreeStack){
    var ix, ixLen;
    for (ix = 1, ixLen = N; ix <= ixLen; ix++) {
        if(graph[ix].inDegree === 0 && graph[ix].visited === false){
            zDegreeStack.push(graph[ix]);
        }
    }
}

function initGraph(){
    var ix, ixLen, tallerStudent, smallerStudent;
    for (ix = 1, ixLen = N; ix <= ixLen; ix++) {
        graph[ix] = {
            node      : ix,
            inDegree  : 0,
            outDegree : [],
            visited   : false
        }
    }
    for (ix = 0, ixLen = M; ix < ixLen; ix++) {
        tallerStudent  = compareHeightInfo[ix][0];
        smallerStudent = compareHeightInfo[ix][1];
        graph[tallerStudent].outDegree.push(smallerStudent);
        graph[smallerStudent].inDegree++;
    }
}

initGraph();
lineUpStudents();

