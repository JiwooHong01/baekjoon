#include <stdio.h>
#include <queue>
using namespace std;

typedef struct st{
    int clip;
    int screen;
    int stage;
}st;
queue<st> qq;
int checked[1001][2001];

int bfs(int S){
    while(!qq.empty()){
        st cur = qq.front();
        qq.pop();
        int clip = cur.clip;
        int screen = cur.screen;
        int stage = cur.stage;
        if(screen == S) return stage;
        if(screen !=0){
            if(!checked[clip][screen-1]){
                st cur3 = {clip, screen - 1, stage+1};
                qq.push(cur3);
                checked[clip][screen-1]=1;
            }
        }   
        if(screen > S) continue;
        if(!checked[screen][screen]){
            st cur1 = {screen, screen, stage+1};
            qq.push(cur1);
            checked[screen][screen]=1;
        }
        if(clip != 0){
            if(!checked[clip][screen+clip]){
                st cur2 = {clip, screen + clip, stage+1};
                qq.push(cur2);
                checked[clip][screen+clip]=1;
            }
        }
        
    }
    return 100000;
}

int main(void){
    int S;
    scanf("%d", &S);
    st cur = {0, 1, 0};
    qq.push(cur);
    int ans = bfs(S);
    printf("%d", ans);
}