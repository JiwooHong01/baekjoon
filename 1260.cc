#include <stdio.h>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

vector<int> edges[1001];
queue<int> bfsq;
int check[1001][2];//0: dfs, 1: bfs

void dfs(int v){
    sort(edges[v].begin(), edges[v].end());
    for(int i=0;i<edges[v].size();i++){
        int elem = edges[v][i];
        if(check[elem][0] == 0){
            printf("%d ", elem);
            check[elem][0] = 1;
            dfs(elem);
        }
    }
}

void bfs(int v){
    bfsq.push(v);
    while(!bfsq.empty()){
        int start = bfsq.front();
        bfsq.pop();
        printf("%d ", start);
        sort(edges[start].begin(), edges[start].end());
        for(int i=0;i<edges[start].size();i++){
            if(check[edges[start][i]][1] == 0){
                check[edges[start][i]][1] = 1;
                bfsq.push(edges[start][i]);
            }
        }
    }
}


int main(void){
    int n, m, v;
    scanf("%d %d %d", &n, &m, &v);
    for(int i=0;i<m;i++){
        int a, b;
        scanf("%d %d", &a, &b);
        edges[a].push_back(b);
        edges[b].push_back(a);
    }
    
    check[v][0]=1;
    check[v][1]=1;
    printf("%d ", v);
    dfs(v);
    printf("\n");
    bfs(v);
}