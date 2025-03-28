#include <iostream>
#include <cstring>
#define INF 1234567890
using namespace std;
int W[16][16];
int dp[16][1<<16];
int visited;

int minimum(int a, int b){
    if(a<b) return a;
    return b;
}

int dfs(int cur, int mask, int N){
    if(mask == visited){
        if(W[cur][0] == 0){
            return INF;
        }
        return W[cur][0];
    }
    if(dp[cur][mask] != -1){
        return dp[cur][mask];
    }
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
    cout<<dfs(1, 0, N)<<endl;
}