#include <iostream>
#include <algorithm>
using namespace std;

int height[9];
int sum;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    for(int i=0; i < 9; i++){
        cin >> height[i];
        sum += height[i];
    }

    bool found_flag = false; // i 반복문 빠져나가기 위한 flag
    for(int i=0; i < 9 && !found_flag; i++){
        for(int j=i+1;j < 9; j++){
            if(sum - height[i] - height[j] == 100){
                height[i] = 0;
                height[j] = 0;
                found_flag = true;
                break;
            }
        }
    }

    sort(height, height+9);

    for(int i=2; i < 9; i++){
        /*if(height[i] > 0)*/   cout << height[i] << '\n';
    }

    return 0;
}