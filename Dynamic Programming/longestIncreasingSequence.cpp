#include <iostream>
#include <algorithm>

using namespace std;
int sequence[100];
int arr[100];

int main(){
    int n, ans;
    cin >> n;
    for (int i = 0; i < n; ++i){
        cin >> sequence[i];
    }
    arr[0] = 1;
    for (int i = 1; i < n; ++i){
        for (int j = i; i >= 0; --j){
            if (sequence[j] < sequence[i]){
                arr[i] = arr[j] + 1;
                break;
            }
        }
    }
    // for (int i = 0; i < n; ++i) {
    //     cout << arr[i] << " ";
    // }
    ans = *max_element(arr, arr + n);
    cout << "Length of longest increasing sequence :: " << ans << endl;
    return 0;
}
