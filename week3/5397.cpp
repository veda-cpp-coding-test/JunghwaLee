#include <iostream>
#include <list>
using namespace std;

string s;
int n;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;

    while(n--){
        cin >> s;

        list<char> L;
        auto cursor = L.begin();
        for(auto c : s){
            if(c == '<'){
                if(cursor != L.begin()){
                    cursor--;
                }
            }
            else if(c == '>'){
                if(cursor != L.end()){
                    cursor++;
                }
            }
            else if(c == '-'){       
                if(cursor != L.begin()){
                    cursor = L.erase(--cursor);
                }
            }
            else{
                L.insert(cursor, c);
            }
        }
        for(auto c : L) cout << c;
        cout << '\n';
    }
    return 0;
}