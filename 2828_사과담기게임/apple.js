/*

2018 Jen 01, made by Moon

*/

var fs = require('fs');
var input = fs.readFileSync('./txt.txt').toString().split('\n');
var n = parseInt(input[0].toString().split(' ')[0]);
var m = parseInt(input[0].toString().split(' ')[1]);
var j = parseInt(input[1]);
var ix, ixLen, c = [];

for(ix = 2, ixLen = input.length; ix < ixLen; ix++){
  c.push(parseInt(input[ix]));
}

function main(n, m, j, c){
  var ix, ixLen, posL, posR, moveDistance;

  if(m < 1 || m >= n || n > 10) return;

  moveDistance = 0;
  posL = 1, posR = m;
  for(ix = 1, ixLen = n; ix <= ixLen; ix++){
    if(c[ix-1] <= posL){
      moveDistance += (posL - c[ix-1]);
      posL = c[ix-1];
      posR -= moveDistance;
    }else if(c[ix-1] >= posR){
      moveDistance += (c[ix-1] - posR);
      posL += moveDistance;
      posR = c[ix-1];
    }
  }

  console.dir(moveDistance);
}

main(n, m, j, c);
