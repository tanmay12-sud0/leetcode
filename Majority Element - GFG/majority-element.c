// { Driver Code Starts
//Initial Template for C

#include <stdio.h>
#include <stdbool.h>


 // } Driver Code Ends
//User function Template for C

// Function to find majority element in the array
// a: input array
// size: size of input array
int majorityElement(int a[], int size)
{
        
    int minj = a[0];
    int cnt = 1;
    for(int i=1; i<size; i++){
        if(a[i] == minj){
            cnt++;
        }
        if(a[i] != minj){
            cnt--;
        }
        if(cnt == 0){
            minj = a[i];
            cnt = 1;
        }
    }
    // cout << minj << endl;
    int sum = 0;
    for(int i=0; i<size; i++){
        if(a[i] == minj){
            sum++;
        }
    }
    if(sum > (size/2)){
        return minj;
    }
    return -1;
}

// { Driver Code Starts.

int main(){

    int t;
    scanf("%d", &t);

    while(t--){
        int n;
        scanf("%d", &n);
        int arr[n];
        
        for(int i = 0;i<n;i++){
            scanf("%d", &arr[i]);
        }
        printf("%d\n", majorityElement(arr, n));
    }

    return 0;
}
  // } Driver Code Ends