#include <iostream>
#include <stack>
#include <vector>
using namespace std;

int n, val;
stack<int> s; 
vector<char> v; // 정답 출력

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;

    int idx = 1; // 어디까지 숫자 들어갔는지 표기하는 인덱스
    
    for(int i=0; i < n; i++){
        cin >> val;

        // 스택에 해당 값 들어갈 때까지 push
        while(idx <= val){
            s.push(idx++);
            v.push_back('+');
        }
 
        if(s.empty() || s.top() != val){
            cout << "NO";
            return 0;
        }

        // 값이 있으면 -> pop하며 출력
        if(s.top() == val){
            s.pop();
            v.push_back('-');
        }
    }

    for(auto c : v) cout << c << '\n';

    return 0;
}