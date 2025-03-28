#include <stdio.h>
#include <algorithm>
#include <vector>
using namespace std;
vector<pair<long long int, long long int> > arr;
double cos(pair<long long int, long long int> a){
    long long int den=(a.first*a.first + a.second*a.second);
    return (double)(a.first*a.first)/den;
}

bool cmp(const pair<long long int, long long int> &a, const pair<long long int, long long int> b){
    if(a.second >= 0){
        if(b.second >= 0){
            return  cos(a)> cos(b);
        }
        return true;
    }
    else{
        if(b.second < 0){
            return cos(a) < cos(b);
        }
        return false;
    }
}

int main(void){
    int N;
    scanf("%d", &N);
    long double area=0;
    long long int a0, b0;
    scanf("%lld %lld", &a0, &b0);
    for(int i=1;i<N;i++){
        long long int a, b;
        scanf("%lld %lld", &a, &b);
        arr.push_back(make_pair(a-a0, b-b0));
    }
    // sort(arr.begin(), arr.end(), cmp);
    for(int i=1;i<N-1;i++){
        area += (long double)(arr[i].second*arr[i-1].first - arr[i].first*arr[i-1].second) *0.5;
    }
    if(area<0) area = -area;
    printf("%.1Lf", area);
}