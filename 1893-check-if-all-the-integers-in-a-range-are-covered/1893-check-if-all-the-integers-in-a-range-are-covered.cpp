class Solution {
public:
    bool isCovered(vector<vector<int>>& ranges, int left, int right) {
        int cnt=0;
        for(int i=left;i<=right;i++){
            bool found=false;
            for(int j=0;j<ranges.size();j++){
                if(i>=ranges[j][0] && i<=ranges[j][1]){
                    found=true;
                    break;
                }
            }
            if(found){
                cnt++;
            }
        }
        
        if(cnt == (right-left+1)){
            return true;
        }
        else{
            return false;
        }
    }
};