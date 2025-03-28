#include <stdio.h>
#define INF 1234567890

int dp[101][10001];

int min(int a, int b){
    if(a<b) return a;
    else return b;
}

int foo(int i, int j){
    if(i<0) return INF;
    if(j<0) return INF;
    return dp[i][j];
}

int main(void){
    int n, k;
    scanf("%d %d", &n, &k);
    for(int i=0;i<n;i++){
        int a;
        scanf("%d", &a);
        for(int j=1;j<=k;j++){
            dp[i][j] = min(foo(i-1, j), foo(i, j-a) + 1);
        }
    }
    if(dp[n-1][k] <100001)
        printf("%d", dp[n-1][k]);
    else printf("-1");
}