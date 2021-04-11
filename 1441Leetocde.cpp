#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<string> buildArray(vector<int>& target, int n) {
        
        vector<string> buildArray;
        int j=1;
        
        for(int i = 0 ; i<target.size() ;)
        {
            if(target[i] == j)
            {
                j++;
                buildArray.push_back("Push");
                i++;
            }
            else
            {
                j++;
                buildArray.push_back("Push");
                buildArray.push_back("Pop");
            }
        }
        
        
        return buildArray;
    }
};

int main()
{
    Solution obj;
    vector<int> ar;
    ar.push_back(1);
    ar.push_back(2);
    ar.push_back(3);
    ar.push_back(5);
    vector<string>answer = obj.buildArray(ar,5);
    return 0;
}