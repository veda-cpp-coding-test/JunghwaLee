#include <iostream>
using namespace std;

int n;
char star[3073][6145];

void draw_triangle(int y, int x){
    star[y][x] = '*';
    star[y+1][x-1] = '*';
    star[y+1][x+1] = '*';
    for(int i=-2; i < 3; ++i)
        star[y+2][x+i] = '*';
}

void print_triangle(int y, int x, int len){
    if(len == 3){
        draw_triangle(y, x);
        return;
    }

    int new_size = len/2;
    print_triangle(y, x, new_size);
    print_triangle(y + new_size, x - new_size, new_size);
    print_triangle(y + new_size, x + new_size, new_size);
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    int y = n; int x = 2*n - 1;
    for(int i=0; i < y; ++i){
        for(int j=0; j < x; ++j){
           star[i][j] = ' '; 
        }
    }
    print_triangle(0, n-1, n);

    for(int i=0; i < y; ++i){
        for(int j=0; j < x; ++j){
            cout << star[i][j];
        }
        cout << '\n';
    }
    return 0;
}