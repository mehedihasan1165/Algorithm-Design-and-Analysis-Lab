#include <iostream>
#include <algorithm>

using namespace std;
int matrix[100][100], coins[100];

int main(){
    int n, target;
    cin >> n >> target;
    for (int i = 1; i <= n; ++i){
        cin >> coins[i];
    }
    for (int i = 0; i <= n; ++i){
        matrix[i][0] = 1;
    }
    for (int i = 1; i <= n; ++i){
        for (int j = 1; j <= target; ++j){
            if (j >= coins[i]){
                matrix[i][j] = matrix[i - 1][j] + matrix[i][j - coins[i]];
            }
            else{
                matrix[i][j] = matrix[i - 1][j];
            }
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
    cout << "Ways :: " << matrix[n][target] << endl;
    return 0;
}