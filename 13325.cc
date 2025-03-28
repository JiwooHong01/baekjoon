#include <stdio.h>
#include <vector>
using namespace std;
vector<int> edges[20];

void dfs(int root){
    int len = edges[root].size();
    for(int i=0;i<len;i++){
        
    }
}

int main(void){
    int k;
    scanf("%d", &k);
    edges[0].push_back(0);
    for(int i=1;i<=k;i++){
        for(int j=0;j<2*i;j++){
            int a;
            scanf("%d", &a);
            edges[i].push_back(a);
        }
    }
    dfs(1);
}