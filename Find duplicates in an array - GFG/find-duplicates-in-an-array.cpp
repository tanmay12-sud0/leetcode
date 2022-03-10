// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{
  public:
    vector<int> duplicates(int arr[], int n) {
         int a[n];
       vector<int>b;
       int j=0;
       for(int i=0;i<n;i++){
           a[i]={0};
       }
       for(int i=0;i<n;i++){
           a[arr[i]]+=1;
        }
        for(int i=0;i<n;i++){
            if(a[i]>1)
             b.push_back(i);
        }
       if(b.size()==0)
        b.push_back(-1);
      return b;
    }
};


// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t-- > 0) {
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++) cin >> a[i];
        Solution obj;
        vector<int> ans = obj.duplicates(a, n);
        for (int i : ans) cout << i << ' ';
        cout << endl;
    }
    return 0;
}
  // } Driver Code Ends