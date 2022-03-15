// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

  

 // } Driver Code Ends
// Function to find square root
// x: element to find square root
class Solution{
  public:
  
    bool solve(long long int mid, int x){
        if(mid*mid <= x){
            return true;
        }
        return false;
    }
  
  
  
    long long int floorSqrt(long long int x) 
    {
        int left = 1;
        int right = x;
        int ans = -1;
        while(left <= right){
            long long int mid = (left + right)/2;
            if(solve(mid, x)){
                ans = mid;
                left = mid+1;
            }
            else{
                right = mid-1;
            }
        }
        return ans;
    }
};

// { Driver Code Starts.

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		long long n;
		cin>>n;
		Solution obj;
		cout << obj.floorSqrt(n) << endl;
	}
    return 0;   
}
  // } Driver Code Ends