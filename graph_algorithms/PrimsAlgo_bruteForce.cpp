#include<iostream>
#include<bits/stdc++.h>
using namespace std;
// This is the brute force approach whose time complexity is greater than O(n^2) . not an efficient algorithm
int main()
{
    int N , E ; //node and edges.
    cin>>N>>E;
    vector<pair<int , int>>adj[N]; //adjecency matrix to store the weighted graph
    
    int u , v , wt;

    for(int i = 0 ; i<E ; i++) //Making the weighted graph
    {
        cin>>u>>v>>wt;
        adj[u].push_back({v , wt});
        adj[v].push_back({u , wt});
    }

    //Three different arrays as required by the prims algorithm
    int key[N];
    bool mstSet[N];
    int parent[N];

    for(int i = 0 ; i< N ; i++)  //initializing all the array
        mstSet[i] = false, key[i] = INT_MAX, parent[i] = -1;

    key[0] = 0; //Setting the starting node as 0 as in the algorithm;
    parent[0] = -1;
    for(int count = 0 ; count< N-1 ; count++) // iteration for N-1 edges.
    {
        int minKey = INT_MAX , u;
        for(int v = 0 ; v<N ; v++) //traversing for the minimum key in the key array
        {
            if(key[v]<minKey && mstSet[v] == false)
            minKey = key[v] , u = v; // u = v is done to store the parent node that fulfills the conditions
        }

        mstSet[u] = true; //make the nodes mst true as it has been visited

        //traverse the adjecency list as per the algorithm
        for(auto child : adj[u])
        {
            int v = child.first; //the node of the child
            int weight = child.second; // the weight of the child node
            if(mstSet[v] == false && weight < key[v])
            parent[v] = u , key[v] = weight; //update the parent of all the nodes and also if weight < the previous stored weight change the weight to the new but lesser one
        }
    }
    cout<<"The minimum spanning tree: "<<endl;
    for(int i = 1 ; i<N ; i++)
    cout<<"parent: "<<parent[i]<<" - child: "<<i<<endl; //print as a pair the parent and the child

    return 0;
}