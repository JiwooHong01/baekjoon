#include <iostream>
#include <cstring>
//8:00PM-
using namespace std;
int start, ending, reverseflag;
int result[100001];
int RD(string arr, string func, int length){
    int lenoffunc = func.size();
    start = 0;
    ending = length-1;
    reverseflag = 0;
    for(int i=0;i<lenoffunc;i++){
        char F = func[i];
        if(F == 'R'){
            if(reverseflag == 1) reverseflag = 0;
            else reverseflag = 1;
        }
        if(F == 'D'){
            if(ending<start) return 0;
            if(reverseflag == 0){
                start++;
            }
            else{
                ending--;
            }
        }
    }
    return 1;
}

void preprocess(string arr){
    int value = 0;
    int index = 0;
    for(int i=1;i<arr.size();i++){
        if(arr[i] == ','){
            result[index] = value;
            value = 0;
            index++;
        }
        else if(arr[i] == ']'){
            result[index] = value;
        }
        else{
            value = value*10 + (arr[i] - '0');
        }
    }
}

int main(void){
    int T;
    ios::sync_with_stdio(false);
    cin.tie(0);
    string func, arr;
    cin>>T;
    for(int i=0;i<T;i++){
        cin>>func;
        int length;
        cin>>length;
        cin>>arr;
        preprocess(arr);
        int output = RD(arr, func, length);
        if(output == 0) cout<<"error"<<endl;
        else{
            cout<<"[";
            if(reverseflag == 0){
                for(int j=start;j<ending;j++){
                    cout<<result[j]<<",";
                }
                if(start<=ending)
                    cout<<result[ending];
            }
            else{
                for(int j=ending;j>start;j--){
                    cout<<result[j]<<",";
                }
                if(start<= ending)
                    cout<<result[start];
            }
            cout<<"]"<<endl;
        }

    }
}