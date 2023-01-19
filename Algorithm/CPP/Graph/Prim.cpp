#include <stdio.h>
#include <iostream>

using namespace std;

#define INT_MAX 999
#define VerticiesCount 5

int getMin(int wei[], bool mstSet[]){
    int minCost = INT_MAX;
    int minIndex;
    
    for(int a=0; a<VerticiesCount; a++)
    {
        if(mstSet[a] == false && wei[a]<minCost){
            minCost = wei[a];
            minIndex = a;
        }
    }
    return minIndex;
}

void PrintGraph(int parent[], int graph[VerticiesCount][VerticiesCount]);
int CostOfTree(int parent[], int graph[VerticiesCount][VerticiesCount]);

void Prim(int graph[VerticiesCount][VerticiesCount]){
    int parent[VerticiesCount];
    int wei[VerticiesCount];
    bool mstSet[VerticiesCount];
    
    for(int a=0; a<VerticiesCount; a++)
    {
        wei[a] = INT_MAX;
        mstSet[a] = false;
    }
    
    wei[0] = 0;
    parent[0] = -1;
    
    for(int a=0; a<VerticiesCount; a++)
    {
        int currentNode = getMin(wei, mstSet);
        mstSet[currentNode] = true;
        
        for(int i=0; i<VerticiesCount; i++){
            if(graph[currentNode][i] && mstSet[i] == false && graph[currentNode][i]<wei[i]){
                wei[i] = graph[currentNode][i];
                parent[i] = currentNode;
                
            }
        }
    }
    
    PrintGraph(parent, graph);
    cout << "\nCost Of Tree : " << CostOfTree(parent, graph);
}

void PrintGraph(int parent[], int graph[VerticiesCount][VerticiesCount])
{
    cout << "Edge\t|\tWeight" << endl;
    for(int a=1; a<VerticiesCount; a++){
        cout << parent[a] << "-" << a << "\t|\t" << graph[a][parent[a]] << endl;
    }
}

int CostOfTree(int parent[], int graph[VerticiesCount][VerticiesCount])
{
    int cost = 0;
    for(int a=1; a<VerticiesCount; a++)
        cost += graph[a][parent[a]];
    
    return cost;
}

int main()
{
    int myGraph[VerticiesCount][VerticiesCount] = {
        {0, 2, 0, 3, 7},
        {2, 0, 1, 6, 0},
        {0, 1, 0, 6, 1},
        {3, 6, 6, 0, 3},
        {7, 0, 1, 3, 0}
    };
    
    Prim(myGraph);

    return 0;
}
