#include <iostream>
#include <cstring>
#include <stack>
using namespace std;
stack<char> st;

int main(void){
    int T;
    cin>>T;
    for(int i=0;i<T;i++){
        string SS;
        cin>>SS;
        int flag = 0;
        for(int j=0;j<SS.size();j++){
            if(SS[j] == '(')
                st.push(SS[j]);
            else{
                if(st.empty()){
                    cout<<"NO"<<endl;
                    flag = 1;
                    break;
                }
                st.pop();
            }
        }
        if(flag == 0) {
            if(st.empty()) cout<<"YES"<<endl; 
            else cout<<"NO"<<endl;
        }
        while(!st.empty()){
            st.pop();
        }
    }
}