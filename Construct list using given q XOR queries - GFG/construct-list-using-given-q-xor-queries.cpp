// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function Template for C++

class Solution {
  public:
    vector<int> constructList(vector<vector<int>> Q, int N) {
        vector<int> res{0};
        stack<pair<int, int>> mask;
        for(auto q: Q)
        {
            if(q[0]==0)
            {
                res.push_back(q[1]);
            }
            else
            {
                mask.push({res.size(), q[1]});
            }
        }
        int m = 0;
        for(int i=res.size()-1; i>=0; i--)
        {
            while(!mask.empty() && i<mask.top().first)
            {
                m ^= mask.top().second;
                mask.pop();
            }
            
            res[i] ^= m;
        }
        
        sort(res.begin(), res.end());
        return res;
    }
};

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N,type,val;
        cin>>N;
        
        vector<vector<int>> Q;
        
        for(int i=0; i<N; i++)
        {
            cin>>type>>val;
            vector<int> temp;
            temp.push_back(type);
            temp.push_back(val);
            Q.push_back(temp);
        }

        Solution ob;
        vector<int> res = ob.constructList(Q,N);
        
        for(int i=0; i<res.size(); i++)
            cout<<res[i]<<" ";
        cout<<endl;
    }
    return 0;
}  // } Driver Code Ends