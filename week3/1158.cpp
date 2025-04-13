#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int n,k, idx;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
     
    cin >> n >> k;

// 벡터 이용
#if 0
    vector<int> v(n);
    
    // 벡터를 n으로 초기화하고 나서 모든 원소가 초기화 되기 전가지 push_back 사용 X 
    // 인덱스로 값 할당!
    for(int i=1; i <= n; i++){
        v[i-1] = i;
    }

    idx = k-1;
    cout << '<';

    while(!v.empty()){
        cout << v[idx];
        v.erase(v.begin() + idx);
        if(!v.empty()){
            cout << ", ";
            // 지울 인덱스가 벡터 크기만큼을 넘어설 수 있으니까 나머지 이용하여 인덱스 처음으로 돌리기
            idx = (idx + k-1) % v.size();
        }  
    }
    cout << '>';
#endif

// 큐 이용
    queue<int> Q;
    for(int i=1; i <=n; i++){
        Q.push(i);
    }
    cout << '<';

    while(!Q.empty()){
        for(int i=0; i < k-1; i++){
            Q.push(Q.front());
            Q.pop();
        }
        cout << Q.front();
        Q.pop();
        if(Q.size())    cout << ", ";
    }
    cout << ">";
    return 0;
}