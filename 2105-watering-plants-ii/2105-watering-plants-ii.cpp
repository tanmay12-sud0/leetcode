class Solution {
public:
    int minimumRefill(vector<int>& plants, int capacityA, int capacityB) {
        int refil = 0;
        int n = plants.size();
        int i= 0;
        int j = n-1;
        int cap1 = capacityA;
        int cap2 = capacityB;
        while(i<j){
            if(cap1 < plants[i]){
                refil++;
                cap1 = capacityA-plants[i];
            }else{
                cap1 -= plants[i];
            }
            if(cap2 < plants[j]){
                refil++;
                cap2 = capacityB-plants[j];
            }else{
                cap2 -= plants[j];
            }
            i++, j--;
        }
        if(n%2!=0){
            int index = n/2;
            int remain = max(cap1, cap2);
            if(plants[index] > remain){
                refil++;
            }
        }
        return refil;
    }
};