// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution
{
    public:
    //Function to check if a string can be obtained by rotating
    //another string by exactly 2 places.
    bool isRotated(string str1, string str2)
    {
        int len = str1.length();
        string a;
        string b;
        a += str1[len-2];
        a += str1[len-1];
        a += str1.substr(0, len-2);
        
        b += str1.substr(2);
        b += str1[0];
        b += str1[1];
        // cout << a << "  " << b << endl;
        if(a == str2 or b == str2){
            return true;
        }
        return false;
    }

};


// { Driver Code Starts.

int main() {
	
	int t;
	cin>>t;
	while(t--)
	{
		string s;
		string b;
		cin>>s>>b;
		Solution obj;
		cout<<obj.isRotated(s,b)<<endl;
	}
	return 0;
}
  // } Driver Code Ends