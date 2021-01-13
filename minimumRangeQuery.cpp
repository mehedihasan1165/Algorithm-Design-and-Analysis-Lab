#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;
int squareRootDecomposition(int start, int finish);
int sequence[100], n;
int main(){
    cin >> n; //16  7 8 9 10 5 7 11 9 13 21 18 11 9 13 21 18 11 3 19 20 2
    for (int i = 0; i < n; ++i){
        cin >> sequence[i];
    }
    squareRootDecomposition(0, 1);
    return 0;
}
int squareRootDecomposition(int start, int finish){
    int block = sqrt(n), j = 0;
    int arr[100];
    for (int i = 0; i < n; ++i){
        if (i % block == 0){
            arr[j] = *min_element(sequence + i, sequence + i + block);
            j++;
            i = i + block;
        }
        else{
            arr[j] = sequence[i];
            j++;
        }
    }
    for (int i = 0; i < j; ++i){
        cout << arr[i] << "\t";
    }
    return 0;
}