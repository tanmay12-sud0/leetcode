// { Driver Code Starts
#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;



/* Function to print an array */
void printArray(int arr[], int size)
{
    int i;
    for (i=0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}


 // } Driver Code Ends


class Solution
{
    void merge(int arr[], int l, int m, int r)
    {
        int arrSize_1 = m - l + 1;
        int arrSize_2 = r - m;
        
        int* subarr_1 = new int[arrSize_1];
        int* subarr_2 = new int[arrSize_2];
        
        int i;
        for(i = 0; i < arrSize_1; i++)
            subarr_1[i] = arr[l + i];

        for(i = 0; i < arrSize_2; i++)
            subarr_2[i] = arr[m + 1 + i];
        
        int i_1 = 0, i_2 = 0;
        i = l;
        
        while(i_1 < arrSize_1 && i_2 < arrSize_2)
        {
            if(subarr_1[i_1] < subarr_2[i_2])
                arr[i++] = subarr_1[i_1++];
            else 
                arr[i++] = subarr_2[i_2++];
        }
        
        while(i_1 < arrSize_1)
            arr[i++] = subarr_1[i_1++];
        
        while(i_2 < arrSize_2)
            arr[i++] = subarr_2[i_2++];
        
    }
    public:
    void mergeSort(int arr[], int l, int r)
    {
        if(l < r)
        {
            int m = (l + r) / 2;
            mergeSort(arr, l, m);
            mergeSort(arr, m + 1, r);
            merge(arr, l, m, r);
        }
    }
};

// { Driver Code Starts.


int main()
{
    int n,T,i;

    scanf("%d",&T);

    while(T--){
    
    scanf("%d",&n);
    int arr[n+1];
    for(i=0;i<n;i++)
      scanf("%d",&arr[i]);

    Solution ob;
    ob.mergeSort(arr, 0, n-1);
    printArray(arr, n);
    }
    return 0;
}  // } Driver Code Ends