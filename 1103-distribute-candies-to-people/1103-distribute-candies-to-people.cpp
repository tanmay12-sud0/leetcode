class Solution {
public:
    vector<int> distributeCandies(int candies, int num_people) {
        vector<int>hash(num_people, 0);
        int cnt = 0;
        int value = 1;
        while(candies> 0){
            int index = cnt%num_people;
            cnt++;
            // cout << cnt << endl;
            if(value > candies){
                hash[index] += candies;
                candies = 0;
            }else{
                hash[index] += value;
                candies -= value;
            }
            value++;
        }
        return hash;
    }
};