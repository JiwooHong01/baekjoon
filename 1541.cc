#include <iostream>
#include <cstring>

using namespace std;

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(0);
    string S;
    cin>>S;
    int ans = 0;
    int flag = 0;
    for(int i=0;i<S.size();){
        if(S[i] == '+'){
            i++;
            continue;
        }
        if(S[i] == '-'){
            i++;
            if(flag == 0){
                flag = 1;
            }
            continue;
        }
        int val = 0;
        while((S[i] != '+') && (S[i] != '-')){
            val = val*10 + (S[i] - '0');
            i++;
            if(i >= S.size()) break;
        }
        if(flag == 0) ans += val;
        else ans -= val;
        // cout<<"ans="<<ans<<",val="<<val<<endl;
    }
    cout<<ans<<endl;
}