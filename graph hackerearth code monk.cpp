//  ########  ########  ########  ########  ########   ######    ######   ########  ########    //
//  #      #  #      #  #      #  #         #         #      #  #      #  #      #  #      #    //
//  #      #  #      #  #      #  #         #         #         #         #      #  #      #    //
//  #      #  #      #  #      #  #         #          #         #        #      #  #      #    //
//  ########  ########  #      #  #####     #####       ####      ####    #      #  ########    //
//  #         ##        #      #  #         #               #         #   #      #  ##          //
//  #         #  #      #      #  #         #                #         #  #      #  #  #        //
//  #         #    #    #      #  #         #         #      #  #      #  #      #  #    #      //
//  #         #      #  ########  #         ########   ######    ######   ########  #      #    //
#include<iostream>
#include<algorithm>
#include<vector>
#include<chrono>
#include<bits/stdc++.h>
#define vpp vector<pp>
#define vll vector<ll>
#define endl "\n"
#define vbb vector<int>
#define w(t) while(t--)
#define pp pair<ll, ll>
#define test(x) ll t;cin>>t; w(t) x()
#define __lb lower_bound
#define __up upper_bound
#define szs(x) x.length()
#define szv(x) x.size()
#define ll long long int
#define takeINP(arr,n) for(long long int i=0;i<n;i++) cin>>arr[i];
#define f(i,s,e) for(long long int i=s;i<e;i++)
#define bf(i,s,e) for(long long int i=s-1; i>=e;i--)
#define rsz(s,n) x.resize(n)
#define rsr(x,n) x.reserve(n)
#define mp(a,b) make_pair(a,b)
#define pb push_back
#define print(arr,s,e) f(i,s,e) cout<<arr[i]<<" ";cout<<endl;
#define all(v) v.begin(),v.end()
#define ff first
#define ss second
#define triplet pair<ll,pair<ll,ll>>
#define MITR(a,b) map<a,b>:: reverse_iterator
#define N 1000000
#define mod 1000000007
using namespace std;
using namespace chrono;

vector<int> ar[10001];
int vis[10001], dist[10001];
void bfs(int node) //remember this is not the reccursion as in case of dfs
{
    queue<int> q;
    q.push(node);

    vis[node] = 1;
    dist[node] = 0; //so as this is not a reccursive function so always the node is the root or the source node

    while(!q.empty())
    {
        int cur = q.front();
        q.pop();

        for(int child : ar[cur]) //This is the critical part in dfs here is node but here it is cur
        {
            if(vis[child] == 0)
            {
                q.push(child);
                dist[child] = dist[cur]+1;
                vis[child] = 1;
            }
        }
    }
}

void solve()
{
    int n , m , u , v;
    cin>>n>>m;
    for(int i = 1 ;i<=n ; i++) ar[i].clear(), vis[i] = 0; //This is also important and 1-n is important and 0-n-1 will be wrong 
    for(int i = 0 ;i < m ;i++)
    {
        cin>>u>>v;
        ar[u].pb(v);
        ar[v].pb(u);
    }

    bfs(1);
    
    cout<<dist[n]<<endl;
}

int main(){
    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    auto start1=high_resolution_clock::now();
    //solve();
    test(solve);

    auto stop1=high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop1 - start1);
    #ifndef ONLINE_JUDGE
        //cerr<<"Time: "<<duration.count() / 1000.0<<endl;
        cout<<endl<<endl<<endl<<"Time: "<<duration.count()/1000.0<<endl;
    #endif
}
