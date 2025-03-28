#include <stdio.h>
#include <queue>
using namespace std;
priority_queue<int, vector<int>, greater<int> > pq;

int cards[100001];

int main(void){
    int minimum = 0;
    int N;
    scanf("%d", &N);
    for(int i=0;i<N;i++){
        int a;
        scanf("%d", &a);
        pq.push(a);
    }
    while(pq.size()>=2){
        int a = pq.top();
        pq.pop();
        int b = pq.top();
        pq.pop();
        minimum += (a+b);
        pq.push(a+b);
    }
    int a = pq.top();
    pq.pop();
    printf("%d", minimum);
}