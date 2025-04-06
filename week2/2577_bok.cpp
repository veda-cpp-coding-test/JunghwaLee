#include <iostream>
using namespace std;

int val, a,b,c;
int arr[10];
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> a >> b >> c;
    val = a * b * c;

    while(val > 0){
        arr[val%10]++;
        val /= 10;        
    }

    for(int i=0; i < 10; i++){
        cout << arr[i] << '\n';
    }
    return 0;

}