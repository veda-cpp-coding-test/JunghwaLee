#include <iostream>
#include <algorithm>
using namespace std;

int N, M;
int arr[10];
int res[10];
int isused[10];

void func(int k){
    if(k == M){
        for(int i=0; i < M; ++i)       cout << res[i] << ' ';
        cout << '\n';
        return;
    }

    int prev = -1;
    for(int i=0; i < N; ++i){
        if(!isused[i] && prev != arr[i]){
            res[k] = arr[i];
            isused[i] = 1;
            prev = arr[i];
            func(k+1);
            isused[i] = 0;
        }
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> M;
    for(int i=0; i < N; ++i)    cin >> arr[i];
    sort(arr, arr+N);
    func(0);

    return 0;
}