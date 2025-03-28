#include <iostream>
#include <vector>
using namespace std;
// vector<char> vv;

char vv[101];
int cnt[30];

int check(int ind){
    int flag = 1;
    for(int i=0;i<26;i++){
        if(cnt[i] != 0){
            flag = 0;
            return i;
        }
    }
    //ret -1: use all characters allocated
    return -1;
}

int totsum(void){
    int res = 0;
    for(int i=0;i<26;i++){
        if(cnt[i] != 0){
            res+=cnt[i];
        }
    }
    //ret -1: use all characters allocated
    return res;
}

int func(char curalphabet, int N, int curpos){
    //curnode : current node
    
    int nodepos = curalphabet-'A';
    int ret=0;
    int index = check(nodepos+2);
    if(N == curpos){
        if(index == -1) return 1;//ideal string
        return 0; // wrong string
    }
    else if(index != -1){
        cnt[index] -= 1;
        vv[curpos] = index + 'A';
        ret = func(curalphabet, N, curpos+1);
        if(ret == 0){
            vv[curpos] = '\0';
            cnt[index] += 1;
            if(cnt[index] == curpos){
                cnt[index] = 0;
                return 0;
            }
        }
        else return 1;
    }
    
    
    if(curpos * 2 +1 + totsum() <= N){
        cnt[nodepos+1] = curpos;
        vv[curpos] = (curalphabet+1);
        ret = func(curalphabet+1, N, curpos+1); // New character
        if(ret == 0){
            vv[curpos] = '\0';
            cnt[nodepos+1] += 1;
            if(cnt[nodepos+1] == curpos + 1){
                cnt[nodepos+1] = 0;
            }
        }
    }
    return ret;
}

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int N;
    cin>>N;
    if(N==1) printf("A");
    else{
        vv[0] = 'A';
        cnt[1] = 1;
        vv[1] = 'B';
        int ret = func('B', N, 2);
        if(ret){
            for(int i=0;i<N;i++)
                cout<<vv[i];
        }
        else{
            cout<<"-1";
        }
    }
}