class Solution {
public:
    int findMinDifference(vector<string>& time) {
        sort(time.begin(), time.end());
        // for(auto x : time){
        //     cout << x << endl;
        // }
        int n = time.size();
        int min_so_far = INT_MAX;
        for(int i=0; i<time.size()-1; i++){
            string hr1 = time[i].substr(0,2);
            string min1 = time[i].substr(3,2);
            string hr2 = time[i+1].substr(0, 2);
            string min2 = time[i+1].substr(3, 2);
            
            int a = (stoi(hr2)-stoi(hr1))*60 + (stoi(min2)-stoi(min1));
            min_so_far = min(min_so_far, min(a, 24*60-a));
        }
        
            string hr1 = time[0].substr(0,2);
            string min1 = time[0].substr(3,2);
            string hr2 = time[n-1].substr(0, 2);
            string min2 = time[n-1].substr(3, 2);
            int a = (stoi(hr2)-stoi(hr1))*60 + (stoi(min2)-stoi(min1));
            min_so_far = min(min_so_far, min(a, 24*60-a));
        return min_so_far;
    }
};