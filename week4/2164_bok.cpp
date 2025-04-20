// 2164 카드2
#include <iostream>
#include <queue>
using namespace std;

int n;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    queue<int> q;
    for(int i=1; i <= n; i++)    q.push(i);

    while(!q.empty()){
        if(q.size() > 1){
            q.pop();
            int tmp = q.front();
            q.push(tmp);
            q.pop();
        }
        else{
            break;
        }
    }
    cout << q.front();
    return 0;
}
