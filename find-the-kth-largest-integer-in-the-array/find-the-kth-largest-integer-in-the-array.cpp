 struct cmp
    {
        bool operator()(const string &a, const string &b)
        {
            return a.length()==b.length() ? (a>b) : a.length()>b.length();
        }    
    };



class Solution {
public:
    
    
    
    
    string kthLargestNumber(vector<string>& nums, int k) {
        priority_queue<string, vector<string>, cmp>pq;
        for(auto x : nums){
            pq.push(x);
            if(pq.size() > k){
                pq.pop();
            }
        }
        return pq.top();
    }
};