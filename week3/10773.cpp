// 10773 제로
#include <bits/stdc++.h>

using namespace std;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int k, n;
    cin >> k;
    stack<int> s;

    for(int i=0; i < k; i++){
        cin >> n;
        if(n == 0)  s.pop();
        else    s.push(n);
    }
    
    int res = 0;
    
    while(!s.empty()){
        res += s.top();
        s.pop();
    }
    cout << res << '\n';
    return 0;
}