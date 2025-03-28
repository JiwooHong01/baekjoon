#include <stdio.h>
//my solution -> DP
#define INF 1234567890

int w[100001];
int v[100001];
int dp[101][100001];

int max(int a, int b){
    if(a<b) return b;
    return a;
}

int foo(int i, int j){
    if(j<0) return -INF;
    if(i<0) return 0;
    
    return dp[i][j];
}

int main(void){
    int N, K;
    scanf("%d %d", &N, &K);
    for(int i=0;i<N;i++)
        scanf("%d %d", &w[i], &v[i]);
    for(int i=0;i<N;i++){
        for(int j=0;j<=K;j++){
            dp[i][j] = max(foo(i-1, j), foo(i-1, j-w[i])+ v[i]);
        }
    }
    printf("%d", dp[N-1][K]);
}