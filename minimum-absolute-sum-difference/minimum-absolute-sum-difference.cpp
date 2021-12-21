class Solution {
public:
    int minAbsoluteSumDiff(vector<int>& nums1, vector<int>& nums2) {
        set<int>s;
        int len = nums1.size();
        for(int i=0; i<len; i++){
            s.insert(nums1[i]);
        }
        long long int sum = 0;
        for(int i=0; i<len; i++){
            sum += abs(nums2[i]-nums1[i])%1000000007;
        }
        long long int min_so_far = sum;
        for(int i=0; i<len; i++){
            if(s.count(nums2[i])){
                min_so_far = min(min_so_far, sum-abs(nums2[i]-nums1[i]));
            }else{
                auto it = s.lower_bound(nums2[i]);
                min_so_far = min(min_so_far, sum-abs(nums2[i]-nums1[i])+abs(*it - nums2[i]));
                it--;
                if(it != s.end()){
                cout << *it << endl;
                min_so_far = min(min_so_far, sum-abs(nums2[i]-nums1[i])+abs(*it - nums2[i]));
                }
                
                
            }
        }
        return min_so_far%1000000007;
    }
};