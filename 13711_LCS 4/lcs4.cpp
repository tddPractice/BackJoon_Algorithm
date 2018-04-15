/*

2018 Mar 8, made by Moon
 
*/
#include<cstdio>
#include<algorithm>
using namespace std;
const int MXN = 1e5;
int idx[MXN + 1], dp[MXN], n, x;
int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; i++) scanf("%d", &x), idx[x] = i;
    for (int i = 0; i < n; i++) {
        scanf("%d", &x);
        dp[i] = n;
        *lower_bound(dp, dp + i, idx[x]) = idx[x];
    }
    printf("%d", lower_bound(dp, dp + n, n) - dp);
    return 0;
}