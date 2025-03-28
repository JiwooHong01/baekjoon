#include <iostream>
#include <vector>
#include <queue>
#define INF 1234567890
using namespace std;
typedef pair<int, int> pii;

vector<pii> vv[1001];
// int checked[1001];
priority_queue<pii, vector<pii>, greater<pii> > pq;
// int checked[1001];
int cost[1001];

void init(int N){
    for(int i=1;i<=N;i++){
        cost[i] = INF;
    }
}

int main(void){
    int N, M;
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>N>>M;
    init(N);
    for(int i=0;i<M;i++){
        int a, b, c;
        cin>>a>>b>>c;
        vv[a].push_back(make_pair(c, b));
    }
    int arr, dst;
    cin>>arr>>dst;
    pq.push(make_pair(0, arr));
    cost[arr] = 0;
    while(!pq.empty()){
        pii cur = pq.top();
        pq.pop();
        if(cur.first > cost[cur.second]) continue;
        for(int i=0;i<vv[cur.second].size();i++){
            pii elem = vv[cur.second][i];
            int newcost =  cost[cur.second] + elem.first;
            if(cost[elem.second] > newcost){
                pq.push(make_pair(newcost, elem.second));
                cost[elem.second] = newcost;
            }
        }
    }
    cout<<cost[dst];
}