// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution{
  public:
    // arr[] : the input array
    // N : size of the array arr[]
    
    //Function to return length of longest subsequence of consecutive integers.
    int findLongestConseqSubseq(int arr[], int N)
    {
      set<int>hash;
      for(int i=0; i<N; i++){
          hash.insert(arr[i]);
      }
      int cnt = 0;
      int max_so_far = INT_MIN;
      for(int i=0; i<100005; i++){
          if(hash.count(i)){
              cnt++;
          }else{
              max_so_far = max(max_so_far, cnt);
              cnt = 0;
          }
      }
      return max_so_far;
    }
};

// { Driver Code Starts.
 
// Driver program
int main()
{
 int  t,n,i,a[100001];
 cin>>t;
 while(t--)
 {
  cin>>n;
  for(i=0;i<n;i++)
  cin>>a[i];
  Solution obj;
  cout<<obj.findLongestConseqSubseq(a, n)<<endl;
 }
      
    return 0;
}  // } Driver Code Ends