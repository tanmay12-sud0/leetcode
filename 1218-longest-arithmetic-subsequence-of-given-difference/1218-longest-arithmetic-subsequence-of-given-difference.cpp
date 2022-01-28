class Solution {
public: 
    int longestSubsequence(vector<int>& arr, int difference) {
         int max_so_far= 1;
        unordered_map<int,int>hash;
        for(int i=0; i<arr.size(); i++){
            if(hash.count(arr[i]-difference)){
                hash[arr[i]] = hash[arr[i]-difference]+1;
            }else{
                hash[arr[i]]=1;
            }    
        }
        for(auto x : hash){
            max_so_far = max(max_so_far, x.second);
        }
        return max_so_far;
    }
};