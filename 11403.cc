#include <iostream>
using namespace std;

int W[101][101];

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int N;
    cin>>N;
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            int a;
            cin>>a;
            W[i][j] = a;

        }
    }
    int changed = 0;
    while(changed != 2){
        for(int i=0;i<N;i++){
            for(int j=0;j<N;j++){
                if(W[i][j] == 1) continue;
                for(int k=0;k<N;k++){
                    if((W[i][k] == 1) &&(W[k][j] ==1)){
                        W[i][j] = 1;
                        changed = 1;
                        break;
                    }
                }
            }
        }
        if(changed != 1) changed = 2;
        if(changed == 1) changed = 0;
    }
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            cout<<W[i][j]<<" ";

        }
        cout<<endl;
    }
}