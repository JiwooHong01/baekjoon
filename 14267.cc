#include <stdio.h>
#include <vector>
using namespace std;
vector<int> junior[100001];
int praise[100001];

void process(int root){
    for(int i=0;i<junior[root].size();i++){
        int elem = junior[root][i];
        praise[elem] += praise[root];
        process(elem);
    }
}

int main(void){
    int n, m;
    scanf("%d %d", &n, &m);
    for(int i=1;i<=n;i++){
        int a;
        scanf("%d", &a);
        if(a>0) junior[a].push_back(i);
    }
    for(int i=0;i<m;i++){
        int a, b;
        scanf("%d %d", &a, &b);
        praise[a] += b;
    }
    process(1);
    for(int i=1;i<=n;i++){
        printf("%d ", praise[i]);
    }
}