class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        sort(people.begin(), people.end());
        int i = 0;
        int ans = 0;
        int j = people.size()-1;
        while(i<=j){
            if(people[i]+people[j]<=limit){
                i++;
            }
            j--;
            ans++;
        }
        return ans;
    }
};





// class Solution {
// public:
//     int numRescueBoats(vector<int>& people, int limit) {
//         int len = people.size();
//         sort(people.begin(), people.end());
//         int start = 0;
//         int end = len-1;
//         int count = 0;
//         while(start <= end){
//             if(start == end){
//                 count++;
//                 start++,end--;
//             }
//             else if(people[end]==limit){
//                 count++;
//                 end--;
//             }
//             else if(people[start]==limit){
//                 count++;
//                 start++;
//             }
//             else if(people[start]+people[end]<=limit){
//                 count++;
//                 start++, end--;
//             }
//             else if(people[start]+people[end]>limit){
//                 count++;
//                 end--;
//             }
//         }
//         return count;
//     }
// };