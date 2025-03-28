#include <stdio.h>
int dp[1001];
int checked[1001];
int foo(int n){
    int X, Y;
    if(n==1) return 1;
    if(n==2) return 3;
    if(checked[n-1] ==0){
        X = foo(n-1);
        checked[n-1]=1;
    }
    else X = dp[n-1];
    if(checked[n-2] ==0){
        checked[n-2]=1;
        Y = foo(n-2);
    }
    else Y = dp[n-2];
    Y = (Y*2)%10007;
    checked[n]=1;
    dp[n] = (X+Y)%10007;
    return dp[n];
}

int main(void){
    int n;
    scanf("%d", &n);
    dp[1] =1;
    dp[2] = 3;
    checked[1]=1;
    checked[2]=1;
    checked[0] = 1;
    foo(n);
    int res = dp[n] % 10007;
    printf("%d", res);
}