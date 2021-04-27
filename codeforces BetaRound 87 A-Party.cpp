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
#define vbb vector<ll>
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
 
int vis[2001];
vbb ar[2001];
int  dist[2001] = {0};
int c =1;
void dfs(int node,int d)
{
    //vis[node] = 1; // The problem here is that node 1 is not the root and its getting visited before the node 2 which is root so the problem is there that dfs(2) again does not traverse node 1
    //dist[node] = d;
 
    c = max(c ,d);
    for(int child : ar[node])
    {
        // if(vis[child] == 0)
            dfs(child , d + 1);
    }
}
 
void solve()
{
    int n , p;
    cin>>n;
 
    for(int i = 1 ; i<= n ; i++)
    {
        cin>>p;
        if(p != -1)
        {
            ar[p].pb(i);
        }
    }
 
    // for(int i = 0 ; i<=2001 ; i++) dist[i].pb(0);
    //dfs(1 , 0);
    for(int i=1 ; i<=n ; i++)
    {
            dfs(i , 1);
    }  
 
    // int m = INT_MIN;
    // for(int i = 1 ;i<=n; i++)
    // {
    //     cout<<dist[i]<<" "<<endl;
    //     if(dist[i]>m)
    //         m = dist[i];
    // }
 
    cout<<c;
}
 
int main(){
    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif
 
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    auto start1=high_resolution_clock::now();
    solve();
    //test(solve);
 
    auto stop1=high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop1 - start1);
    #ifndef ONLINE_JUDGE
        cerr<<"Time: "<<duration.count() / 1000.0<<endl;
        cout<<endl<<endl<<endl<<duration.count()/1000.0<<endl;
    #endif
}