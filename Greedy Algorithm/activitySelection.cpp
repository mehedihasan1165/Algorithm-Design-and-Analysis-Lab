#include <iostream>
#include <algorithm>

typedef struct activity{
    int index, start, finish;
} act;
using namespace std;

int comp(act a, act b);

int main(){
    int n, ans = 1, prev = 1;
    act activities[1000];
    cin >> n;
    for (int i = 1; i <= n; ++i){
        cin >> activities[i].start >> activities[i].finish;
        activities[i].index = i;
    }
    sort(activities + 1, activities + n + 1, comp);
    cout << activities[1].index << "\t";
    for (int i = 2; i <= n; ++i){
        if (activities[i].start >= activities[prev].finish){
            cout << activities[i].index << "\t";
            ans += 1;
            prev = i;
        }
    }
    cout << "\nTotal activity done :: " << ans << endl;
    return 0;
}

int comp(act a, act b){
    int x = a.finish;
    int y = b.finish;
    return x < y;
}
