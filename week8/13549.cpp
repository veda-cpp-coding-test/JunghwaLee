#include <iostream>
#include <queue>
#include <climits>
using namespace std;

int vis[200002];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, k;
    cin >> n >> k;

    fill(vis, vis + 200002, -1);

    deque<int> dq;
    dq.push_front(n);
    vis[n] = 0;
    
    int res = INT_MAX;
    while(!dq.empty()){
        int cur = dq.front(); dq.pop_front();
        if(cur == k){
            cout << vis[cur];
            return 0;
        }
        int arr[3] = {cur * 2, cur + 1, cur - 1};
        for(int i=0; i < 3; ++i){
            int nxt = arr[i];
            if(nxt < 0 || nxt > 100000)   continue;
            
            // 순간이동: 우선 처리 : 현재 위치가 도착한 시간보다 더 빠른시간이라면 갱신!
            if(i == 0 && (vis[nxt] == -1 || vis[nxt] > vis[cur])){ 
                vis[nxt] = vis[cur];
                dq.push_front(nxt);
            }
            // 순간이동 아닌 경우: 나중 처리 
            if(i != 0 && (vis[nxt] == -1 || vis[nxt] > vis[cur] + 1)){ 
                vis[nxt] = vis[cur] + 1;
                dq.push_back(nxt);
            }
        }
    }
    cout << -1;

    return 0;
}