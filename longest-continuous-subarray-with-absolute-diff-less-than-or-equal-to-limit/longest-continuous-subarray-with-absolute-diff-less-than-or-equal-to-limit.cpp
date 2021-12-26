class Solution {
public:
    int longestSubarray(vector<int>& nums, int limit) {
        
        priority_queue<pair<int,int>,vector<pair<int,int>>, greater<pair<int,int>>> pqmin;
        priority_queue<pair<int,int>> pqmax;
        
        int start = 0;
   
        int ans = 1;
        for(int i=0; i<nums.size();){
            pqmin.push({nums[i], i});
            pqmax.push({nums[i], i});
            
            while(pqmin.top().second < start){
                pqmin.pop();
            }
            
            while(pqmax.top().second < start){
                pqmax.pop();
            }
            
            if(abs(pqmin.top().first - pqmax.top().first) > limit){
                start++;
            }else{
                if((i-start+1 > ans)){
                    ans = i-start+1;
                    
                }
               i++; 
            }
        }
        return ans;
    }
};