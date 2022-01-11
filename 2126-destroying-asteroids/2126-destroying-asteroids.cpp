class Solution {
public:
    bool asteroidsDestroyed(int mass, vector<int>& asteroids) {
        int n = asteroids.size();
        sort(begin(asteroids),end(asteroids));
       long long int sum=mass;
        for(int i=0;i<n;i++){
            if(sum >= asteroids[i]){
                sum+=asteroids[i];
            }
            else
                return false;
        }
        return true;
    }
};



// class Solution {
// public:
//     bool asteroidsDestroyed(int mass, vector<int>& asteroids) {
//         int n = asteroids.size();
//         sort(asteroids.begin(), asteroids.end());
//         long long int sum = mass;
//         while(asteroids.size()>0){
//             auto it = lower_bound(asteroids.begin(), asteroids.end(), sum);
//             if(it != asteroids.end()){
//                 if(*it <= sum){
//                 sum += *it;
//                 asteroids.erase(it);
//             }
//             if(*it > sum){
//                 auto pp = asteroids.begin();
//                 if(it != pp){
//                     it--;
//                     sum += *it;
//                     asteroids.erase(it);
//                 }else{
//                     return false;
//                 }
//             }
//             }else{
//                 it--;
//                 sum += *it;
//                 asteroids.erase(it);
//             }
//         }
//         return true;
//     }
// };