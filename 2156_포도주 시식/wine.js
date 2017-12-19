/*

2017 Dec 19, made by Moon

*/

var fs = require('fs');
var n, c = [];
var input = fs.readFileSync('/dev/stdin').toString().split('\n').map(function(d, i){
	if(i===0){
  	n = parseInt(d);
  }else{
  	c.push(parseInt(d));
  }
});


function main(n, c){
	var cLen, d = [];
  var ix, ixLen;

  c.unshift(0);

  d[0] = 0;
  d[1] = c[1];
  d[2] = d[1] + c[2];

  for(ix = 3, ixLen = n; ix <= ixLen; ix++){
  	if(!d[ix]){
      d[ix] = Math.max(
        d[ix-3] + c[ix-1] + c[ix],
        d[ix-2] + c[ix],
        d[ix-1]
      );
    }
  }

  console.log(d[n]);
};

main(n, c);
