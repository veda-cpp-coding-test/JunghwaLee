#include <iostream>
#include <stack>
using namespace std;

int n;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    stack<pair<int, int>> s; // 높이, 인덱스
    s.push({100000001, 0});

    for(int idx=1; idx <= n; ++idx){
        int height;
        cin >> height;

        // 왼쪽 탑 높이 < 현재 탑 높이보다 작으면 어차피 신호 못받으니까 pop
        while(!s.empty() && s.top().first < height){
            s.pop();
        }

        cout << s.top().second;
        if(idx != n)    cout << ' ';

        s.push({height, idx});
    }

    return 0;
}