#include <stdio.h>
int map[22][22][1500];
int max = 0;

void upward(int N, int index, int level);
void downward(int N, int index, int level);
void right(int N, int index, int level);
void left(int N, int index, int level);
void bruteforce(int N, int index, int level);


int main(void){
    int N;
    scanf("%d", &N);
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            int a;
            scanf("%d", &a);
            map[i][j][0] = a;
            if(a>max) max = a;
        }
    }
    bruteforce(N, 0, 0);
    printf("%d", max);
}

void upward(int N, int index, int level){
    if(level > 5) return;
    if(index==0){
        index=0;
    }
    int originindex = (int)index/4;
    // if(index==1025)
    //     index=1025;
    for(int j=0;j<N;j++){
        int start = 0;
        for(int i=0;i<N;){
            int originend = i+1;
            int flag = 0;
            while(map[i][j][originindex] == 0){
                if(i==(N-1)){
                    flag = 1;
                    break;
                }
                i++;
                originend++;
            }
            if(flag == 1) break;
            if(i==(N-1)){
                map[start][j][index] = map[i][j][originindex];
                break;
            }
            while(map[originend][j][originindex] == 0){
                if(originend == N-1){
                    break;
                }
                originend++;
            }
            if(map[i][j][originindex] == map[originend][j][originindex]){
                map[start][j][index] = map[i][j][originindex]*2;
                if(map[start][j][index] > max) {
                    max = map[start][j][index];
                    // printf("At upward, origin=%d, index=%d, level=%d, max=%d\n", originindex, index, level, max);
                }
                start++;
                i=originend+1;
                originend++;
            }
            else{
                map[start][j][index] = map[i][j][originindex];
                start++;
                i++;
            }
            // if(map[0][1][0] == 4){
            //     printf("HERE UPWARD, i=%d, j=%d\n", i, j);
            // }
        }
    }
    bruteforce(N, index, level);
}

void downward(int N, int index, int level){
    if(level > 5) return;
    int originindex = (int)index/4;
    
    if(index==351){
        index=351;
    }
    for(int j=0;j<N;j++){
        int start = N-1;
        for(int i=N-1;i>=0;){
            int flag = 0;
            int originend = i-1;
            while(map[i][j][originindex] == 0){
                if(i == 0) {
                    flag = 1;
                    break;
                }
                i--;
                originend--;
            }
            if(flag) break;
            if(i==0){
                map[start][j][index] = map[i][j][originindex];
                break;
            }
            while(map[originend][j][originindex] == 0){
                if(originend == 0){
                    break;
                }
                originend--;
            }
            if(map[i][j][originindex] == map[originend][j][originindex]){
                map[start][j][index] = map[i][j][originindex]*2;
                if(map[start][j][index] > max){
                    max = map[start][j][index];
                    // printf("At downward, index=%d, level=%d, max=%d\n", index, level, max);
                }
                start--;
                i=originend-1;
                originend--;
            }
            else{
                map[start][j][index] = map[i][j][originindex];
                start--;
                i--;
                originend--;
            }
            // if(map[0][1][0] == 4){
            //     printf("HERE dOWN, i=%d, j=%d\n", i, j);
            // }
        }
    }
    bruteforce(N, index, level);
}

void left(int N, int index, int level){
    if(level > 5) return;
    int originindex = ((int)index/4)-1;
    if(index==344){
        index=344;
    }
    
    for(int i=0;i<N;i++){
        int start = 0;
        for(int j=0;j<N;){
            int originend = j+1;
            int flag = 0;
            while(map[i][j][originindex] == 0){
                if(j == (N-1)){
                    flag = 1;
                    break;
                }
                j++;
                originend++;
            }
            if(flag) break;
            if(j==(N-1)){
                map[i][start][index] = map[i][j][originindex];
                break;
            }
            while(map[i][originend][originindex] == 0){
                if(originend == N-1){
                    break;
                }
                originend++;
            }
            if(map[i][j][originindex] == map[i][originend][originindex]){
                map[i][start][index] = map[i][j][originindex]*2;
                if(map[i][start][index] > max) {
                    max = map[i][start][index];
                    // printf("At left, index=%d, level=%d, max=%d\n", index, level, max);
                }
                start++;
                j = originend + 1;
                originend = j+1;
            }
            else{
                map[i][start][index] = map[i][j][originindex];
                start++;
                j++;
                originend++;
            }
            // if(map[0][1][0] == 4){
            //     printf("HERE LEFT, i=%d, j=%d\n", i, j);
            // }
        }
    }
    bruteforce(N, index, level);
}

void right(int N, int index, int level){
    if(index==0){
        index=0;
    }
    if(level > 5) return;
    int originindex = (int)index/4;
    
    for(int i=0;i<N;i++){
        int start = N-1;
        for(int j=N-1;j>=0;){
            int originend = j-1;
            int flag = 0;
            while(map[i][j][originindex] == 0){
                if(j == 0){
                    flag = 1;
                    break;
                }
                j--;
                originend--;
            }
            if(flag) break;
            if(j==0){
                map[i][start][index] = map[i][j][originindex];
                break;
            }
            while(map[i][originend][originindex] == 0){
                if(originend == 0){
                    break;
                }
                originend--;
            }
            if(map[i][j][originindex] == map[i][originend][originindex]){
                map[i][start][index] = map[i][j][originindex]*2;
                if(map[i][start][index] > max){
                    max = map[i][start][index];
                    
                    // printf("At right, origin=%d, index=%d, level=%d, max=%d\n", originindex, index, level, max);
                }
                start--;
                j=originend-1;
                originend = j-1;
            }
            else{
                map[i][start][index] = map[i][j][originindex];
                start--;
                j--;
                originend--;
            }
            // if(map[0][1][0] == 4){
            //     printf("HERE RIGHT, i=%d, j=%d\n", i, j);
            // }
        }
    }
    bruteforce(N, index, level);
}

void bruteforce(int N, int index, int level){
    // printf("index = %d, level = %d\n", index, level);
    
    if(level>5) return;
    upward(N, index*4+1, level+1);
    right(N, index*4+2, level+1);
    downward(N, index*4+3, level+1);
    left(N, index*4+4, level +1);
}