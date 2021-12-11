bool compare(vector<int>&a, vector<int>&b){
    return a[1]>b[1];
}

class Solution {
public:
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
        int len = boxTypes.size();
        int sum = 0;
        sort(boxTypes.begin(), boxTypes.end(), compare);
        int i;
        for(i=0; i<len; i++){
            cout << boxTypes[i][0] << ", " << boxTypes[i][1]<<endl;
            
            if(truckSize > boxTypes[i][0]){
                truckSize -= boxTypes[i][0];
                sum += (boxTypes[i][0]*boxTypes[i][1]);
            }else{
                sum += boxTypes[i][1]*truckSize;
                break;
            }  
        }
       
        return sum;
    }
};