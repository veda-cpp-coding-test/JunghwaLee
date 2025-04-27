#include <bits/stdc++.h>
using namespace std;

string input;
int cnt = 0;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> input;

    stack <int> s;

    for(int i = 0;  i < input.length(); i++)
    {
        if(input[i] == '(') s.push(input[i]);
        else
        {
            // 레이저 -> + 막대의 갯수(스택에 들어있는 '('의 갯수))
            if(input[i-1] == '(')
            {
                s.pop();
                cnt += s.size();
            }
            else // 막대의 끝 -> 마지막 막대의 갯수 + 1
            {
                s.pop();
                cnt += 1;
            }
        }
    }

    cout << cnt;
}