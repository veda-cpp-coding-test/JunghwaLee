#include <iostream>
using namespace std;

void print_star(int y, int x, int n){
    if(n == 1){
        cout << "*";
        return;
    }
    
    if(((y/(n/3)) % 3 == 1)&&((x/(n/3)) % 3 == 1)){
        cout << " ";
    }
	else {
        print_star(y, x, n / 3);
	}
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;
    for(int i=0; i < n; i++){ // 행
        for(int j=0; j < n; j++){ // 열
            print_star(i, j, n);
        } 
        cout << '\n';
    }

    return 0;
}