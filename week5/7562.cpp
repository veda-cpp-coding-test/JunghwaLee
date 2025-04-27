// 7562 나이트의 이동
#include <iostream>
#include <queue>
using namespace std;

struct Pos{int y, x; };
int dy[8] = {-2, -2, -1, -1, 1, 1, 2, 2};
int dx[8] = {-1, 1, -2, 2, -2, 2, -1, 1};
int vis[302][302]; // 체스판 방문 여부
int t, l;
Pos start, goal;

void input()
{
    cin >> l;
    cin >> start.y >> start.x;
    cin >> goal.y >> goal.x;

    for(int i=0; i < l; ++i){
        fill(vis[i], vis[i]+l, -1);
    }

    return;
}

void bfs()
{
    queue<Pos> q;
    q.push({start.y, start.x});
    vis[start.y][start.x] = 0; // 시작점 0으로 시작

    if(start.y == goal.y && start.x == goal.x){
        cout << 0 << '\n';
        return;
    }

    while(!q.empty()){
       Pos cur = q.front(); q.pop();
       for(int dir=0; dir < 8; ++dir){
            int ny = cur.y + dy[dir];
            int nx = cur.x + dx[dir];
            if(ny == goal.y && nx == goal.x){
                cout << vis[cur.y][cur.x] + 1 << '\n';
                return;
            }
            if(ny < 0 || nx < 0 || ny >= l || nx >= l)  continue;
            if(vis[ny][nx] >= 0) continue; // 방문한 적 있으면 pass
            vis[ny][nx] = vis[cur.y][cur.x] + 1;
            q.push({ny, nx});
       } 
    }
    return;
}

int main(){

    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> t;
    while(t--){
        input();
        bfs();
    }

    return 0;
}