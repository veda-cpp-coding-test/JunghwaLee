#include <iostream>
#include <algorithm> // find()
#include <deque>
using namespace std;

int n, m, ans;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;
    deque<int> dq;
    for(int i=1; i <=n; ++i)   dq.push_back(i);

    for(int i=0; i < m; i++){
        int num;
        cin >> num;
        // 해당 값 인덱스 찾기
        int idx = distance(dq.begin(), find(dq.begin(), dq.end(), num)); 
        // 
        int left_cnt = idx, right_cnt = dq.size() - idx;
        if(left_cnt <= right_cnt){ // 왼쪽 이동
            while(dq.front() != num){
                int tmp = dq.front();
                dq.push_back(tmp);
                dq.pop_front();
            }
        }
        else{ // 오른쪽 이동
            while(dq.front() != num){
                int tmp = dq.back();
                dq.push_front(tmp);
                dq.pop_back();
            }
        }
        dq.pop_front(); // 해당 요소 값 빼고...
        ans += min(left_cnt, right_cnt);
    }
    cout << ans;

    return 0;
}