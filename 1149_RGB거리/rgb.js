/*

2017 Dec 16, made by Moon

*/

function main(c){
	var val, d = [];
  var ix, ixLen;
  d[0] = 0;

  for(ix = 1, ixLen = c.length; ix < ixLen; ix++){
  	d[ix] = new Array();
    if(ix === 1){
    	d[ix][0] = c[ix][0];
      d[ix][1] = c[ix][1];
      d[ix][2] = c[ix][2];
    }else{
    	d[ix][0] = Math.min(d[ix-1][1], d[ix-1][2]) + c[ix][0];
      d[ix][1] = Math.min(d[ix-1][0], d[ix-1][2]) + c[ix][1];
      d[ix][2] = Math.min(d[ix-1][0], d[ix-1][1]) + c[ix][2];
    }
  }

  console.log(Math.max(d[ix-1][0], d[ix-1][1], d[ix-1][2]));
}

main([
	[26, 40, 83],
  [49, 60, 57],
  [13, 89, 99]
])
