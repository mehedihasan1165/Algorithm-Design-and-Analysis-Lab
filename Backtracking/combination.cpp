#include <iostream>
#include <string.h>

void combination(int chIndex, int takenIndex);

using namespace std;
char s[100], ans[100];
int n, r;

int main(){
    cin >> s >> r;
    n = strlen(s);
    ans[r] = '\0';
    combination(0, 0);
    return 0;
}

void combination(int chIndex, int takenIndex){
    if (takenIndex == r)
    {
        cout << ans << endl;
        return;
    }
    if (chIndex == n)
    {
        return;
    }
    ans[takenIndex] = s[chIndex];
    combination(chIndex + 1, takenIndex + 1);
    combination(chIndex + 1, takenIndex);
}
