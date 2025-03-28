#include <stdio.h>
int sum[11][11];
int ans[11];
int var;

void init(void){
    for(int i=0;i<=9;i++) sum[1][i] =1; 
    for(int i=2;i<=10;i++){
        for(int j=i-1;j<=9;j++){
            sum[i][j] = sum[i][j-1] + sum[i-1][j-1];
        }
    }
}
void backtrack(int stair, int N){
    if(stair == 0) return;
    for(int i=stair-1;i<=9;i++){
        N -= sum[stair][i];
        if(N <= 0) {
            ans[var] = i;
            var++;
            N += sum[stair][i];
            backtrack(stair-1, N);
            break;
        }
    }
    return;
}
void det(int N){
    for(int i=1;i<=10;i++){
        for(int j=0;j<=9;j++){
            N -= sum[i][j];
            if(N<=0){
                ans[var] = j;
                var++;
                N += sum[i][j];
                backtrack(i-1, N);
                return;
            }
        }
    }
}

int main(void){
    int N;
    scanf("%d", &N);
    init();
    det(N+1);
    if(var ==0) printf("-1");
    else{
        for(int i=0;i<var;i++){
            printf("%d", ans[i]);
        }
    }
}