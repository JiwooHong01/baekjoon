#include <stdio.h>
#include <vector>
#include <queue>
#define INF 1234567890
using namespace std;

typedef pair<int, int> pii;
priority_queue<pii, vector<pii>, greater<pii> > pq;
vector<pii> vv[20001];
int cost[20001];
int visited[20001];

void init(int N){
    for(int i=1;i<=N;i++){
        cost[i] = INF;
    }
}

void dijk(int start){
    cost[start] = 0;
    pq.push(make_pair(0, start));
    
    while(!pq.empty()){
        pii cur = pq.top();
        pq.pop();
        if(visited[cur.second] == 1) continue;
        visited[cur.second] = 1;
        // if(cur.first > cost[cur.second]) continue;
        for(int i=0;i<vv[cur.second].size();i++){

            pii elem = vv[cur.second][i];
            
            int newcost = elem.first + cost[cur.second];
            // printf("elem.second=%d, newcost = %d\n", elem.second, newcost);
            if(cost[elem.second] > newcost){
                cost[elem.second] = newcost;
                pq.push(make_pair(newcost, elem.second));
            }
        }
    }
}

int main(void){
    int V, E, start;
    // ios::sync_with_stdio(false);
    // cin.tie(0);
    scanf("%d %d %d", &V, &E, &start);
    // cin>>V>>E>>start;
    for(int i=0;i<E;i++){
        int a, b, c;
        scanf("%d %d %d", &a, &b, &c);
        // cin>>a>>b>>c;
        vv[a].push_back(make_pair(c, b));
    }
    init(V);
    // visited[start] = 1;
    dijk(start);
    for(int i=1;i<=V;i++){
        if(i== start) printf("0\n");
        else if(cost[i] == INF) printf("INF\n");
        else printf("%d\n", cost[i]);
    }
}