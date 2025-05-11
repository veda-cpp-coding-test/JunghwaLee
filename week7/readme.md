### 1759_암호 만들기  
```cpp
// 1759 암호 만들기 
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int L, C;
char res[20];
int isused[20];
vector<char> letter;

// 모음 여부와 자음2개 이상인지 판단하는 함수 
bool isvowel_word(){
    bool vowel_flag = false;
    int cnt=0; // 자음 수
    bool flag = false;
    for(int i=0; i < L; ++i){
        char vowel = res[i];
        if(vowel == 'a' || vowel == 'e' || vowel == 'i' 
            || vowel == 'o' || vowel == 'u')
                vowel_flag = true;
        else{
            ++cnt;
        }
    }
    if(cnt >= 2 && vowel_flag)  flag = true;
    return flag;    
}

void func(int k, int start){
    if(k == L){
        if(isvowel_word()){
            for(int i=0; i < L; ++i){
                cout << res[i];
            }
            cout << '\n';
        }
        return;
    }

    for(int i=start; i < C; ++i){
        res[k] = letter[i];
        func(k+1, i+1); // i+1로 다음 인덱스부터 탐색
    }

}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> L >> C;
    letter.resize(C);

    for(int i=0; i < C; ++i){
        cin >> letter[i];
    }
    sort(letter.begin(), letter.end());         
    func(0, 0);
    return 0;
}
```  
**알고리즘 설계**  
1. 입력 받은 문자들 먼저 오름차순으로 정렬
2. 만들 글자수와, 시작할 인덱스를 가지고 백트래킹 시작
    - 시작할 인덱스부터 다음 인덱스부터만 탐색하여 다음 글자수 선택
    - 모음이 있고, 자음 2개 이상 있으면 문자열의 각 글자수 출력  

*기억해야할 점*
```cpp
for(auto vowel : res){
    ...
}
```
처음에 위 코드와 같이 배열의 요소를 순회했는데, 암호 생성은 L길이까지만 유효하기에, 초과된 공간까지 탐색하면 불필요한 데이터 포함됨  
-> 설계한대로 제대로 나오지 않음.... 유효한 길이만 탐색하도록 변경  

### 16987_계단으로 계란치기  
XX
백트래킹으로 모든 경우를 탐색해야 한다고 생각했지만, 조건을 제대로 생각하지 못함  
```cpp
#include <iostream>
#include <algorithm>
using namespace std;

int n, res;
struct Info{ int s; int w; };
Info egg[10];

void func(int k){
    if(k == n){
        int broken = 0;
        for(int i=0; i < n; ++i){
            if(egg[i].s <= 0) ++broken;
        }
        res = max(res, broken);
        return;
    }

    // 현재 계란이 이미 깨졌다면 바로 다음 계란 이동
    if(egg[k].s <= 0){
        func(k+1);
        return;
    }

    bool check = false;
    for(int i=0; i < n; ++i){
        // 손에 든 계란이거나, 이미 깨진 계란이면 패스
        if(i == k || egg[i].s <= 0) continue; 

        // 계란 칠 때,
        egg[k].s -= egg[i].w;
        egg[i].s -= egg[k].w;
        check = true;
        // 다음 계란 이동
        func(k+1);
        // 원상 복구
        egg[k].s += egg[i].w;
        egg[i].s += egg[k].w;
    }
    // 계란 모두 깨진 상황(현재 계란은 남아있고)
    if(!check)  func(k+1);
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for(int i=0; i < n; ++i){
        cin >> egg[i].s >> egg[i].w;
    }
    func(0);
    cout << res;
    return 0;
}
```

### 1941_소문난 칠공주
-> BFS + DFS 함께 섞인 문제
1. 백트래킹(DFS) 사용하여 25명 중 7명 뽑기 = 조합
2. 4명 이상 있는지 확인하는 함수
3. BFS 사용하여 7명 인접한지 확인

```cpp
// 1941 소문난 칠공주 
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int board[5][5]; // Y, S 저장하는 보드 
int isused[25]; // 조합 -> 7명 뽑을 때 사용 여부 판단
int ans; 

struct Pos{int y; int x; };
int dy[4] = {1, 0, -1, 0};
int dx[4] = {0, 1, 0, -1};

void input(){
    for(int i=0; i < 5; ++i){
        string str;
        cin >> str;
        for(int j=0; j < 5; ++j){
            if(str[j] == 'Y')   board[i][j] = 1;
            if(str[j] == 'S')   board[i][j] = 2;
        }
    }
}

// 4명 이상 있는지 확인
bool ismore4(){
    int Y_cnt=0, S_cnt=0;
    for(int i=0; i < 25; ++i){
        if(isused[i]){
            int y = i / 5;
            int x = i % 5;
            if(board[y][x] == 1)   Y_cnt++;
            if(board[y][x] == 2)   S_cnt++;
        }
    }
    return (S_cnt >= 4);
}

// 7명 서로 인접한지 확인(BFS)
bool adjency(){
    queue<Pos> q;
    int vis[5][5] = {0, }; // 방문 여부 저장
    
    // 7명 위치 좌표 저장
    vector<Pos> sel;
    for(int i=0; i < 25; ++i){
        if(isused[i]){
            sel.push_back({i/5, i%5});
        }
    }

    q.push(sel[0]);
    vis[sel[0].y][sel[0].x] = 1;

    int cnt = 1; // 연결된 요소 수 
    while(!q.empty()){
        Pos cur = q.front(); q.pop();
        for(int dir = 0; dir < 4; ++dir){
            int ny = cur.y + dy[dir];
            int nx = cur.x + dx[dir];
            
            if(ny < 0 || ny >= 5 || nx < 0 || nx >= 5)  continue;
            if(vis[ny][nx]) continue;

            // ny, nx가 현재 뽑힌 7명에 포함되는지 확인
            for(const Pos& p : sel){
                if(p.y == ny && p.x == nx && !vis[ny][nx]){
                    vis[ny][nx] = 1;
                    q.push({ny, nx});
                    ++cnt;
                }
            }

        }
    }
    return (cnt==7);
}


// 25명 중 7명 뽑기
void dfs(int idx, int k){
    if(k == 7){
        if(ismore4() && adjency()){
            ans++;
        }
        return;
    }

    for(int i=idx; i < 25; ++i){
        if(!isused[i]){
            isused[i] = 1;
            dfs(i, k+1);
            isused[i] = 0;
        }
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    input();
    dfs(0, 0);
    cout << ans;
    return 0;
}
```




