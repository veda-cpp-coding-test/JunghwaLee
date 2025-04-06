// 3273 두수의 합 -> 투포인터 알고리즘 사용
// 브루트포스로 완전탐색 시 O(N^2) -> 시간 초과

#include <iostream>
#include <algorithm>
using namespace std;

int n, x, ans;
int arr[1000001];
bool occur[1000001]; // 각 자연수의 존재 여부 저장하는 배열

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for(int i=0; i < n; i++){
        cin >> arr[i];
    }
    cin >> x;

#if 0
 // 투포인터 알고리즘 -> O(N)   
    sort(arr, arr+n);  
    int left=0, right=n-1;
    int sum;
    while(left < right){
        sum = arr[left]+arr[right];
        if(sum == x){ 
            ans++;
            right--;
        }
        else if(sum > x){
            right--;
        }
        else if(sum < x){
            left++;
        }
    }
#endif

    for(int i=0; i < n; i++){
        if(x-arr[i] > 0 && occur[x-arr[i]]) ans++;
        occur[arr[i]] = true;
    }
    cout << ans;
}