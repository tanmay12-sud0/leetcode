// { Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


 // } Driver Code Ends
//User function template for C++
class Solution{
public:	

	void segregateEvenOdd(int arr[], int n) {
	    vector<int>even;
	    vector<int>odd;
	    for(int i=0; i<n; i++){
	        if(arr[i]%2 == 0){
	            even.push_back(arr[i]);
	        }else{
	            odd.push_back(arr[i]);
	        }
	    }
	    sort(even.begin(), even.end());
	    sort(odd.begin(), odd.end());
	    for(auto x : odd){
	        even.push_back(x);
	    }
	    for(int i=0; i<n; i++){
	        arr[i] = even[i];
	    }
	    return;
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
        ob.segregateEvenOdd(arr, n);
        for (int i = 0; i < n; i++) {
            cout << arr[i] << " ";
        }
        cout << "\n";
    }
    return 0;
}
  // } Driver Code Ends