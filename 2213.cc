#include <stdio.h>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;
vector<int> edge[10001];
int vtx[10001];
int dp[10001][2];
int checked[10001][2];
int check2[10001];//preprocess
queue<int> qq;//preprocess
vector<int> nodes;


int max(int a, int b){
    if(a<b) return b;
    return a;
}

int startDP(int start, int flag){
    checked[start][flag] = 1;
    int len = edge[start].size();
    int res = 0;
    if(flag == 1) res = vtx[start];
    for(int i=0;i<len;i++){
        int elem = edge[start][i];
        int X, Y;
        if(checked[elem][flag]){
            X = dp[elem][0];
            if (flag == 0) Y = dp[elem][1];
        }
        else{
            X = startDP(elem, 0);
            if(flag == 0) Y = startDP(elem, 1);
        }
        if(flag == 0){
            res += max(X, Y);
        }
        else {
            res += X;
        }
    }
    dp[start][flag]=res;
    return res;
}

void preprocess(int start){
    check2[start] = 1;
    
    qq.push(start);
    while(!qq.empty()){
        int cur = qq.front();
        qq.pop();
        int last = edge[cur].size();
        for(int i=0;i<last;){
            if(check2[edge[cur][i]]) edge[cur].erase(edge[cur].begin() + i);
            else {
                qq.push(edge[cur][i]);
                check2[edge[cur][i]] = 1;
                i++;
            }
            
            last = edge[cur].size();
        }
    }
}

void backtrack(int start, int parentsin){
    if(start == 6) 
        start = 6;
    if(!parentsin) {
        if(dp[start][0] < dp[start][1]){
            nodes.push_back(start);
            for(int i=0;i<edge[start].size();i++){
                backtrack(edge[start][i], 1);
            }
        }
        else{
            for(int i=0;i<edge[start].size();i++){
                backtrack(edge[start][i], 0);
            }
        }
    }
    else{
        for(int i=0;i<edge[start].size();i++){
            backtrack(edge[start][i], 0);
        }
    }
}

int main(void){
    int N;
    scanf("%d", &N);
    for(int i=1;i<=N;i++){
        int tmp;
        scanf("%d", &tmp);
        vtx[i]=tmp;
    }
    for(int i=0;i<N-1;i++){
        int a, b;
        scanf("%d %d", &a, &b);
        edge[a].push_back(b);
        edge[b].push_back(a);
    }
    preprocess(1);
    //1, 0: start1, 1포함안함
    //1, 1: start1, 1포함
    int X = startDP(1, 0);
    int Y = startDP(1, 1);
    backtrack(1, 0);
    printf("%d\n", max(X, Y));
    sort(nodes.begin(), nodes.end());
    for(int i=0;i<nodes.size();i++)
        printf("%d ", nodes[i]);
}