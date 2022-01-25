class FindSumPairs {
public:
    unordered_map<int,int> freq;
    vector<int> v1;
    vector<int> v2;
    FindSumPairs(vector<int>& nums1, vector<int>& nums2) {
        for(auto ele:nums2)
            freq[ele]++;
        v1=nums1;
        v2=nums2;
    }
    
    void add(int index, int val) {
        freq[v2[index]]-- ;
        v2[index]+=val;
        freq[v2[index]]++;
    }
    
    int count(int tot) {
        int pairs=0;
        for(auto ele:v1)
            if(tot>ele && freq.count(tot-ele))
                pairs+=freq[tot-ele];
        return pairs;
    }
};











// class FindSumPairs {
// public:
//     unordered_map<int, int>hash;
//     vector<int>hash2;
//     FindSumPairs(vector<int>& nums1, vector<int>& nums2) {
//         for(int i=0; i<nums1.size(); i++){
//             hash[nums1[i]]++;
//         }
//         for(int i=0; i<nums2.size(); i++){
//             hash2.push_back(nums2[i]);
//         }
//         sort(hash2.begin(), hash2.end());
//     }
    
//     void add(int index, int val) {
//         hash2[index] += val;
//     }
    
//     int count(int tot) {
//         int cnt = 0;
//         for(int i=0; i<hash2.size() and hash2[i]<=tot; i++){
//             if(hash.count(tot-hash2[i])){
//                 cnt += hash[tot-hash2[i]];
//             }
//         }
//         return cnt;
//     }
// };
