#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int n, m, cnt;
vector<int> adj[1002];
bool vis[1002];

void bfs(){
    queue<int> q;
    for(int i=1; i <= n; ++i){
        if(vis[i])  continue;
        q.push(i);
        vis[i] = true;
        cnt++;
        while(!q.empty()){
            int cur = q.front(); q.pop();
            for(auto nxt : adj[cur]){
                if(vis[nxt])    continue;
                q.push(nxt);
                vis[nxt] = true;
            }
        }
    }
    cout << cnt;
    return ;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;
    for(int i=0; i < m; ++i){
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    bfs();

    return 0;
}