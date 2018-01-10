var fs = require('fs');
var input = fs.readFileSync('./txt.txt').toString().split('\n');
var n = parseInt(input[0]);

function main(n){
	var ix, ixLen, dp;
	var _3x, _2x, _one, min, next;
	
	dp = {}, path = [n];
	
	/*
		입력 n에서부터 x3 , x2, +1의 3가지 경우의 수를 비교해 가장 최소값으로 값을 계속 저장해 나감 / 메모이제이션 사용
	*/
	for(ix = n, ixLen = 1; ix >= ixLen; ix--){
		if(ix === n){ dp[ix] = {min : 0, next: undefined} }
		if(ix === n - 1){ dp[ix] = { min: 1, next: n}; }
		else{
			if(!dp[ix]){
				_3x = ix * 3, _2x = ix * 2, _one = ix + 1;
				if(_3x < n){ 
					min  = Math.min(dp[_3x].min, dp[_2x].min, dp[_one].min) + 1; 
					next = (min === dp[_3x].min + 1) ? _3x : ((min === dp[_2x].min + 1) ? _2x : _one);
				}else if(_2x < n){ 
					min  = Math.min(dp[_2x].min, dp[_one].min) + 1; 
					next = (min === dp[_2x].min + 1) ? _2x : _one;
				}else if(_3x === n || _2x === n){
					min  = 1;
					next = n;
				}else{ 
					min  = dp[_one].min + 1;
					next = _one;
				}
				
				dp[ix] = { min: min, next: next };
			}
		}
	}
	console.log(dp[1].min);
	
	/*
		0에서부터 다시 N까지 올라가면서, 저장된 next 포인터를 따라서 경로를 추적함
	*/
	var prev, next, path = [], range = Object.keys(dp);
	for(ix = 0, ixLen = range.length; ix <= ixLen; ix++){
		if(ix === 0){
			path.push(range[ix]);
			next = dp[range[ix]].next;
		}else{
			if(dp[next].next){
				path.push(next);
				next = dp[next].next;
			}
		}
	}
	path.push(n);
	
	path = path.reverse();
	path = path.join(' ');
	
	console.dir(path);
}

main(n);