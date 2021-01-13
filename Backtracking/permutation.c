#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char s[100], ans[100];
int n;

int main(){
    scanf("%s", &s);
    n = strlen(s);
    permutation(0);
    return 0;
}
void permutation(int count){
    if (count == n){
        printf("%s\n", ans);
        return;
    }
    for (int i = 0; i < n; i++){
        ans[count] = s[i];
        permutation(count + 1);
    }
    return;
}
