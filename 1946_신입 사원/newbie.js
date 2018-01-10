/*

2018 Jan 10, mady by Moon

*/
var fs = require('fs');
var input = fs.readFileSync('/dev/stdin').toString().split('\n');
var n = parseInt(input[0]);

var candidatesN = [], scores = [];
var ix, ixLen;

input.shift();
for(ix = 0, ixLen = input.length; ix < ixLen; ix++){
	if(input[ix].length === 2){
		candidatesN.push(parseInt(input[ix]));
	}else{
		scores.push([parseInt(input[ix].split(' ')[0]), parseInt(input[ix].split(' ')[1])]);
	}
}

function main(n, candidatesN, scores){
	var ix, ixLen, jx, jxLen, kx, kxLen;
	var current, count, tail;
	
	var sortedArr = [];
	for(ix = 0, ixLen = n; ix < ixLen; ix++){
		count = candidatesN[ix];
		tail = candidatesN[ix];
		sortedArr = scores.splice(0, tail);
		sortedArr.sort(function(a,b){return b[0] - a[0];});
		
		for(jx = 0, jxLen = sortedArr.length; jx < jxLen; jx++){
			for(kx = jx + 1, kxLen = jxLen; kx < kxLen; kx++){
				if(sortedArr[jx][1] > sortedArr[kx][1]){
					count--;
					break;
				}
			}
		}
		console.log(count);
	}
}

main(n, candidatesN, scores);