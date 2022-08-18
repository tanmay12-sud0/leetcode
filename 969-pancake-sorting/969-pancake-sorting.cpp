class Solution {
public:
    vector<int> pancakeSort(vector<int>& arr) {
        vector<int>data;
        int n = arr.size();
        int j = n-1;
        while(j >= 0){
            int max_so = INT_MIN;
            int index = -1;
            for(int i=0; i<=j; i++){
                if(arr[i] > max_so){
                    max_so = arr[i];
                    index = i;
                }
            }
            if(index == j){
                j--;
                continue;
            }else{
                reverse(arr.begin(), arr.begin()+index+1);
                reverse(arr.begin(), arr.begin()+j+1);
                data.push_back(index+1);
                data.push_back(j+1);
            }
            j--;
        }
        return data;
    }
};