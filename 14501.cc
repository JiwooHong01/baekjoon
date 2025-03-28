#include <stdio.h>
#include <queue>
#define INF 1234567890
using namespace std;
int t[16];
int p[16];
int maximum;

int dfs(int start, int N){
    if(start>=N) return 0;
    int ti=t[start];
    int pi=p[start];
    
    int flag=0;
    if(start+ti>N) flag=1;
    int tmp1=0;
    int tmp2=0;
    if(flag == 1){
        tmp2 = dfs(start+1, N);
    }
    else{
        tmp1 = pi + dfs(start + ti, N);
        tmp2 = dfs(start+1, N);
    }
    if(tmp1>tmp2) return tmp1;
    else return tmp2;
}

int main(void){
    int N;
    int sum = 0;
    scanf("%d", &N);
    for(int i=0;i<N;i++){
        scanf("%d %d", &t[i], &p[i]);
    }
    int maxi = dfs(0, N);
    printf("%d", maxi);
    
}