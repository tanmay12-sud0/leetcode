class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        vector<int>hash(m+n, 0);
        int i=0; 
        int j=0;
        int k=0;
        while(i<m and j<n){
            if(nums1[i] <= nums2[j]){
                hash[k++] = nums1[i++];
            }else{
                hash[k++] = nums2[j++];
            }
        }
        while(i<m){
            hash[k++] = nums1[i++];
        }
        while(j<n){
            hash[k++] = nums2[j++];
        }
        nums1.clear();
        for(auto x : hash){
            nums1.push_back(x);
        }
        return;
    }
};