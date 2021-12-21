class Solution {
public:
    vector<int> avoidFlood(vector<int>& rains) {
        vector<int> res(rains.size(),-1);
        unordered_map<int, int> m;
        set<int> zero;
        for(int i =0; i < rains.size(); ++i){
            if(rains[i] == 0){
                zero.insert(i);
                res[i] = 1;
            }
            else{
                if(m.find(rains[i])!=m.end()){
                    int last = m[rains[i]];
                    auto zero_ = zero.lower_bound(last);
                    if(zero_ == zero.end()){
                        res.clear();
                        return res;
                    }
                    res[*zero_] = rains[i];
                    zero.erase(zero_);
                }
                m[rains[i]] = i;
            }
        }
        return res;
    }
};