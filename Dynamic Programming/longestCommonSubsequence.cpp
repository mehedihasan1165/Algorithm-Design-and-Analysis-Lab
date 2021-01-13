#include <iostream>
#include <string.h>

using namespace std;
char string1[100], string2[100];
int table[100][100];

int main(){
    cin >> string1 >> string2;
    int len1 = strlen(string1), len2 = strlen(string2);
    for (int i = 0; i <= len1; ++i){
        for (int j = 0; j <= len2; ++j){
            if (i == 0 || j == 0){
                table[i][j] = 0;
            }
            else{
                if (string1[i - 1] == string2[j - 1]){
                    table[i][j] = table[i - 1][j - 1] + 1;
                }
                else{
                    table[i][j] = max(table[i - 1][j], table[i][j - 1]);
                }
            }
            // cout << table[i][j] << "\t";
        }
        // cout << endl;
    }
    cout << "Length of longest common subsequence :: " << table[len1][len2] << endl;
    return 0;
}
