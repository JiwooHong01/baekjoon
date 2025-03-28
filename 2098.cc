#include <iostream>
#include <cstring>
#define INF 1234567890
using namespace std;
// From https://velog.io/@min_gi1123/c-%EB%B0%B1%EC%A4%80-2098-%EC%99%B8%ED%8C%90%EC%9B%90-%EC%88%9C%ED%9A%8C-Traveling-Salesman-problem-TSP-%EB%B9%84%ED%8A%B8%EB%A7%88%EC%8A%A4%ED%82%B9-bitmasking
int W[16][16];
int dp[16][1<<16];
int visited;

int minimum(int a, int b){
    if(a<b) return a;
    return b;
}
int dfs(int cur, int mask, int N){
    if(visited == mask){
        if(W[cur][0] == 0){
            return INF;
        }
        else return W[cur][0];
    }
    if(dp[cur][mask] != -1)
        return dp[cur][mask];
    dp[cur][mask] = INF;
    for(int i=0;i<N;i++){
        if(W[cur][i] == 0) continue;
        if((mask & (1<<i)) == (1<<i)) continue;
        dp[cur][mask] = minimum(dp[cur][mask], W[cur][i] + dfs(i, mask | (1<<i), N));
    }
    return dp[cur][mask];
}

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int N;
    cin>>N;
    visited = (1<<N) -1;
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            int a;
            cin>>a;
            W[i][j] = a;
        }
    }
    memset(dp, -1, sizeof(dp));
    int ans = dfs(0, 1, N);
    cout<<ans<<endl;
}