class Solution {
public:
    vector<int> twoOutOfThree(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3) {
        vector<int>hash;
        unordered_map<int, int>hash1;
        unordered_map<int, int>hash2;
        unordered_map<int, int>hash3;
        for(auto x : nums1){
            hash1[x]++;
        }
        for(auto x : nums2){
            hash2[x]++;
        }
        for(auto x : nums3){
            hash3[x]++;
        }
        for(int i=0; i<=100; i++){
            if((hash1.count(i) and hash2.count(i)) or ( hash1.count(i)and hash3.count(i)) or (hash2.count(i) and hash3.count(i))){
                hash.push_back(i);
            }
        }
        return hash;
    }
};