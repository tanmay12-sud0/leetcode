// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution{
    public:

    bool find3Numbers(int A[], int n, int X)
    {
    sort(A, A+n);
    for(int i=0; i<n-2; i++){
        int left = i+1;
        int right = n-1;
        while(left < right){
            int sum = A[left] + A[right] + A[i];
            if(sum == X){
                return true;
            }
            if(sum > X){
                right--;
            }else{
                left++;
            }
        }
    }
    return false;
    }

};

// { Driver Code Starts.

int main()
{
	int T;
	cin>>T;
	while(T--)
	{
		int n,X;
		cin>>n>>X;
		int i,A[n];
		for(i=0;i<n;i++)
			cin>>A[i];
		Solution ob;
        cout <<  ob.find3Numbers(A, n, X) << endl;
    }
}
  // } Driver Code Ends