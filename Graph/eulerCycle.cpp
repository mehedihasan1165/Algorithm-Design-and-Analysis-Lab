#include <iostream>

using namespace std;
int n, m, con[100][100], maxPos, ans[100];
void eulerCycle(int node);
int main(){
    //input 5 6 0 1 1 2 2 0 1 3 3 4 4 1
    int i, a, b;
    cin >> n >> m;
    for (i = 0; i < m; i++){
        cin >> a >> b;
        con[a][b] = 1;
    }
    eulerCycle(0);
    for (i = maxPos - 1; i >= 0; i--){
        cout << ans[i] << " ";
    }
    return 0;
}
void eulerCycle(int node){
    int i;
    for (i = 0; i < n; i++){
        if (con[node][i] == 1){
            con[node][i] = 0;
            eulerCycle(i);
        }
    }
    ans[maxPos++] = node;
}
