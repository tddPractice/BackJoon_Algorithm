/*

2018 Mar 16, made by Moon

*/
#include <cstdio>
#include <vector>
using namespace std;

vector<int> v;
void checkPalin(int a, int b){
	int s, e, isPalin;
	s = a - 1;
	e = b - 1;
	isPalin = 1;
	while(s < e){
		if(v[s] != v[e]){
			isPalin = 0;
			break;
		}
		s++;
		e--;
	}
	printf("%d\n", isPalin);
}

int main(){
    int n, m, k;
    scanf("%d", &n);
    
    for(int i = 0; i < n; i++){
        scanf("%d", &k);
        v.push_back(k);
    }
    
    scanf("%d", &m);
    int a,b;
    for(int i = 0; i < m; i++){
        scanf("%d %d", &a, &b);
		checkPalin(a, b);
    }
    
    return 0;    
}
