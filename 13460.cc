#include <stdio.h>
#include <queue>
using namespace std;

char arr[11][11];
int state[11][11][11][11];
int checked[11][11][11][11];
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};
int minimum = 11;
typedef struct pos{
    int redx;
    int redy;
    int bluex;
    int bluey;
    int cnt;
}pos;
queue<pos> positions;

int foo(int i, int j, int n, int m){
    if(i<0) return -1;
    if(j<0) return -1;
    if(i>=n) return -1;
    if(j>=m) return -1;
    if(arr[i][j] == 'O') return 2;
    if(arr[i][j] != '#') return 1;
    else return 3;
}

void bfs(int cnt, int RedX, int RedY, int BlueX, int BlueY, int n, int m){
    pos cur = {RedX, RedY, BlueX, BlueY, cnt};
    positions.push(cur);

    while(!positions.empty()){
        int RX = positions.front().redx;
        int RY = positions.front().redy;
        int BX = positions.front().bluex;
        int BY = positions.front().bluey;
        int cnt = positions.front().cnt;
        if(cnt > 10) break;
        cnt++;
        
        for(int i=0;i<4;i++){
            int redx = RX;
            int redy = RY;
            int bluex = BX;
            int bluey = BY;
            int flag = 0;//0: nothing happen 1: red in hole -1 : blue in hole 2: move
            int tmp = foo(redx + dx[i], redy + dy[i], n, m);
            while(tmp == 1){
                redx += dx[i];
                redy += dy[i];
                tmp = foo(redx + dx[i], redy + dy[i], n, m);
                flag = 2;
            }
            if(tmp == 2){
                redx += dx[i];
                redy += dy[i];
                flag = 1;
            }
            tmp = foo(bluex + dx[i], bluey + dy[i], n, m);
            while(tmp == 1){
                bluex += dx[i];
                bluey += dy[i];
                tmp = foo(bluex + dx[i], bluey + dy[i], n, m);
                if(flag!=1) flag = 2;
            }
            if(tmp == 2){
                bluex += dx[i];
                redy += dy[i];
                flag = -1;
            }
            if((redx == bluex) && (redy == bluey)){
                if((RX * dx[i] + RY*dy[i]) < (BX * dx[i] + BY*dy[i])){
                    redx -= dx[i];
                    redy -= dy[i];
                }
                else{
                    bluex -= dx[i];
                    bluey -= dy[i];
                }
            }
            if((RX == redx) && (RY == redy) && (BX == bluex) && (BY == bluey))
                flag = 0;
            if(flag == 1){
                if(minimum > cnt) minimum = cnt;
                continue;
            }
            else if(flag == -1) continue;
            if(flag == 0) continue;
            pos cur = {redx, redy, bluex, bluey, cnt};
            if(!checked[redx][redy][bluex][bluey])
                positions.push(cur);
            checked[redx][redy][bluex][bluey] = 1;
        }
        positions.pop();
    }
}

int main(void){
    int n, m;
    scanf("%d %d", &n, &m);
    int RedX, RedY, BlueX, BlueY, ZeroX, ZeroY;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            char a;
            scanf(" %c", &a);
            arr[i][j] = a;
            if(a == 'R'){
                RedX = i;
                RedY = j;
            }
            if(a == 'B'){
                BlueX = i;
                BlueY = j;
            }
            if(a == 'O'){
                ZeroX = i;
                ZeroY = j;
            }
        }
    }
    checked[RedX][RedY][BlueX][BlueY] = 1;
    bfs(0, RedX, RedY, BlueX, BlueY, n, m);
    if(minimum <= 10) printf("%d", minimum);
    else printf("-1");
}



// void bfs(int cnt, int RedX, int RedY, int BlueX, int BlueY, int n, int m){    
//     int redx = RedX;
//     int redy = RedY;
//     int bluex = BlueX;
//     int bluey = BlueY;

//     cnt++;
//     if(cnt > 10){
//         return;
//     }
    
//     for(int i=0;i<4;i++){
//         //nothing happen : flag == -2
//         // blue in hole : flag == -1
//         //red only move : flag == 2
//         //blue only move : flag == 3
//         //both move : 0
//         //only red in hole : 1
        
//         int flag = -2;
//         if(checked[redx][redy][bluex][bluey][i] == 1) 
//             continue;
//         if(cnt ==4)
//             cnt = 4;
//         checked[redx][redy][bluex][bluey][i] = 1;
//         int tmp = foo(redx + dx[i], redy + dy[i], n, m);
//         while(tmp == 1){
//             redx += dx[i];
//             redy += dy[i];
//             tmp = foo(redx + dx[i], redy + dy[i], n, m);
//             flag = 2;
//         }
//         if(tmp == 2){
//             flag = 1;
//         }
//         tmp = foo(bluex + dx[i], bluey + dy[i], n, m);
//         while(tmp == 1){
//             bluex += dx[i];
//             bluey += dy[i];
//             tmp = foo(bluex + dx[i], bluey + dy[i], n, m);
//             if(flag == 2) flag = 0;
//             else if(flag == -2) flag = 3;
//         }
//         if(tmp == 2) flag = -1;
//         tmp = foo(redx + dx[i], redy + dy[i], n, m);
//         while(tmp == 1){
//             redx += dx[i];
//             redy += dy[i];
//             tmp = foo(redx + dx[i], redy + dy[i], n, m);
//             if(flag ==3) flag = 0;
//         }
//         if((tmp == 2) && (flag != -1)){
//             flag = 1;
//         }
//         checked[redx][redy][bluex][bluey][i] = 1;
//         if(flag == -2) continue;
//         if((state[redx][redy][bluex][bluey] > cnt) || (state[redx][redy][bluex][bluey] == 0))
//             state[redx][redy][bluex][bluey] = cnt;
//         else return;
//         if(flag == 0){
//             arr[redx][redy] = 'R';
//             arr[RedX][RedY] = '.';
//             arr[bluex][bluey] = 'B';
//             arr[BlueX][BlueY] = '.';
//             func(cnt, redx, redy, bluex, bluey, n, m);
//             arr[RedX][RedY] = 'R';
//             arr[redx][redy] = '.';
//             arr[BlueX][BlueY] = 'B';
//             arr[bluex][bluey] = '.';
//         }
//         else if(flag == 2){
//             arr[redx][redy] = 'R';
//             arr[RedX][RedY] = '.';
//             func(cnt, redx, redy, bluex, bluey, n, m);
//             arr[RedX][RedY] = 'R';
//             arr[redx][redy] = '.';
//         }
//         else if(flag == 3){
//             arr[bluex][bluey] = 'B';
//             arr[BlueX][BlueY] = '.';
//             func(cnt, redx, redy, bluex, bluey, n, m);
//             arr[BlueX][BlueY] = 'B';
//             arr[bluex][bluey] = '.';
//         }
//         else if(flag == 1){
//             if(min > cnt) min = cnt;
//             return;
//         }
//         else{
//             return;
//         }
        
//     }
// }