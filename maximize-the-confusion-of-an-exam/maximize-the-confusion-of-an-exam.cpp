class Solution {
public:
    
    bool hogya(int mid, vector<int>trues, vector<int>falses, int k, int len){
        int i=0;
        int j = mid;
        cout << mid << endl;
        while(j<len){
            if((i-1>=0 and abs(trues[j]-trues[i-1]) <= k) or ( i-1>=0 and abs(falses[j]-falses[i-1]) <= k)){
                return true;     
            }
            if((i-1<0 and abs(trues[j]) <= k) or (i-1 <0 and abs(falses[j]) <= k)){
                return true;     
            }
            i++,j++;
        }
        return false;
    }
    
    
    
    
    int maxConsecutiveAnswers(string answerKey, int k) {
        
        int len = answerKey.length();
        vector<int>trues(len, 0);
        vector<int>falses(len, 0);
        
        if(answerKey[0] == 'T'){
            trues[0] = 1;
            falses[0] = 0;
        }
        if(answerKey[0] == 'F'){
            trues[0] = 0;
            falses[0] = 1;
        }
        for(int i=1; i<len; i++){
            if(answerKey[i] == 'T'){
                trues[i] = 1 + trues[i-1];
                falses[i] = falses[i-1];
            }
            if(answerKey[i] == 'F'){
                trues[i] = trues[i-1];
                falses[i] = 1 + falses[i-1];
            }
        }
        
        
        // for(auto x : trues){
        //     cout << x << ", ";
        // }
        // for(auto x : falses){
        //     cout << x << ", ";
        // }
        int ans = 0;
        int start = 1;
        int end = len;
        while(start <= end){
            int mid = (start+end)/2;
            if(hogya(mid, trues, falses, k , len)){
                start = mid+1;
                ans = mid;
            }else{
                end = mid-1;
            }
        }

        return ans+1;
    }
};