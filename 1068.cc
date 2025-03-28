#include <stdio.h>
#include <algorithm>
#include <vector>
using namespace std;
vector<int> children[51];
int parent[51];
int res;

void process(int node){
    while(children[node].size() != 0){
        int elem = children[node].front();
        children[node].erase(children[node].begin());
        process(elem);
    }
}

void count(int start, int node){
    while(children[start].size() != 0){
        int elem = children[start].front();
        children[start].erase(children[start].begin());
        if(children[elem].empty()) res++;
        else count(elem, node);
    }
}

int main(void){
    int n;
    scanf("%d", &n);
    for(int i=0;i<n;i++){
        int a;
        scanf("%d", &a);
        children[a+1].push_back(i+1);
        parent[i+1] = a+1;
    }
    int node;
    scanf("%d", &node);
    node++;
    int par = parent[node];
    auto it = find(children[par].begin(), children[par].end(), node);
    children[par].erase(it);
    process(node);
    count(0, node);
    printf("%d", res);
}