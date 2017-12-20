/*

2017 Dec 20, made by Moon

*/

var fs = require('fs');
var input = fs.readFileSync('./test.txt').toString();
var n = input.split('\n')[0];
var c = input.split('\n').map(function(d, i){ 
	if(i > 0){
		return +d;
	}
});

c.shift();

function main(n, c){
	var ix, ixLen, d = [];
	
	d[0] = c[0];
	d[1] = d[0] + c[1];
	d[2] = Math.max(c[0] + c[1], c[0] + c[2], c[1] + c[2]);
	
	console.log(d[0], d[1], d[2]);
	
	for(ix = 3, ixLen = n; ix < ixLen; ix++){
		d[ix] = Math.max(d[ix-3] + c[ix-1] + c[ix], d[ix-2] + c[ix]);
		console.log(d[ix]);
	}
	
	console.log(d[d.length - 1]);
}

main(n, c);