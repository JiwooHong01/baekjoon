#include <stdio.h>

int dp[201][201];
int main(void){
    int n, k;
    int cnt=0;
    scanf("%d %d", &n, &k);
    for(int j=1;j<=k;j++) dp[0][j] = 1;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=k;j++){
            //dp[i][j] : 0~i까지 숫자 j개로 i만들기
            dp[i][j] = 1;
            for(int l=1;l<=i;l++){
                dp[i][j] = (dp[i][j] + dp[l][j-1]) % 1000000000;
            }
        }
    }
    printf("%d", dp[n][k]);
}