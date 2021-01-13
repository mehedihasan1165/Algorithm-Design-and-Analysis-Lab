#include <iostream>

void hamiltonCycle(int startNode, int depth);

void hamiltonPath();

using namespace std;
int adjMat[100][100], visited[100], path[100];
int node, start;

int main(){
    //4 6 1 2 1 4 2 1 2 4 4 3 3 2
    int edge, startNode, endNode;
    cin >> node >> edge;
    for (int i = 0; i < edge; ++i){
        cin >> startNode >> endNode;
        adjMat[startNode][endNode] = 1;
    }
    start = 3;
    path[0] = start;
    hamiltonCycle(start, 0);

    return 0;
}

void hamiltonCycle(int startNode, int depth){
    if (visited[start] == 1){
        if (depth == node){
            cout << "Hamilton cycle Found" << endl;
            hamiltonPath();
            return;
        }
        else{
            return;
        }
    }
    for (int i = 1; i <= node; ++i){
        if (adjMat[startNode][i] == 1 && visited[i] == 0){
            visited[i] = 1;
            path[depth + 1] = i;
            hamiltonCycle(i, depth + 1);
            visited[i] = 0;
        }
    }
}

void hamiltonPath(){
    cout << "Path :: ";
    for (int i = 0; i < node; ++i){
        cout << path[i] << " -> ";
    }
    cout << path[0];
}
