/*

2018 Jen 04, made by Moon

*/

var fs = require('fs');
var input = fs.readFileSync('/dev/stdin').toString().split('\n');
var n = parseInt(input[0]);
var c = [];

var ix, ixLen;
for(ix = 1, ixLen = input.length; ix < ixLen; ix++){
	c[ix-1] = new Array();
	c[ix-1].push(parseInt(input[ix].split(' ')[0]), parseInt(input[ix].split(' ')[1]));
}

function main(n, c){
	var ix, ixLen, n1, n2, sum;
	
	
	for(ix = 1, ixLen = n; ix <= ixLen; ix++){
		n1 = reverse(c[ix-1][0]);
		n2 = reverse(c[ix-1][1]);
		
		sum = reverse(n1 + n2);
		console.log(sum);
	}
	
	function reverse(n){
		var ix, ixLen, rStr = '', str = '' + n;
		
		for(ix = str.length - 1, ixLen = 0; ix >= ixLen; ix--){
				rStr += str[ix];
		}
		
		return parseInt(rStr);
	}
}

main(n,c);