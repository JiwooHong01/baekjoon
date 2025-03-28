#include <stdio.h>

using namespace std;
int coin[100];
int dp[2][10001];

int main(void){
    int n, k;
    scanf("%d %d", &n, &k);
    for(int i=0;i<n;i++){
        scanf("%d", &coin[i]);
    }
    for(int j=0; j<=k;j++){
        if(j%coin[0] == 0) dp[0][j] = 1;
    }
    int start = 1;
    for(int i=1;i<n;i++){
        for(int j=0; j<=k;j++){
            dp[start][j] = 0;
            for(int l=j ; l>=0; l -= coin[i]){
                dp[start][j] += dp[1-start][l];
            }
        }
        start = 1-start;
    }
    printf("%d", dp[1-start][k]);
}