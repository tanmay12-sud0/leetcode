// { Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function template for C++

class Solution{   
public:
    long long findgroups(int a[], int n) {
        long long C[3]={0};
        long long res=0;
        for(int i=0;i<n;i++)
            C[a[i]%3]++;
        if(C[0]>=2) res+=C[0]*(C[0]-1)/2;
        if(C[1]>=1 && C[2]>=1) res+=C[1]*C[2];
        if(C[0]>=3) res+=C[0]*(C[0]-1)*(C[0]-2)/6;
        if(C[1]>=3) res+=C[1]*(C[1]-1)*(C[1]-2)/6;
        if(C[2]>=3) res+=C[2]*(C[2]-1)*(C[2]-2)/6;
        if(C[1]>=1 && C[2]>=1 && C[0]>=1)
            res+=C[0]*C[1]*C[2];
        return res;

    }
};

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.findgroups(arr, n);
        cout << ans << "\n";
    }
    return 0;
}  // } Driver Code Ends