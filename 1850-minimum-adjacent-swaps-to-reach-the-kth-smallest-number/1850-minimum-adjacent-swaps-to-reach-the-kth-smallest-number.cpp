class Solution {
public:
    int minSteps(string s1, string s2) {
        int size = s1.length();
        int i = 0, j = 0;
        int result = 0;
  
        while (i < size) {
            j = i;
            while (s1[j] != s2[i]) j++;
			
            while (i < j) {
                swap(s1[j], s1[j-1]);
                j--;
                result++;
            }
            i++;
        }
        return result;
    }
    
    
    
    int getMinSwaps(string num, int k) {
        int n = num.length();
        string tan = num;
        for(int a=0; a<k; a++){
        // bool flag = false;
        // for(int i=n-1; i>0; i--){
        //     if(num[i]!='1' and i-1>=0){
        //         for(int j=i-1; j>=0; j--){
        //             if(num[j] < num[i]){
        //                 swap(num[j], num[i]);
        //                 reverse(num.begin()+j+1, num.end());
        //                 flag = true;
        //                 break;
        //             }
        //         }
        //     }
        //     if(flag){
        //         break;
        //     }
        // }   
            next_permutation(num.begin(), num.end());
        }
        cout << num << endl;
        int count = 0;
        return minSteps(tan, num);
        for(int i=0; i<n; i++){
            if(tan[i] != num[i]){
                int j = i;
                while(j<n){
                    if(num[j] == tan[i]){
                        break;
                    }
                    j++;
                }
                while(j>i){
                    swap(num[j], num[j-1]);
                    count++;
                    j--;
                }
            }
        }
        return count;
    }
};