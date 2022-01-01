class Solution {
public:
    bool mergeTriplets(vector<vector<int>>& triplets, vector<int>& target) {
        int first = 0, second = 0, third = 0;
        for (auto tr : triplets) {
            if (tr[0] == target[0] && tr[1] <= target[1] && tr[2] <= target[2]) first = 1;
            if (tr[0] <= target[0] && tr[1] == target[1] && tr[2] <= target[2]) second = 1;
            if (tr[0] <= target[0] && tr[1] <= target[1] && tr[2] == target[2]) third = 1;
        }
        return first && second && third;
    }
};



// class Solution {
// public:
//     bool mergeTriplets(vector<vector<int>>& triplets, vector<int>& target) {
//         int n = triplets.size();
//         bool flag = false;
//         int count = 0;
//         set<int>ss;
//         for(int i=0; i<target.size(); i++){
//             for(int j=0; j<triplets.size(); j++){
//                 if(triplets[j][i] > target[i]){
//                     cout << j << i << endl;
//                     ss.insert(j);
//                 }
//             }
//         }
//         for(auto x : ss){
//             cout << x << endl;
//         }
        
//         for(int i=0; i<target.size(); i++){
//             flag = false;
//             for(int j=0; j<n; j++){
//                 if(!ss.count(j) and triplets[j][i] == target[i]){
//                     flag = true;
//                 }
//             }
//             if(flag){
//                 count++;
//             }
//         }
//         if(count == 3){
//             return true;
//         }
//         return false;
//     }
// };