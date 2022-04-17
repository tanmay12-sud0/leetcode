class Solution {
public:
    int minDeletion(vector<int>& nums) {
        stack<int>st;
        int cnt = 0;
        int total = 0;
        for(int i=0; i<nums.size(); i++){
            if(st.empty()){
                st.push(nums[i]);
                cnt++;
            }else{
                cnt++;
                if(st.top() == nums[i] and (cnt)%2==0){
                    total++;
                    cnt--;
                    continue;
                }else{
                    
                    st.push(nums[i]);
                }
            }
        }
        nums.clear();
        while(!st.empty()){
            cout << st.top() << ", ";
            nums.push_back(st.top());
            st.pop();
        }
        if(nums.size() % 2 ==0){
            return total;
        }
        return total+1;
    }
};