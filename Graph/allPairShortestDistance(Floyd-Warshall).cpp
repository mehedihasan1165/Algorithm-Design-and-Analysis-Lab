#include <iostream>
#include <algorithm>
#define inf 99999

using namespace std;

int matrix[100][100];
int main(){
    int node, edge, start, finish, temp;
    cin >> node >> edge;
    //matrix initializations
    for (int i = 1; i <= node; ++i){
        for (int j = 1; j <= node; ++j){
            matrix[i][j] = inf;
        }
        matrix[i][i] = 0;
    }
    //input
    //5 8 1 2 4 1 4 3 1 3 10 2 4 1 2 5 3 4 3 7 4 5 1 5 3 1
    for (int i = 0; i < edge; ++i){
        cin >> start >> finish >> temp;
        matrix[start][finish] = temp;
    }
    for (int k = 1; k <= node; ++k){
        cout << "\nWorking node :: " << k << endl<< endl;
        for (int i = 1; i <= node; ++i){
            for (int j = 1; j <= node; ++j){
                matrix[i][j] = min(matrix[i][j], matrix[i][k] + matrix[k][j]);
                cout << matrix[i][j] << "\t";
            }
            cout << endl;
        }
    }
    return 0;
}
