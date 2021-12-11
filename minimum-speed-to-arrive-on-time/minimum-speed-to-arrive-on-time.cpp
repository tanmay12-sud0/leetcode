class Solution {
public:
    
    bool ismeHoGya(int mid, vector<int> dist, double hour){
        double count_hour = 0;
        cout << "mid" << mid << endl;
        for(int i=0; i<dist.size(); i++){
            if(i!=dist.size()-1){
                count_hour += ceil(double(dist[i])/double(mid));
            }else{
                count_hour += double(dist[i])/double(mid);
            }
        }
        cout << count_hour << endl;
        if(count_hour <= hour){
            return true;
        }
        return false;
    }
    
    
    
    int minSpeedOnTime(vector<int>& dist, double hour) {
        int len = dist.size();
        if (hour <= (double)(len - 1))
            return -1;
        
        
        int max_speed = 0;
        // for(int i=0; i<len; i++){
        //     max_speed += dist[i]*hour;
        // }
        int ans = -1;
        int start = 1;
        int end = 1e7;
        while(start <= end){
            int mid = end + (start-end)/2;
            if(ismeHoGya(mid, dist, hour)){
                ans = mid;
                end = mid-1;
            }else{
                start = mid+1;
            }
        }
        return ans;
    }
};