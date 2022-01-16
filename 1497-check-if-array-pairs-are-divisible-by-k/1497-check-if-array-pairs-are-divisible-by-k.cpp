class Solution {
public:
    bool canArrange(vector<int>& arr, int k) {
        int n = arr.size();
        int cnt = 0;
        int cnt2 = 0;
        for(int i=0; i<n; i++){
            arr[i] = arr[i]%k;
            if(arr[i]<0){
                arr[i] += k;
            }
        }
        unordered_map<int, int>hash;
        for(int i=0; i<n; i++){
            if(arr[i] == 0){
                cnt2++;
            }
            if(hash.count(k - arr[i]) and hash[k-arr[i]]>0){
                hash[k-arr[i]]--;
                cnt++;
            }else{
                hash[arr[i]]++;
            }
        }
        cout << cnt+(cnt2/2) << endl;
        return cnt+(cnt2/2) == (n/2);
    }
};