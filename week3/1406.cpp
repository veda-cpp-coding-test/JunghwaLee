#include <iostream>
#include <list>
using namespace std;

string s;
int n;
char cmd;

int main()
{
    cin >> s >> n;

    // 초기 문자열 리스트에 넣기
    list<char> L(s.begin(), s.end());

    // 커서 선언
    list<char>::iterator cursor = L.end();

    for(int i=0; i < n; i++){
        cin >> cmd;

        switch(cmd){
        // 왼쪽 이동
        case 'L':
            if(cursor != L.begin()){
                cursor--;
            }
            break;
        // 오른쪽 이동
        case 'D':
            if(cursor != L.end()){
                cursor++;
            }
            break;
        // 삭제
        case 'B':  {
            if(cursor != L.begin()){
                auto del = cursor;
                L.erase(--del);
            }
            break;
        }
        // 삽입
        case 'P': {
            char letter;
            cin >> letter;
            // cursor가 가리키는 곳 앞에 letter 삽입
            L.insert(cursor, letter);
            break;
        }
        default:
            break;
        }

    }

    for(auto i : L) cout << i;
    return 0;
}