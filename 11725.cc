#include <stdio.h>
#include <iostream>
#include <queue>
using namespace std;

queue<int> arr[100001];
int root[100001];
int checked[100001];

void findroot(int n){
    while(!arr[n].empty()){
        int elem = arr[n].front();
        if(checked[elem] == 0) {
            root[elem] = n;
            checked[elem] = 1;
            findroot(elem);
        }
        arr[n].pop();
    }
}

int main(void){
    int n;
    scanf("%d", &n);
    for(int i=0;i<n-1;i++){
        int a, b;
        scanf("%d %d", &a, &b);
        arr[a].push(b);
        arr[b].push(a);
    }
    checked[1]=1;
    findroot(1);
    for(int i=2;i<=n;i++){
        printf("%d\n", root[i]);
    }
}