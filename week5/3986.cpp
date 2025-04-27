#include <iostream>
#include <stack>
using namespace std;

int n;
string str;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    int cnt=0;
    while(n--){
        cin >> str;
        stack<char> s;
        for(int i=0; i < str.size(); ++i){
            if(!s.empty() && (s.top() == str[i])){
                s.pop();
            }
            else {
                s.push(str[i]);
            }
        }

        if(s.empty())   ++cnt;
    }
    cout << cnt;


    return 0;
}