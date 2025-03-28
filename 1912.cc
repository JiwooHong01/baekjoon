#include <stdio.h>
#define INF 1234567890
int arr[100001];
//dp[i][1]:i포함
int dp[100001][2];
int start;
int max(int a, int b){
    if(a>b) return a;
    else return b;
}
void foo(int n){
    for(int i=1;i<n;i++){
        dp[i][0] = max(dp[i-1][0], dp[i-1][1]);
        dp[i][1] = max(0, dp[i-1][1]) + arr[i]; 
    }
}
int main(void){
    int n;
    scanf("%d", &n);
    int a;
    scanf("%d", &a);
    arr[0] = a;
    dp[0][0] = -INF;
    dp[0][1] = a;
    for(int i=1;i<n;i++){
        int a;
        scanf("%d", &a);
        arr[i]=a;
    }
    foo(n);
    printf("%d", max(dp[n-1][0], dp[n-1][1]));
}