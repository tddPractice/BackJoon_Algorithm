/*

2017 Dec 20, made by Moon

*/

var fs = require('fs');
var input = fs.readFileSync('./test.txt').toString();

var arr_size = input.split('\n')[0].split(' ').map(function(d){return +d});
var ix, ixLen, c = [];
var c_r;

for(ix = 0, ixLen = arr_size[0]; ix < ixLen; ix++){
	c[ix] = new Array();
	c_r = input.split('\n')[ix+1].split(' ');
	for(jx = 0, jxLen = arr_size[1]; jx < jxLen; jx++){
		c[ix][jx] = +c_r[jx];
	}
}

var sum_size = input.split('\n')[++ix];
var test_case = [];

for(jx = 0, jxLen = sum_size; jx < jxLen; ix++, jx++){
	test_case.push(input.split('\n')[ix+1].split(' ').map(function(d){return +d}));
}

function main(arr_size, c, sum_size, test_case){
	var ix, ixLen, dp;
	
	for(ix = 0, ixLen = sum_size; ix < ixLen; ix++){
		dp = 0;
		dp = sum(c, dp, test_case[ix]);
		console.log(dp);
	}
}

function sum(c, dp, test_case){
	var ix, ixLen, jx, jxLen;
	
	for(ix = test_case[0], ixLen = test_case[2]; ix <= ixLen; ix++){
		for(jx = test_case[1], jxLen = test_case[3]; jx <= jxLen; jx++){
			dp += c[ix-1][jx-1];
		}
	}
	return dp;
}

main(arr_size, c, sum_size, test_case);