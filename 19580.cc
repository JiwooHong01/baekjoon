#include <stdio.h>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

struct Citizen {
    long long int min_price;
    long long int max_price;
};

struct Store {
    long long int price;
    int quantity;
};

bool cmpCitizen(Citizen a, Citizen b) {
    return a.min_price < b.min_price;
}
struct cmp{
    bool operator()(Citizen a, Citizen b) {
        return a.max_price > b.max_price;
    }
};

bool cmpStore(Store a, Store b) {
    return a.price < b.price;
}

vector<Citizen> citizens;
vector<Store> stores;

int main() {
    int N, M;
    scanf("%d %d", &N, &M);

    

    for (int i = 0; i < N; i++) {
        long long int a, b;
        scanf("%lld %lld", &a, &b);
        Citizen tmp = {a, b};
        citizens.push_back(tmp);
    }

    for (int i = 0; i < M; i++) {
        long long int a;
        int b;
        scanf("%lld %d", &a, &b);
        Store tmp = {a, b};
        stores.push_back(tmp);
    }

    sort(citizens.begin(), citizens.end(), cmpCitizen);
    sort(stores.begin(), stores.end(), cmpStore);

    int cnt = 0;
    int start = 0;
    priority_queue<Citizen, vector<Citizen>, cmp> pq;
    for(int i=0;i<M;i++){
        while((start < N) && (citizens[start].min_price <= stores[i].price)){
            if(citizens[start].max_price >= stores[i].price){
                pq.push(citizens[start]);
            }
            start++;
        }
        while((stores[i].quantity >0) && (!pq.empty())){
            Citizen tmp = pq.top();
            pq.pop();
            if((tmp.min_price <= stores[i].price) && (stores[i].price <= tmp.max_price)){
                stores[i].quantity--;
                cnt++;
            }
        }
    }

    printf("%d", cnt);

    return 0;
}