#include<bits/stdc++.h>
using namespace std;
void merge(int [], int , int , int , int);
void merge_sort(int a[] , int l , int h)
{
    if(l<h)
    {
        int mid = (l+h)/2;
        cout<<"l="<<l<<"mid="<<mid<<"h="<<h<<endl;
        merge_sort(a, l , mid);
        cout<<"After first"<<endl;
        cout<<"l="<<l<<"mid="<<mid<<"h="<<h<<endl;
        merge_sort(a , mid+1 , h);
        cout<<"After second"<<endl;
        cout<<"l="<<l<<"mid="<<mid<<"h="<<h<<endl;
        merge(a , l, mid , mid+1 , h);
        cout<<"After merge"<<endl;
        cout<<"l="<<l<<"mid="<<mid<<"h="<<h<<endl;
    }
}
void merge(int a[] , int l1 , int h1, int l2  , int h2)
{

    cout<<"In the merge function"<<endl;
}
int main()
{
    int n;
    cout<<"Enter number of elements";
    cin>>n;
    int arr[n];
    for(int i = 0 ; i <n ;i++)
    cin>>arr[i];
    cout<<"inside the main programme is starting here"<<endl;
    merge_sort(arr , 0 , n-1);
    cout<<"after the sorting again in the main at last of the programme"<<endl;
    for(int i = 0 ; i< n ; i++)
    cout<<arr[i]<<" ";
    cout<<endl;

    return 0;
}