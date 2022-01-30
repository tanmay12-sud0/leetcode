class Solution {
public:
    int minCost(string s, vector<int>& cost) 
    {
        int res = 0;
        int n = s.size();
        for(int i = 1; i < n; i++)
        {
            if(s[i] == s[i - 1])
            {
                res += min(cost[i], cost[i - 1]); 
                cost[i] = max(cost[i], cost[i - 1]); 
            }     
        }
        
        return res;
        
    }
    // int minCost(string colors, vector<int>& neededTime) {
    //     vector<pair<char, int>>ss;
    //     int needTime = 0;
    //     for(int i=0; i<colors.length(); i++){
    //         if(ss.empty()){
    //             ss.push_back(make_pair(colors[i], i));
    //         }else{
    //             if(ss.back().first == colors[i]){
    //                 if(neededTime[ss.back().second] < neededTime[i]){
    //                     needTime += neededTime[ss.back().second];
    //                     ss.pop_back();
    //                     ss.push_back(make_pair(colors[i], i));
    //                 }else{
    //                     needTime += neededTime[i];
    //                 }
    //             }else{
    //                 ss.push_back(make_pair(colors[i], i));
    //             }
    //         }
    //     }
    //     return needTime;
    // }
};