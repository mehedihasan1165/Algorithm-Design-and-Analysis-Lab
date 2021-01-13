#include <iostream>
#include <algorithm>

typedef struct item{
    double value, weight;
} item;

int comp(item a, item b);

using namespace std;

int main(){
    int n, w, remainingWeight;
    item items[100];
    cin >> n >> w;
    for (int i = 0; i < n; ++i){
        cin >> items[i].value >> items[i].weight;
    }
    sort(items, items + n, comp);
    remainingWeight = w;
    double totalProfit = 0;
    for (int i = 0; i < n; ++i){
        if (items[i].weight <= remainingWeight){
            totalProfit += items[i].value;
            remainingWeight -= items[i].weight;
        }
        else{
            totalProfit += (items[i].value / items[i].weight) * remainingWeight;
            break;
        }
    }
    cout << "Maximum profit for " << w << " is " << totalProfit << endl;
    return 0;
}

int comp(item a, item b){
    double x = a.value / a.weight;
    double y = b.value / b.weight;
    return x > y;
}
