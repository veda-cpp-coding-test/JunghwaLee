#include <iostream>
#include <queue>
#include <cstring>
using namespace std;

char board[12][6];
int ans;
struct Pos { int y, x; };
int dy[4] = { 0, 1, 0, -1 };
int dx[4] = { 1, 0, -1, 0 };

void input() {
    for (int i = 0; i < 12; ++i) {
        for (int j = 0; j < 6; ++j) {
            cin >> board[i][j];
        }
    }
}

//  뿌요 탐색 하는 함수 
bool bfs(int y, int x, char color) {
    queue<Pos> q;
    vector<Pos> same_color;
    bool discovered[12][6];
    memset(discovered, false, sizeof(discovered));

    q.push({ y, x });
    discovered[y][x] = true;
    same_color.push_back({ y, x });

    while (!q.empty()) {
        Pos cur = q.front(); q.pop();
        for (int dir = 0; dir < 4; ++dir) {
            int ny = cur.y + dy[dir];
            int nx = cur.x + dx[dir];
            if (ny < 0 || ny >= 12 || nx < 0 || nx >= 6) continue;
            if (!discovered[ny][nx] && board[ny][nx] == color) {
                q.push({ ny, nx });
                same_color.push_back({ ny, nx });
                discovered[ny][nx] = true;
            }
        }
    }

    if (same_color.size() >= 4) {
        for (Pos p : same_color) {
            board[p.y][p.x] = '.';
        }
        return true;
    }
    else {
        return false;
    }
}

// 뿌요 내리는 함수 
void down() {
    for (int x = 0; x < 6; ++x) {
        int emptyRow = 11;
        for (int y = 11; y >= 0; --y) {
            // 색깔인 부분 아래 . 이있는지 emptyrow로 판단
            if (board[y][x] != '.') {
                if (emptyRow != y) {
                    board[emptyRow][x] = board[y][x];
                    board[y][x] = '.';
                }
                --emptyRow;
            }
        }
    }
}

void solve() {
    while (1) {
        bool check = false;
        for (int i = 0; i < 12; ++i) {
            for (int j = 0; j < 6; ++j) {
                // 보드가 색깔인 부분에서 -> 탐색 했을 때 연쇄 파괴 여부 파악
                if (board[i][j] != '.' && bfs(i, j, board[i][j])) {
                    check = true;
                }
            }
        }

        if (!check)  break;
        else {
            down();
            ++ans;
        }
    }
    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    input();
    solve();

    return 0;
}
