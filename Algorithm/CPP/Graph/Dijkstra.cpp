#include <stdio.h>
#include <iostream>

using namespace std;

#define INT_MAX 999
#define VerticiesCount 9

int getMin(int wei[], bool mstSet[])
{
    int minCost = INT_MAX;
    int minIndex;
    
    for(int a=0; a<VerticiesCount; a++)
    {
        if(wei[a]<minCost && mstSet[a]==false){
            minCost=wei[a];
            minIndex = a;
        }
    }
    return minIndex;
}

void PrintGraph(int wei[], int graph[VerticiesCount][VerticiesCount]);

void Dijkstra(int graph[VerticiesCount][VerticiesCount]){
    int wei[VerticiesCount];
    bool mstSet[VerticiesCount];
    
    for(int a=0; a<VerticiesCount; a++)
    {
        wei[a] = INT_MAX;
        mstSet[a] = false;
    }
    
    wei[0] = 0;
    
    for(int a=0; a<VerticiesCount; a++)
    {
        int currentNode = getMin(wei, mstSet);
        mstSet[currentNode] = true;
        
        for(int i=0; i<VerticiesCount; i++){
            if(graph[currentNode][i] && mstSet[i] == false && graph[currentNode][i]+wei[currentNode] < wei[i])
             {
                 graph[currentNode][i] = wei[currentNode]+graph[currentNode][i];
                 graph[i][currentNode] = wei[currentNode]+graph[currentNode][i];
                 
                 wei[i] = graph[currentNode][i];
                 
             }
        }
    }
    PrintGraph(wei, graph);
}

void PrintGraph(int wei[], int graph[VerticiesCount][VerticiesCount])
{
    cout << "Vertex\t|\tDistanceFromStart" << endl;
    for(int a=1; a<VerticiesCount; a++){
        cout << a << "\t|\t" << wei[a] << endl;
    }
}

int main()
{
    int myGraph[VerticiesCount][VerticiesCount] =  {{0, 2, 0, 4, 0, 0, 7, 12, 0},{2, 0, 8, 0, 4, 0, 0, 10, 0},{0, 8, 0, 15, 1, 4, 0, 0, 2},{4, 0, 15, 0, 3, 14, 1, 0, 6},{0, 4, 1, 3, 0, 10, 0, 7, 8},{0, 0, 4, 14, 10, 0, 2, 0, 0},{7, 0, 0, 1, 0, 2, 0, 1, 6},{12,10, 0, 0, 7, 0, 1, 0, 3},{0, 0, 2, 0, 6, 8, 6, 3, 0}};
    
    Dijkstra(myGraph);

    return 0;
}
