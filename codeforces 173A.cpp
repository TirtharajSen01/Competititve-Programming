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
 
void solve()
{
    //Try to learn 2 - pointer technique to solve this in better time 
    int n;
    cin>>n;
    int a[n];
    for(int i = 0 ; i<n ; i++)
        cin>>a[i];
    int m;
    cin>>m;
    int b[m];
    for(int j = 0 ;j <m;j++)
        cin>>b[j];
    sort(a , a+n);
    sort(b , b+m);
    int pair = 0;
    for(int i = 0; i<n ;i++)
    {
        for(int j = 0 ; j<m; j++)
        {
            if(abs(a[i]-b[j]) <= 1)
            {
                pair++;
                b[j] = INT_MAX;  //replace the matched pair with (inf) so that when again comes to check doesnt form a pair again
                break;
            }
        }
    }
 
    cout<<pair<<endl;
 
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
        //cerr<<"Time: "<<duration.count() / 1000.0<<endl;
        cout<<endl<<endl<<endl<<"Time: "<<duration.count()/1000.0<<endl;
    #endif
}