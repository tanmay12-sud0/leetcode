class Solution {
public:
    bool isPossibleDivide(vector<int>& nums, int k) {
        int n = nums.size();
        if(n%k != 0){
            return false;
        }
        sort(nums.begin(), nums.end());
        map<int, int>hash;
        for(int i=0; i<n; i++){
            hash[nums[i]]++;
        }
        int count = 0;
        for(int i=0; i<n; i++){
           if(hash.count(nums[i]) and hash[nums[i]]!=0){
               int x = nums[i];
                int cnt = 0;
                while(cnt != k){
                    cnt++;
                    if(hash.count(x) and hash[x]!=0){
                        hash[x]--;
                    }else{
                        return false;
                    }
                    x++;
                }
           }
        }
        return true;
    }
};