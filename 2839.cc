#include <stdio.h>
#include <vector>

using namespace std;

int main(void){
    int N;
    scanf("%d", &N);
    int last = (int)N/5;
    bool flag = true;
    for(int i=last;i>=0;i--){
        int tmp = N - i*5;
        if(tmp % 3 == 0){
            flag = false;
            printf("%d", i + (int)tmp/3);
            break;
        }
    }
    if(flag) printf("-1");
}