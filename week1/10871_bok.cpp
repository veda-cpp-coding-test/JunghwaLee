// 10871 X보다 작은 수
#include <iostream>
using namespace std;

int n, x, a;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> x;

    for(int i=0; i < n; ++i){
        cin >> a;
        if(a < x)   cout << a << ' ';
    }

    return 0;
}