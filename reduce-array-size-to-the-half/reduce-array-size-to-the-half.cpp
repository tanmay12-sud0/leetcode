class Solution {
public:
    int minSetSize(vector<int>& arr) {
        int n = arr.size();
        priority_queue<pair<int, int>>pq;
        unordered_map<int, int>hash;
        for(int i=0; i<n;i++){
            hash[arr[i]]++;
        }
        for(auto x : hash){
            pq.push(make_pair(x.second, x.first));
        }
        int count = 0;
        int tan = n;
        while (!pq.empty()) {
            cout << pq.top().first << ", ";
           if(n-pq.top().first  <= tan/2){
               return count+1;
           }
            count++;
            n -= pq.top().first;
            pq.pop();
        }
        return count;
    }
};