class Solution {
public:
    int minSetSize(vector<int>& arr) {
        unordered_map<int, int>umap;
        priority_queue<int>pq;
        for(auto x : arr){
            umap[x]++;
        }        
        for(auto x : umap){
            pq.push(x.second);
        }
        int removed = 0;
        int count = 0;
        while(removed < (arr.size()/2)){
            removed += pq.top();
            pq.pop();
            count++;
        }
        return count;
    }
};
