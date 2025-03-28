#include <iostream>
#include <cstring>
#include <vector>
#include <stack>
using namespace std;
vector<char> vv;
stack<char> st;
int main(void){
    ios::sync_with_stdio(false);
    cin.tie(0);
    string arr, explode;
    cin>>arr;
    cin>>explode;
    int flag = explode.size() -1;
    
    for(int i=0;i<arr.size();i++){
        vv.push_back(arr[i]);
        while(vv.back() == explode[flag]){
            st.push(vv.back());
            vv.pop_back();
            flag--;
            if(flag < 0) {
                break;
            }
            if(vv.empty()) break;
        }
        if(flag>=0){
            while(!st.empty()){
                vv.push_back(st.top());
                st.pop();
            }
        }
        else{
            while(!st.empty()){
                st.pop();
            }
        }
        flag = explode.size() -1;
    }
    if(vv.empty()) cout<<"FRULA"<<endl;
    for(int i=0;i<vv.size();i++)
        cout<<vv[i];
    
}