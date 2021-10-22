class Solution {
public:
    bool isHappy(int n) {
        
       unordered_set<int>hash;

        while(n != 1){
   
        if(hash.count(n)){
            return false;
        }else{
            hash.insert(n);
        }
            
            
            
            int new_num = 0;
            while(n!=0){
                int x = n%10;
                n = n/10;
                new_num += x*x;
            }
            n = new_num;
        }
        if(n == 1){
            return true;
        }
         
        
        return false;
    
    }
};