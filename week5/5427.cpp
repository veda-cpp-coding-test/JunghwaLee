// 5247 불
#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

struct Pos {int x, y;};
const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};

int t, w, h; // 테스트 케이스, 너비, 높이
string board[1001]; 
int fire[1001][1001]; // 불 방문 여부
int person[1001][1001]; // 사람 방문 여부

queue<Pos> fq; // 불
queue<Pos> pq; // 사람

void input()
{
    cin >> w >> h;
    for(int i=0; i < h; ++i){
        cin >> board[i];
        fill(fire[i], fire[i] + w, -1); // 벽이면 -1
        fill(person[i], person[i] + w, -1); // 벽이면 -1
    }
    return;
}

// 큐 비우는 방법
void queue_empty()
{
    fq = queue<Pos>();
    pq = queue<Pos>();
    return;
}

void fire_bfs(){
    // 시작점
    for(int i=0; i < h ;++i){
        for(int j=0; j < w; ++j){
            if(board[i][j] == '*'){ // 불
                fq.push({i, j});
                fire[i][j] = 0;
            }
        }
    }

    while(!fq.empty()){
        Pos cur = fq.front(); fq.pop();
        for(int dir = 0; dir < 4; ++dir){
            int nx = cur.x + dx[dir];
            int ny = cur.y + dy[dir];
            if(nx < 0 || ny < 0 || nx >= h || ny >= w) continue;
            if(fire[nx][ny] >= 0 || board[nx][ny] == '#') continue; // 이미 방문했거나 벽만나면 통과
            fire[nx][ny] = fire[cur.x][cur.y] + 1;
            fq.push({nx, ny}); 
        }
    }
    return;
}

void person_bfs(){
    // 시작점
    for(int i=0; i < h ;++i){
        for(int j=0; j < w; ++j){
            if(board[i][j] == '@'){ // 사람
                pq.push({i, j});
                person[i][j] = 0;
            }
        }
    }
    while(!pq.empty()){
        Pos cur = pq.front(); pq.pop();
        for(int dir = 0; dir < 4 ; ++dir){
            int nx = cur.x + dx[dir];
            int ny = cur.y + dy[dir];
            // 범위 넘으면 통과
            if(nx < 0 || ny < 0 || nx >= h || ny >= w){
                //cout << nx << ' ' << ny << '\n';
                cout << person[cur.x][cur.y] + 1 << '\n';
                queue_empty();
                return; 
            }
            // 이미 방문했거나 벽만나면 통과
            if(person[nx][ny] >= 0 || board[nx][ny] == '#') continue;
            // 불 전파 시간이 사람 전파시간보다 빠를 때는 통과~
            if(fire[nx][ny] >= 0 && fire[nx][ny] <= person[cur.x][cur.y] + 1){
                continue;
            } 
            person[nx][ny] = person[cur.x][cur.y] + 1;
            pq.push({nx, ny});
        }
    }
    cout << "IMPOSSIBLE" << '\n';
    queue_empty();
    return;
}


int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> t;
    while(t--){
        input();
        fire_bfs();
        person_bfs();
    }
        
    return 0;
}