// { Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


 // } Driver Code Ends
class Solution{
public:
    // m is maximum of number zeroes allowed to flip
    // n is size of array
    int findZeroes(int arr[], int n, int m) {
        int maxConsecutiveOne = 0 , start = 0 , zeroCount = 0;
       
       for(int end = 0; end < n; end++)
       {
           if(arr[end] == 0) zeroCount++;
           
           while(zeroCount > m)
           {
               if(arr[start] == 0)
                   zeroCount--;
                   
               start++;
           }
           
           maxConsecutiveOne = max(maxConsecutiveOne , end-start+1);
       }
       
       return maxConsecutiveOne;

    }  
};

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, i, m;
        cin >> n;
        int arr[n];
        for (i = 0; i < n; i++) {
            cin >> arr[i];
        }
        cin >> m;
        Solution ob;
        auto ans = ob.findZeroes(arr, n, m);
        cout << ans << "\n";
    }
    return 0;
}  // } Driver Code Ends