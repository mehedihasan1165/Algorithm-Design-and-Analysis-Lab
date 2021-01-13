#include <iostream>

#define n 8
using namespace std;
int grid[n][n];
int sol = 0;

void display(){
    for (int i = 0; i < n; ++i){
        for (int j = 0; j < n; ++j){
            cout << grid[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
    sol++;
}

bool isSafe(int grid[n][n], int row, int column){
    for (int i = 0; i < column; i++){
        if (grid[row][i]){
            return false;
        }
    }
    for (int i = row, j = column; i >= 0 && j >= 0; i--, j--){
        if (grid[i][j]){
            return false;
        }
    }
    for (int i = row, j = column; j >= 0 && i < n; i++, j--){
        if (grid[i][j]){
            return false;
        }
    }
    return true;
}

void solve(int grid[n][n], int column){
    if (column >= n){
        display();
        return;
    }
    for (int i = 0; i < n; ++i){
        if (isSafe(grid, i, column)){
            grid[i][column] = 1;
            solve(grid, column + 1);
            grid[i][column] = 0;
        }
    }
}

int main(){
    solve(grid, 0);
    cout << "Total solution :: " << sol << endl;
    return 0;
}
