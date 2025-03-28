#include <stdio.h>
#include <algorithm>
#include <vector>
using namespace std;

vector<int> arr[100001];
int num_child[100001];
int des[100001];
int cnt;

void process(int root, int N){
    if(cnt == N) return;
    num_child[root] = arr[root].size();
    cnt++;
    for(int i=0;i<arr[root].size();i++){
        int value = arr[root][i];
        auto it = find(arr[value].begin(), arr[value].end(), root);
        arr[value].erase(it);
        process(value, N);
    }
}
int postprocess(int root){
    int val = num_child[root];
    for(int i=0;i<num_child[root];i++){
        val += postprocess(arr[root][i]);
    }
    des[root] = val;
    return val;
}

int main(void){
    int N, root, Q;
    scanf("%d %d %d", &N, &root, &Q);
    for(int i=0;i<N-1;i++){
        int a, b;
        scanf("%d %d", &a, &b);
        arr[a].push_back(b);
        arr[b].push_back(a);
    }
    process(root, N);
    cnt=0;
    des[root] = postprocess(root);

    for(int i=0;i<Q;i++){
        int a;
        scanf("%d", &a);
        printf("%d\n", 1+des[a]);
    }
}