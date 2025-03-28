#include <stdio.h>
int multval(int a, int b, int x, int y, int r){
    return (a-x)*(a-x) + (b-y)*(b-y) - r*r;
}
int main(void){
    int T;
    scanf("%d", &T);
    for(int i=0;i<T;i++){
        int x1, y1, x2, y2;
        scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
        int N;
        int cnt = 0;
        scanf("%d", &N);
        for(int j=0;j<N;j++){
            int a, b, c;
            scanf("%d %d %d", &a, &b, &c);
            if((multval(a, b, x1, y1, c) > 0) && (multval(a, b, x2, y2, c) < 0))
                cnt++;
            if((multval(a, b, x1, y1, c) < 0) &&(multval(a, b, x2, y2, c) > 0))
                cnt++;
            
        }
        printf("%d\n", cnt);
    }
}