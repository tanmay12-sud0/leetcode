struct MyComp {
        bool operator() (const pair<int, string>& a, const pair<int, string>& b) {
            if(a.first != b.first) {
                return a.first < b.first;
            }
            else {
                return a.second > b.second;
            }
        }
};

class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        vector<string>ss;
        unordered_map<string, int>hash;
        for(int i=0; i<words.size(); i++){
            hash[words[i]]++;
        }
        priority_queue<pair<int, string>, vector<pair<int, string>>, MyComp>pq;
        
        for(auto x : hash){
            pq.push(make_pair(x.second, x.first));
        }
        for(int i=0; i<k; i++){
            ss.push_back(pq.top().second);
            pq.pop();
        }
        return ss;
    }
};