class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int,int>hash;
        for(int i=0;i<nums1.size(); i++){
            hash[nums1[i]]++;
        }
        set<int>umap;
        for(int i=0; i<nums2.size(); i++){
            if(hash.count(nums2[i])){
                umap.insert(nums2[i]);
            }
        }
        vector<int>pp;
        for(auto x : umap){
            pp.push_back(x);
        }
        return pp;
    }
};