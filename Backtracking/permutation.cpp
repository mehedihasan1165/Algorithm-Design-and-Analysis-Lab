#include <iostream>
#include <string.h>

void permutation(int count);

using namespace std;
char s[100], ans[100];
int n;

int main(){
    cin >> s;
    n = strlen(s);
    permutation(0);
    return 0;
}

void permutation(int count){
    if (count == n){
        cout << ans << endl;
        return;
    }
    for (int i = 0; i < n; i++){
        ans[count] = s[i];
        permutation(count + 1);
    }
}
