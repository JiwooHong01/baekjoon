#include <stdio.h>
#include <vector>
#define INF 1234567890

using namespace std;
vector<int> sns[1000001];
int checked[1000001][2];
int mine[1000001];
int dp[1000001][2];

int min(int a, int b){
    if(a<b) return a;
    return b;
}

void preprocess(int root){
    int last = sns[root].size();
    for(int i=0;i<last;){
        int elem = sns[root][i];
        if(mine[elem] == 1){
            sns[root].erase(sns[root].begin()+i);
        }
        else{
            mine[elem]=1;
            preprocess(elem);
            i++;
        }
        last = sns[root].size();
    }
}

int startDP(int root, int flag){
    int res = 0;
    for(int i=0;i<sns[root].size();i++){
        int elem = sns[root][i];
        
        int X;
        if(checked[elem][1] == 0){
            checked[elem][1] = 1;
            X = startDP(elem, 1)+1;
        }
        else X = dp[elem][1] + 1;
        
        if(flag== 1){
            int Y;
            if(checked[elem][0] ==0){
                checked[elem][0] = 1;
                Y = startDP(elem, 0);
            }
            else Y = dp[elem][0];
            res += min(X, Y);
        }
        else
            res += X;
        
    }
    dp[root][flag] = res;
    return res;
}

int main(void){
    int n;
    scanf("%d", &n);
    for (int i = 1; i < n; i++){
        int a, b;
        scanf("%d %d", &a, &b);
        sns[a].push_back(b);
        sns[b].push_back(a);
    }
    //start = 1
    mine[1]=1;
    preprocess(1);
    checked[1][0] = 1;
    checked[1][1] = 1;
    dp[1][0] = 0;
    dp[1][1] = 1;
    int X = startDP(1, 0);
    int Y = startDP(1, 1)+1;
    int ans = min(X, Y);
    printf("%d", ans);
}