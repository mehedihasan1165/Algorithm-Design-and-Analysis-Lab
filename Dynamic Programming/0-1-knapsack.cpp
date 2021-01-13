#include <iostream>
#include <algorithm>

using namespace std;

int matrix[100][100], weight[100], value[100];

int main(){
    int n, w;
    cin >> n >> w;
    for (int i = 1; i <= n; ++i){
        cin >> value[i] >> weight[i];
    }
    for (int i = 1; i <= n; ++i){
        for (int j = 1; j <= w; ++j){
            if (j >= weight[i]){
                matrix[i][j] = max(value[i] + matrix[i - 1][j - weight[i]], matrix[i - 1][j]);
            }
            else{
                matrix[i][j] = matrix[i - 1][j];
            }
            cout << matrix[i][j] << "\t";
        }
        cout << endl;
    }
    cout << "Total Profit :: " << matrix[n][w];
    return 0;
}
