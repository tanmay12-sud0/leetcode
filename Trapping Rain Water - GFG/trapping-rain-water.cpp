// { Driver Code Starts
#include<bits/stdc++.h>

using namespace std;


 // } Driver Code Ends
class Solution{

    // Function to find the trapped water between the blocks.
    public:
    long long trappingWater(int arr[], int n){
        vector<int>pref(n, 0);
        vector<int>suff(n, 0);
        pref[0] = arr[0];
        suff[n-1] = arr[n-1];
        for(int i=1; i<n; i++){
            pref[i] = max(pref[i-1], arr[i]);
            suff[n-i-1] = max(arr[n-1-i], suff[n-i]);
        }
        long long total = 0;
        for(int i=0; i<n; i++){
            total += min(pref[i], suff[i])-arr[i];
        }
        return total;
    }
};

// { Driver Code Starts.

int main(){
    
    int t;
    //testcases
    cin >> t;
    
    while(t--){
        int n;
        
        //size of array
        cin >> n;
        
        int a[n];
        
        //adding elements to the array
        for(int i =0;i<n;i++){
            cin >> a[i];            
        }
        Solution obj;
        //calling trappingWater() function
        cout << obj.trappingWater(a, n) << endl;
        
    }
    
    return 0;
}  // } Driver Code Ends