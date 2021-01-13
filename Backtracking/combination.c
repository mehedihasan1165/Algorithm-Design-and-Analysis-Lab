#include <stdio.h>
#include <stdlib.h>
#include <string.h>
char s[100], ans[100];
int n, r;
int main(){
    scanf("%s %d", &s, &r);
    n = strlen(s);
    ans[r] = '\0';
    combination(0, 0);
    return 0;
}
void combination(int chIndex, int takenIndex){
    if (takenIndex == r)
    {
        printf("%s\n", ans);
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
