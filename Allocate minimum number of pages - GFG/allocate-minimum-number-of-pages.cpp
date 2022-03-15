// { Driver Code Starts
// Initial template for C++

#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function template in C++

class Solution 
{
    public:
    
    bool isPossible(int A[], int n, int m, int mid){
        int sum = 0;
        int cnt = 1;
        for(int i=0; i<n; i++){
            if(sum + A[i] > mid){
                cnt++;
                if(cnt > m or A[i] > mid){
                    return false;
                }
                sum = A[i];
            }else{
                sum += A[i];
            }
        }
        return true;
    }
    
    
    
    //Function to find minimum number of pages.
    int findPages(int A[], int N, int M) 
    {
        int sum = 0;
        for(int i=0; i<N; i++){
            sum += A[i];
        }
        int left = 0;
        int right = sum;
        int ans = -1;
        while(left <= right){
            int mid = (left + right)/2;
            if(isPossible(A, N, M, mid)){
                right = mid-1;
                ans = mid;
            }else{
                left = mid+1;
            }
        }
        return ans;
    }
};

// { Driver Code Starts.

int main() {
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int A[n];
        for(int i=0;i<n;i++){
            cin>>A[i];
        }
        int m;
        cin>>m;
        Solution ob;
        cout << ob.findPages(A, n, m) << endl;
    }
    return 0;
}
  // } Driver Code Ends