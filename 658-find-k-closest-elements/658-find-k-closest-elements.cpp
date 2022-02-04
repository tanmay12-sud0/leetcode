class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        priority_queue<pair<int, int>>pq;
        for(int i=0; i<arr.size(); i++){
            pq.push(make_pair(abs(x-arr[i]), arr[i]));
            if(pq.size()>k){
                pq.pop();
            }
        }
        vector<int>umap;
        while(!pq.empty()){
            cout << pq.top().first << ", " << pq.top().second << endl;
            umap.push_back(pq.top().second);
            pq.pop();
            
        }
        sort(umap.begin(), umap.end());
        return umap;
    }
};