class Solution {
public:
    int timeRequiredToBuy(vector<int>& tickets, int k) {
        queue<int>q;
        int n = tickets.size();
        for(int i=0; i<n; i++){
            q.push(i);
        }
        int count = 0;
        while(!q.empty()){
            int f = q.front();
            q.pop();
            count++;
            tickets[f]--;
            if(f == k and tickets[f]==0){
                return count;
            }
            if(tickets[f]!=0){
                q.push(f);
            }
        }
        return -1;
    }
};