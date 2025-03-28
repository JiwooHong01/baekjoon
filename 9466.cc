#include <stdio.h>
int arr[100001];
int checked[100001];

void init(int n){
    for(int i=1;i<=n;i++) checked[i]=0;
}

int dfs(int start, int cur){
    int elem = arr[cur];
    if((checked[cur] !=0) &&(checked[cur] != start) ) return 0;
    checked[cur] = start;
    // if(elem==cur) return 1;
    if(checked[elem] == start) {
        int len = 1;
        while(elem != cur){
            len++;
            elem = arr[elem];
        }
        return len;
    }
    if((checked[elem] !=0) && (checked[elem] != start)) return 0;
    return dfs(start, elem);
}

int main(void){
    int T;
    scanf("%d", &T);
    for(int i=0;i<T;i++){
        int n;
        scanf("%d", &n);
        int cnt = 0;
        for(int j=1;j<=n;j++){
            int a;
            scanf("%d", &a);
            arr[j]=a;
        }
        for(int j=1;j<=n;j++){
            cnt += dfs(j, j);
        }
        init(n);
        printf("%d\n",n- cnt);
    }
}