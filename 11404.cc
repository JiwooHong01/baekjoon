#include <iostream>
#define INF 10000001

using namespace std;

int map[101][101];

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, m;
    cin>>n>>m;
    for(int i=0;i<m;i++){
        int start, end, cost;
        cin>>start>>end>>cost;
        if(map[start][end] != 0){
            if(map[start][end] > cost)
                map[start][end] = cost;
        }
        else map[start][end] = cost;
    }
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
            if(map[i][j] ==0)
                if(i!=j) map[i][j] = INF;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            for(int k=1;k<=n;k++){
                if(map[j][k] > map[j][i] + map[i][k]){
                    map[j][k] = map[j][i] + map[i][k];
                }
            }
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(i==j) cout<<"0 ";
            else if(map[i][j] == INF) cout<<"0 ";
            else cout<<map[i][j]<<" ";
        }
        cout<<endl;
    }
}