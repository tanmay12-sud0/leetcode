class Solution {
public:
    vector<int> advantageCount(vector<int>& nums1, vector<int>& nums2) {
        vector<int>umap;
        int n = nums1.size();
        multiset<int> m(begin(nums1), end(nums1));
        for(int i=0; i<n; i++){
            auto it = m.upper_bound(nums2[i]);
            if(it != m.end()){
                umap.push_back(*it);
                m.erase(it);
            }else{
                umap.push_back(*(m.begin()));
                m.erase(m.begin());
            }
        }
        return umap;
    }
};