#include <stdio.h>

int dp[12];

void init(int n){
    for(int i=4;i<=n;i++) dp[i] = 0;
}

void foo(int n){
    for(int i=4;i<=n;i++){
        dp[i] = dp[i-3] + dp[i-2] + dp[i-1];
    }
} 

int main(void){
    int T;
    scanf("%d", &T);
    dp[1] = 1;
    dp[2] = 2;
    dp[3] = 4;
    for(int i=0;i<T;i++){
        int n;
        scanf("%d", &n);
        foo(n);
        printf("%d\n", dp[n]);
        init(n);
    }
}