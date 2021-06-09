#include<iostream>
#include<bits/stdc++.h>
using namespace std;
// This is the optimized algorithm using Priority Queue or Heap to find the minimum in the KEY array
// The time complexity of this algorithm is o(N) and for priority_queue o(log n) , adn for adj list O(n+e) . So total 
// O(n + e + n log n) 
int main()
{   
    int N , E;
    cin>>N>>E;
    vector<pair<int , int>> adj[N];

    int u , v , wt;
    for(int i = 0 ;i < E  ; i++)
    {
        cin>>u >> v >> wt;
        adj[u].push_back({v ,wt});
        adj[v].push_back({u ,wt});
    }

    int parent[N] ;
    int key[N] ; 
    bool mstSet[N];

    for(int  i = 0 ; i< N ; i++)
    mstSet[i] = false , key[i] = INT_MAX ;

    //Same code upto this part as the brute force . 

    priority_queue<pair<int , int>,  vector<pair<int , int>> ,  greater<pair<int , int>> > pq; //priority Queue stl order by the weight min on the top

    key[0] = 0;
    parent[0] = -1;
    pq.push({0 , 0});//push {key[i] (weight) , index value (node)} then we get the order according to the 
    for(int count = 0 ; count < N-1 ; count++)
    {
        int u  = pq.top().second; //the Key having minimum value that node is returned as top in the priority queue
        pq.pop();

        mstSet[u] = true; //this is visited

        //now traverse the adjecency list
        for(auto child : adj[u])
        {
            int v = child.first;
            int weight = child.second;

            if(mstSet[v] == false && key[v] > weight)
            {
                parent[v] = u; //initializing the parent;
                pq.push({key[v] , v});
                key[v] = weight;
            }
        }
    }
    
    cout<<"The minimum spanning tree: "<<endl;
    for(int i = 1 ; i<N ; i++)
    cout<<"parent: "<<parent[i]<<" - child: "<<i<<endl; //print as a pair the parent and the child
    
    return 0;
}