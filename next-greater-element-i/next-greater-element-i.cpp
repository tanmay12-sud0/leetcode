class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        stack<int>s;
        vector<int>ss;
        unordered_map<int, int>hash;
        int len2 = nums2.size();
        for(int i=len2-1; i>=0; i--){
            if(s.empty()){
                s.push(nums2[i]);
            }else{
                while(!s.empty() and s.top() < nums2[i]){
                    s.pop();
                }
                if(!s.empty()){
                    hash[nums2[i]] = s.top();
                }
                s.push(nums2[i]);
                
            }
        }
        
        // for(auto x : hash){
        //     cout << x.first <<", " << x.second << endl;
        // }
        for(int i=0; i<nums1.size(); i++){
            if(hash.count(nums1[i])){
                ss.push_back(hash[nums1[i]]);
            }else{
                ss.push_back(-1);
            }
        }
        return ss;
    }
};