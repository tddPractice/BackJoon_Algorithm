/*

2018 Jen 01, made by Moon

*/

var fs = require('fs');
var input = fs.readFileSync('/dev/stdin').toString().split('\n');
var n = parseInt(input[0]);

function main(n){
  if(n < 1 || n >= 1000){
    return;
  }

  var coins, change, count = 0;

  coins= [500, 100, 50, 10, 5, 1];
  change = 1000 - n;

  var ix, ixLen;
  for(ix = 0, ixLen = coins.length; change > 0; ix++){
    if(change >= coins[ix]){
      change -= coins[ix];
      count++;
      ix = -1;
    }
  }

  console.log(count);
}

main(n);