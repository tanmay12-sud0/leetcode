class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int>pq;
        int n = stones.size();
        for(int i=0; i<n; i++){
            pq.push(stones[i]);
        }
        while(pq.size() > 1){
            int a = pq.top();
            pq.pop();
            int b = pq.top();
            pq.pop();
            if(a == b){
                continue;
            }
            if(a-b>0){
                pq.push(a-b);
            }
            if(b-a>0){
                pq.push(b-a);
            }
        }
        if(pq.size()==0){
            return 0;
        }
        return pq.top();
    }
};