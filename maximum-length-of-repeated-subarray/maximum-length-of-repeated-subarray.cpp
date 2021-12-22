class Solution {
public:
          bool hogya(int mid, string ss1, string ss2){
            unordered_map<string, int>hash;
            int i=0;
            while(i+mid<=ss1.size()){
                hash[ss1.substr(i, mid)]++;
                i++;
            }
            i=0;
            while(i+mid<=ss2.size()){
                if(hash.count(ss2.substr(i, mid))){
                    return true;
                }   
                i++;
            }
            return false;
        }

    int findLength(vector<int>& nums1, vector<int>& nums2) {
        int len = nums1.size();
        
        string ss1;
        string ss2;
        
        for(int i=0; i<len; i++){
            ss1 += 'a'+(nums1[i]);
        }
        
        for(int i=0; i<nums2.size(); i++){
            ss2 += 'a' + nums2[i];
        }
        int start = 1;
        int end = len;
        int ans = 0;
        while(start <= end){
            int mid = (start+end)/2;
            
            if(hogya(mid, ss1, ss2)){
                ans = mid;
                start = mid+1;
            }else{
                end = mid-1;
            }
        }
        
        return ans;
    }
};
