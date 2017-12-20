/*

2017 Dec 20, made by Moon

*/

var fs = require('fs');
var input = fs.readFileSync('/dev/stdin').toString().split('\n');
var n = parseInt(input[0]);
var c = input[1].split(' ');

function main(n, c){
	var ix, ixLen, dp = [];
  
    dp[0] = c[0];
    dp.min = c[0];
    dp.max = c[0];
  
    for(ix = 1, ixLen = n; ix < ixLen; ix++){
  	  if(c[ix] > dp.max){
          dp.push(c[ix]);
          dp.max = c[ix];
      }else if(c[ix] < dp.max && c[ix] > dp.min){
    	if(dp.indexOf(c[ix]) === -1){
      	  dp.push(c[ix]);
        }
      }else if(c[ix] < dp.min){
    	  dp.push(c[ix]);
          dp.min = c[ix];
      }else{}
    }
  
    console.log(dp.length);
}

main(n, c);