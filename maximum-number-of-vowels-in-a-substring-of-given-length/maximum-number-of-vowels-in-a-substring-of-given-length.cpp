class Solution {
public:
    
    
    
    
    int maxVowels(string s, int k) {
        unordered_map<char, int>hash;
        hash['a']++;
        hash['e']++;
        hash['i']++;
        hash['o']++;
        hash['u']++;
        int count = 0;
        int len = s.size();
        if(len < k){
            return count;
        }
        int sum = 0;
        int max_so_far = INT_MIN;
        for(int i=0; i<k; i++){
            if(hash.count(s[i])){
                sum++;
            }
        }
        max_so_far = max(max_so_far, sum);
        // if(sum/k >= threshold){
        //     count++;
        // }
        int i = k;
        int j = 0;
        while(i<len){
            // sum = sum + arr[i] - arr[i-k];?
            if(hash.count(s[i])){
                sum = sum + 1;
            }
            if(hash.count(s[i-k])){
                sum--;
            }
           max_so_far = max(max_so_far, sum);

            i++;
        }
        return max_so_far;
    }
};