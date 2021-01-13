#include <iostream>
#include <algorithm>

using namespace std;
typedef struct job{
    int id, deadline, profit;
} job;

int comp(job a, job b);

int main(){
    int n, profit = 0;
    job jobs[100];
    bool slot[100];
    int result[100];
    cin >> n;
    for (int i = 0; i < n; ++i){
        cin >> jobs[i].deadline >> jobs[i].profit;
        jobs[i].id = i + 1;
    }
    sort(jobs, jobs + n, comp);
    for (int i = 0; i < n; ++i){
        for (int j = jobs[i].deadline - 1; j >= 0; --j){
            if (!slot[j]){
                slot[j] = true;
                result[j] = i;
                // cout << jobs[i].id << "\t";
                profit += jobs[i].profit;
                break;
            }
        }
    }
    cout << "Total profit :: " << profit << endl;
    cout << "Job sequence :: ";
    for (int i = 0; i < n; i++){
        if (slot[i]){
            cout << jobs[result[i]].id << " ";
        }
    }
    return 0;
}

int comp(job a, job b){
    return a.profit > b.profit;
}
