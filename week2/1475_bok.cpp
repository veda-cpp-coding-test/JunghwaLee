#include <bits/stdc++.h>
using namespace std;

int res = 0;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    

    string n;
    cin >> n;
    
    int arr[10] = {0, };
    for(auto c : n){  
        arr[c-'0']++;
    }

    if(!((arr[6]+arr[9]) % 2))    arr[6] = (arr[6] + arr[9])/2;
    else    arr[6] = ((arr[6] + arr[9])/2) + 1;
    arr[9]= 0;

    for(int i=0; i <= 9; i++){
        res = max(res, arr[i]);
    }
    cout << res;

    return 0;
}