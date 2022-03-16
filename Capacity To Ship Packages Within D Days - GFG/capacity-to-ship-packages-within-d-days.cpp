// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function Template for C++

class Solution {
  public:
  
  bool help(int arr[],int n,int D,int capacity)
    {
        int day = 1;
        int sum=0;
         for(int i=0;i<n;i++)
         {
             sum += arr[i];
             if(sum>capacity)
             {
                 day++;
                 sum = arr[i];
             }
         }
         
         if(day<=D)
         {
             return true;
         }
         else
         {
             return false;
         }
    }
    int leastWeightCapacity(int arr[], int n, int D) {
        
        int sum=0;
        for(int i=0;i<n;i++)
        {
            sum+=arr[i];
        }
        int maxx = *max_element(arr,arr+n);
        
        int low = maxx;
        int high = sum;
        int ans =0;
        while(high>=low)
        {
            int mid = (low + high)/2;
            
            if(help(arr,n,D,mid))
            {
                ans = mid;
                high = mid-1;
            }
            else
            {
                low = mid+1;
            }
        }
        return ans;
    }
    
};

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N,D;
        cin>>N;
        
        int arr[N];
        for(int i=0; i<N; i++)
            cin>>arr[i];
        cin>>D;

        Solution ob;
        cout << ob.leastWeightCapacity(arr,N,D) << endl;
    }
    return 0;
}  // } Driver Code Ends