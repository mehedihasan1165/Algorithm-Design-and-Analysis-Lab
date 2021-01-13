#include <iostream>
#include <string.h>
using namespace std;

int main(){
    char text[] = "AABAACAADAABAAABAA";
    char pat[] = "AAB";
    int n = strlen(text);
    int m = strlen(pat);
    for (int i = 0; i < n - m; i++){
        int j;
        for (j = 0; j < m; j++){
            if (text[i + j] != pat[j]){
                break;
            }
        }
        if (j == m){
            cout << "Pattern found at index :: " << i << endl;
        }
    }
    return 0;
}
