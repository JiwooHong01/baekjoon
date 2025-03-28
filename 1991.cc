#include <stdio.h>
#include <iostream>
using namespace std;

int arr[30][3];

int findindex(int elem, int n){
    for(int i=0;i<n;i++){
        if(arr[i][0] == elem) return i;
    }
    return -1;
}
void preorder(int root, int n){
    int ind = findindex(root, n);
    printf("%c", arr[ind][0] + 'A');
    if(arr[ind][1]>=0) preorder(arr[ind][1], n);
    if(arr[ind][2]>=0) preorder(arr[ind][2], n);

}

void inorder(int root, int n){
    int ind = findindex(root, n);
    if(arr[ind][1]>=0) inorder(arr[ind][1], n);
    printf("%c", arr[ind][0] + 'A');
    if(arr[ind][2]>=0) inorder(arr[ind][2], n);

}
void postorder(int root, int n){
    int ind = findindex(root, n);
    if(arr[ind][1]>=0) postorder(arr[ind][1], n);
    if(arr[ind][2]>=0) postorder(arr[ind][2], n);
    printf("%c", arr[ind][0] + 'A');
}


int main(void){
    int n;
    scanf("%d", &n);
    for(int i=0;i<n;i++){
        char a, b, c;
        cin >> a >> b >> c;
        arr[i][0] = a-'A';
        arr[i][1] = b-'A';
        arr[i][2] = c-'A';
    }
    preorder(0, n);
    printf("\n");
    inorder(0, n);
    printf("\n");
    postorder(0, n);
}