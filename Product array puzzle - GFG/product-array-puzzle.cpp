// { Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;



 // } Driver Code Ends
//User function template for C++

class Solution{
  public:
    vector<long long int> productExceptSelf(vector<long long int>& nums, int n) {
       vector<long long int> pref(n, 0);
       vector<long long int> suff(n, 0);
       vector<long long int>hash;
       if(n == 1){
           hash.push_back(1);
           return hash;
       }
       pref[0] = nums[0];
       suff[n-1] = nums[n-1];
       for(int i=1;i<n; i++){
           pref[i] = pref[i-1]*nums[i];
           suff[n-i-1] = suff[n-i]*nums[n-i-1];
       }
       for(int i=0; i<n; i++){
           if(i == 0){
               hash.push_back(suff[i+1]);
           }
           else if(i == n-1){
               hash.push_back(pref[i-1]);
           }
           else{
               hash.push_back(pref[i-1]*suff[i+1]);
           }
       }
       return hash;
    }
};


// { Driver Code Starts.
int main()
 {
    int t;  // number of test cases
    cin>>t;
    while(t--)
    {
        int n;  // size of the array
        cin>>n;
        vector<long long int> arr(n),vec(n);
        
        for(int i=0;i<n;i++)    // input the array
        {
            cin>>arr[i];
        }
        Solution obj;
        vec = obj.productExceptSelf(arr,n);   // function call
        
        for(int i=0;i<n;i++)    // print the output
        {
            cout << vec[i] << " ";
        }
        cout<<endl;
    }
	return 0;
}  // } Driver Code Ends