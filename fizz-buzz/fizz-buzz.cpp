class Solution {
public:
    vector<string> fizzBuzz(int n) {
        vector<string>hash;
        for(int i=1; i<=n; i++){
            if(i%15==0){
                hash.push_back("FizzBuzz");
            }else if(i%3==0){
                hash.push_back("Fizz");
            }else if(i%5==0){
                hash.push_back("Buzz");
            }else{
                hash.push_back(to_string(i));
            }
        }
        return hash;
    }
};