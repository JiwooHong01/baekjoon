#include <iostream>

using namespace std;

int arr[31];

void dfs(int N){
    for(int i=4;i<=N;i+=2){
        int start = i-4;
        arr[i] = 3*arr[i-2];
        while(start>=0){
            arr[i] += 2*arr[start];
            start -= 2;
        }
    }

}

int main(void){
    int N;
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>N;
    arr[0] = 1;
    arr[1] = 0;
    arr[2] = 3;
    if(N % 2 == 1){
        cout<<"0"<<endl;
    }
    else{
        dfs(N);
        cout<<arr[N]<<endl;
    }
}