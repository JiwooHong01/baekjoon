#include <stdio.h>
#include <string.h>

int main(void){
    char arr[1001];
    int n;
    scanf("%s", arr);
    scanf("%d", &n);
    printf("%c", arr[n-1]);
}