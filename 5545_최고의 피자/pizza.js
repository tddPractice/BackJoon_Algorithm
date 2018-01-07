/*

2018 Jen 07, made by Moon

*/

var fs = require('fs');
var input = fs.readFileSync('/dev/stdin').toString().split('\n');
var n = parseInt(input[0]);
var price = [];
price[0] = parseInt(input[1].split(' ')[0]);
price[1] = parseInt(input[1].split(' ')[1]);

var ix, ixLen, kcal = [];

for(ix = 2, ixLen = input.length; ix < ixLen; ix++){
  kcal.push(parseInt(input[ix]));
}

function main(n, price, kcal){
  var ix, ixLen, currentKcal, currentPrice, kcalPerDallor;
  currentKcal = kcal[0];
  currentPrice = price[0];
  kcalPerDallor = currentKcal / currentPrice;

  kcal.unshift();
  kcal.sort(function(a,b){return b-a;});

  for(ix = 0, ixLen = n; ix < ixLen; ix++){
    if(kcalPerDallor < (currentKcal + kcal[ix]) / (currentPrice + price[1])){
      currentKcal += kcal[ix];
      currentPrice += price[1];
      kcalPerDallor = currentKcal / currentPrice;
    }
  }

  console.log(Math.floor(kcalPerDallor));
}

main(n, price, kcal);
