/*

2018 Jan 14, made by Moon

*/
var fs = require('fs');
var input = fs.readFileSync('/dev/stdin').toString().split('\n');
var n = parseInt(input[0]);

input.shift();
var customers = input.map(function(data){return parseInt(data);});

function main(n, customers){
    var ix, ixLen, tip = 0;

    customers.sort(function(a,b){return b-a;});
    for(ix = 0, ixLen = n; ix < ixLen; ix++){
        if(customers[ix] > ix){
            tip += customers[ix] - ix;
        }
    }

    console.log(tip);
}

main(n, customers);