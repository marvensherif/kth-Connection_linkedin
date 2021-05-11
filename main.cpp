#include <iostream>
#include <bits/stdc++.h>
using namespace std;
vector<int> adjacencyList[100000];

void addEdge(vector<int>adj[],int firstNode,int secondNode)
{
    adj[firstNode].push_back(secondNode);
    adj[secondNode].push_back(firstNode);
}

void BFS(int startingVertex,int numberOfVertex,int distance)
{
    int level[100000],visted[numberOfVertex],counter=0;
    for(int i=0; i<=numberOfVertex; i++)
    {
        level[i]=0;
        visted[i]=0;
    }
    queue<int>q;
    q.push(startingVertex);
    visted[startingVertex]=1;

    while(!q.empty())
    {
        int currentNode=q.front();
        q.pop();
        for(int child:adjacencyList[currentNode])
        {
            if(visted[child]==0)
            {
                level[child]=level[currentNode]+1;
                q.push(child);
                visted[child]=1;
                if(level[child]==distance)
                {
                    counter++;
                }

            }
        }

    }
    cout<<"There Are "<<counter<<" People With "<<distance<<" Connections Away Starting From "<<startingVertex;
}
int main()
{
    int numberOfVertex;
    int numberOfEdges;
    int firstEdge;
    int secondEdge;
    int startingVertex;
    int distance;
    cout<<"please enter number of vertex : ";
    cin>>numberOfVertex;
    cout<<"please enter number of edges : ";
    cin>>numberOfEdges;
    for(int i=1; i<=numberOfEdges; i++)
    {
        cout<<"please enter the "<<i<<" edge in form of (u v) : ";
        cin>>firstEdge>>secondEdge;
        addEdge(adjacencyList,firstEdge,secondEdge);
    }
    cout<<"please enter starting vertex : ";
    cin>>startingVertex;
    cout<<"please enter distance : ";
    cin>>distance;

    BFS(startingVertex,numberOfVertex,distance);

    return 0;
}
