// { Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;
// int maxArea(int A[], int len);

 // } Driver Code Ends
//User function template for C++

long long maxArea(long long A[], int len)
{
    int left = 0;
    int right = len-1;
    int ans = 0;
    while(left < right){
        int m = min(A[left], A[right]);
        int l = right-left;
        ans = max(ans, m*l);
        if(A[left] < A[right]){
            left++;
        }else{
            right--;
        }
    }
    return ans;
}

// { Driver Code Starts.

// Driver code
int main()
{
	int t;
	cin>>t;
	while(t--)
    {
        int n;
        cin>>n;
        long long arr[n];
        for(int i=0;i<n;i++)
            cin>>arr[i];
        cout<<maxArea(arr,n)<<endl;
    }
return 0;
}
  // } Driver Code Ends