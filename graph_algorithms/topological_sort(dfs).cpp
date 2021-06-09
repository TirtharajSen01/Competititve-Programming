#include<iostream>
#include<bits/stdc++.h>
// here we are considering the starting node from 0 
using namespace std;
class Solution{
void findTopo(int node , vector<int> &vis , stack<int> &s , vector<int> adj[])
{
    vis[node] = 1;
    for(auto child : adj[node])
    {
        if(vis[child] == 0)
        findTopo(child , vis , s , adj);
    }

    s.push(node); //This is what is different from the normal dfs code just after reccursion gets over each time add the node to the stack
}
public:
vector<int> topoSort(int N , vector<int> adj[])
{
    stack<int> s;
    vector<int> vis(N, 0);  //Visited array

    for(int i = 0 ; i< N ;i++)
    {
        if( vis[i] == 0)
        {
            findTopo(i , vis , s , adj); //This is actually simple dfs.
        }
    }

    vector<int> ans;
    while(!s.empty()) //we have now to just push the elements of the stack to the vector as we cant return stack
    {
        ans.push_back(s.top());
        s.pop();
    }
    return ans;
}

};
vector<int> adj[10001];
int main()
{
    int n , e;
    
    cout<<"Enter the nodes and the edges"<<endl;
    cin>>n>>e;
    cout<<"Enter the adjecency matrix"<<endl;
    while(e--)
    {
        int u , v;
        cin>>u>>v;
        adj[u].push_back(v);
    }

    Solution sol;
    vector<int> finalSorted = sol.topoSort(n , adj);

    for(int i = 0 ; i<finalSorted.size(); i++)
    cout<<finalSorted[i]<<" ";
    
    cout<<endl;

    return 0;
}