class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& score) {
        unordered_map<int, int>hash;
        priority_queue<int>pq;
        for(int i=0; i<score.size(); i++){
            hash[score[i]] = i;
            pq.push(score[i]);
        }
        vector<string>umap(score.size());
        if(pq.size()>0){
             int a = pq.top();
            pq.pop();
            umap[hash[a]] = "Gold Medal";
        }
        if(pq.size()>0){
             int b = pq.top();
        pq.pop();
        umap[hash[b]] = "Silver Medal";
        }
        if(pq.size()>0){
             int c = pq.top();
        pq.pop();
        umap[hash[c]] = "Bronze Medal";
        }

        int count = 4;
        while(!pq.empty()){
            int d = pq.top();
            umap[hash[d]] = to_string(count);
            pq.pop();
            count++;
        }
        return umap; 
    }
};