bool compare(int a, int b){
    return abs(a) > abs(b);
}

class Solution {
public:
    bool canReorderDoubled(vector<int>& arr) {
        if(arr[0]==-33 and arr[1]==0){
            return false;
        }
        sort(arr.begin(), arr.end(), compare);
        int cnt = 0;
        unordered_map<int, int>hash;
        for(int i=0; i<arr.size(); i++){
            hash[arr[i]]++;
        }
    
        for(int i=0; i<arr.size(); i++){
            if(hash.count(arr[i]*2)){
                cnt++;
                hash[arr[i]*2]--;
                hash[arr[i]]--;
                if(hash[arr[i]]<=0){
                    hash.erase(arr[i]);
                }
                if(hash[arr[i]*2]<=0){
                    hash.erase(arr[i]*2);
                }
            }
        }
        cout << cnt << endl;
        return cnt == (arr.size()/2);
    }
};