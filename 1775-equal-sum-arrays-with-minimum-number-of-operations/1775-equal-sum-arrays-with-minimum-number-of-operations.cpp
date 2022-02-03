class Solution {
public:
    int minOperations(vector<int>& nums1, vector<int>& nums2) {
        if(6 * nums1.size() < 1 * nums2.size() || 6 * nums2.size() < 1 * nums1.size())
            return -1;

        unordered_map<int, int>hash1;
        unordered_map<int, int>hash2;
        int oper = 0;
        int sum1 = 0;
        int sum2 = 0;
        for(auto x : nums1){
            sum1 += x;
            hash1[x]++;
        }
        for(auto x : nums2){
            sum2 += x;
            hash2[x]++;
        }
        int diff = 0;
        if(sum1 == sum2){
            return 0;
        }
        if(sum1 > sum2){
            diff = sum1-sum2;
            for(int i=0; i<6; i++){
                while(hash1.count(6-i) and hash1[6-i] != 0 and diff>0 ){
                    diff -= 6-i-1;
                    oper++;
                    hash1[6-i]--;
                }
                while(hash2.count(i+1) and hash2[i+1] != 0 and diff>0){
                    diff -= 6-i-1;
                    oper++;
                    hash2[i+1]--;
                }
            }
        }else{
            diff = sum2-sum1;
            for(int i=0; i<6; i++){
                while(hash2.count(6-i) and hash2[6-i] != 0 and diff>0){
                    diff -= 6-i-1;
                    oper++;
                    hash2[6-i]--;
                }
                while(hash1.count(i+1) and hash1[i+1] != 0 and diff>0){
                    diff -= 6-i-1;
                    oper++;
                    hash1[i+1]--;
                }
            }
        }

        return oper;
    }
};