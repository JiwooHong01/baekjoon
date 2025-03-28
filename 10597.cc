#include <string.h>
#include <vector>
#include <iostream>
using namespace std;
int checked[100];
vector<int> arr;
int numcur=0;
bool dfs(string sent, int start, int sentlen, int nums){
    int elem = (sent[start]) - '0';    
    if(elem == 0) 
        return false;
    if((start) ==sentlen){
        if(nums == numcur) 
            return true;
        else return false;
    }
    if(checked[elem] == 0){
        checked[elem] = 1;
        numcur++;
        arr.push_back(elem);
        if(arr[5]==5)
            arr[5]=5;
        bool flag = dfs(sent, start+1, sentlen, nums);
        if(flag) return true;
        checked[elem] = 0;
        numcur--;
        arr.pop_back();
    }
    if(start + 1 == sentlen) return false;
    else{
        int elem2 = sent[start+1] - '0';
        int output = elem*10+elem2;
        if(output>nums) return false;
        else if(checked[output] == 0){
            arr.push_back(output);
            checked[output] = 1;
            numcur++;
            bool flag = dfs(sent, start+2, sentlen, nums);
            if(flag) return true;
            checked[output] = 0;
            arr.pop_back();
            numcur--;
            return false;
        }
    }
    return false;
}

int main(void){
    string sent;
    ios::sync_with_stdio(false);
	cin.tie(0);
    int start=1;
    int a;
    cin>>sent;
    int n=sent.length();
    if(n<10){
        for(int i=0;i<n;i++){
            cout<<sent[i]<<" ";
        }
    }
    else{
        int nums = (n-9)/2;
        // cout<<n<<endl;
        dfs(sent, 0, n, nums+9);
        
        for(int i=0;i<nums+9;i++)
            cout<<arr[i] <<" ";
    }
}