/*

2018 Jen 01, made by Moon

*/

var fs = require('fs');
var input = fs.readFileSync('/dev/stdin').toString().split('\n');
var n = parseInt(input[0]);
var arr = input[1].toString().split(' ');
var ix, ixLen, c = [];

for(ix = 0, ixLen = n; ix < ixLen; ix++){
	c.push(parseInt(arr[ix]));
}

function main(n, c){
	var ix, ixLen, d;
	var totalTime = 0, currentTime = 0;
	
	d = c.slice();
	d.sort();
	
	
	for(ix = 0, ixLen = n; ix < ixLen; ix++){
		currentTime += d[ix];
		totalTime += currentTime;
	}
	
	console.log(totalTime);
}

main(n, c);