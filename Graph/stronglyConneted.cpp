#include <iostream>
using namespace std;
int n, m, conn[100][100], reverseCon[100][100], visit[100], finishing[100], pos;
void storeAsFinishingTime(int node);
void dfs(int node);
int main(){
    // input 7 8 1 2 2 3 3 1 3 4 4 5 5 6 6 7 7 5
    int a, b, x, ans = 0;
    cin >> n >> m;
    for (int i = 0; i < m; i++){
        cin >> a >> b;
        conn[a][b] = 1;
        reverseCon[b][a] = 1;
    }
    for (int i = 1; i <= n; i++){
        if (visit[i] == 0){
            storeAsFinishingTime(i);
        }
    }
    for (int i = 1; i <= n; i++){
        visit[i] = 0;
    }
    while (pos > 0){
        int i = finishing[pos - 1];
        x = i;
        if (visit[x] == 0){
            ++ans;
            dfs(i);
        }
        pos--;
    }
    cout << "Ans:: " << ans << endl;
    return 0;
}
void storeAsFinishingTime(int node){
    visit[node] = 1;
    for (int i = 1; i <= n; i++){
        if (conn[node][i] == 1 && visit[i] == 0){
            storeAsFinishingTime(i);
        }
    }
    finishing[pos++] = node;
}
void dfs(int node){
    visit[node] = 1;
    for (int i = 1; i <= n; ++i){
        if (reverseCon[node][i] == 1 && visit[i] == 0){
            dfs(i);
        }
    }
}
