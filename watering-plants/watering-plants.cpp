class Solution {
public:
    int wateringPlants(vector<int>& plants, int capacity) {
        int len = plants.size();
        int count = 0;
        int threeSold = capacity;
        for(int i=0; i<len; i++){
            if(threeSold < plants[i]){
                count += 2*(i);
                threeSold = capacity;
            }
            count++;
            threeSold -= plants[i];
        }
        return count;
    }
};