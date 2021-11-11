class Solution {
public:
    int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3, vector<int>& nums4) {
        unordered_map<int, int>hash1;
        unordered_map<int, int>hash2;
        int len = nums1.size();
        for(int i=0; i<len; i++){
            for(int j=0; j<len; j++){
                hash1[nums1[i]+nums2[j]]++;
            }
        }
        for(int i=0; i<len; i++){
            for(int j=0; j<len; j++){
                hash2[nums3[i]+nums4[j]]++;
            }
        }
        int count = 0;
        for(auto x : hash1){
            if(x.first != 0){
                if(hash2.count(-(x.first))){
                count += x.second*hash2[-(x.first)];
                }
            }else{
                if(hash2.count((x.first))){
                count += x.second*hash2[(x.first)];
                }
            }
        }
        return count;
    }
};