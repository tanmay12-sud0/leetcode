// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends


class Solution
{
    public:
    string reverseWords(string S) 
    { 
        S.push_back('.');
        vector<string>ss;
        string tan;
        for(int i=0; i<S.length(); i++){
            if(S[i] == '.'){
                ss.push_back(tan);
                tan.clear();
                continue;
            }
            tan += S[i];
        }
        reverse(ss.begin(), ss.end());
        string a;
        for(auto x : ss){
            a += x;
            a += '.';
        }
        a.pop_back();
        return a;
    } 
};

// { Driver Code Starts.
int main() 
{
    int t;
    cin >> t;
    while (t--) 
    {
        string s;
        cin >> s;
        Solution obj;
        cout<<obj.reverseWords(s)<<endl;
    }
}  // } Driver Code Ends