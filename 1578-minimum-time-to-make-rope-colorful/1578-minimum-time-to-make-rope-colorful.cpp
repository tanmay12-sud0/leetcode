class Solution {
public:
    int minCost(string colors, vector<int>& neededTime) {
        vector<pair<char, int>>ss;
        int needTime = 0;
        for(int i=0; i<colors.length(); i++){
            if(ss.empty()){
                ss.push_back(make_pair(colors[i], i));
            }else{
                if(ss.back().first == colors[i]){
                    if(neededTime[ss.back().second] < neededTime[i]){
                        needTime += neededTime[ss.back().second];
                        ss.pop_back();
                        ss.push_back(make_pair(colors[i], i));
                    }else{
                        needTime += neededTime[i];
                    }
                }else{
                    ss.push_back(make_pair(colors[i], i));
                }
            }
        }
        return needTime;
    }
};