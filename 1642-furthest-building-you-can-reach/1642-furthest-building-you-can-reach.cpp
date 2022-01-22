class Solution {
public:
    int furthestBuilding(vector<int>& heights, int bricks, int ladders) {
        priority_queue<int> pq;
        
        for (int i = 0; i < heights.size() - 1; i++) {
            if (heights[i] >= heights[i + 1])
                continue;
            
            int diff = heights[i + 1] - heights[i];
            pq.push(diff);
            bricks -= diff;
            
            if (bricks >= 0)
                continue;
            
            if (ladders == 0)
                return i;
            
            bricks += pq.top(); pq.pop(); 
			ladders--;
        }
        
        return heights.size() - 1;
    }
};








// class Solution {
// public:
//     int furthestBuilding(vector<int>& heights, int bricks, int ladders) {
//         priority_queue<int>pq;
//         int n = heights.size();
//         for(int i=0; i<n-1; i++){
//             if(heights[i+1]-heights[i]>0){
//                 pq.push(heights[i+1]-heights[i]);
//             }
//         }
//         int check = ladders;
//         unordered_map<int, int>hash;
//         while(check--){
//             hash[pq.top()]++;
//             pq.pop();
//         }

//         int cnt = 0;
//         for(int i=0; i<n-1; i++){
//             if(heights[i+1]<= heights[i]){
//                 cnt++;
//                 continue;
//             }else{
//                 int diff = heights[i+1] - heights[i];
//                 if(hash.count(diff) and ladders>0){
//                     cnt++;
//                     hash[diff]--;
//                     if(hash[diff]==0){
//                         hash.erase(diff);
//                     }
//                     ladders--;
//                     continue;
//                 }else{
//                     if(bricks >= diff){
//                         bricks = bricks-diff;
//                         cnt++;
//                         continue;
//                     }else if(ladders>0){
//                         ladders--;
//                         cnt++;
//                         continue;
//                     }
//                 }
//             }  
//             break;
//         }
//         return cnt;
//     }
// };