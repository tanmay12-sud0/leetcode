class Solution {
public:
    int minStoneSum(vector<int>& piles, int k) {
        priority_queue<int>pq(piles.begin(), piles.end());
        int count=0;
        while(count < k){
            count++;
            float x = pq.top();
            pq.pop();
            x = ceil(x/2);
            pq.push(x);
        }
        int sum = 0;
        while(!pq.empty()){
            sum += pq.top();
            pq.pop();
        }
        return sum;
    }
};