class Solution {
public:
    
 vector<int> fib;
 
    void fill_fib(int n) {
        fib.push_back(1);
        fib.push_back(1);
        int i = 2;
        while(true) {
            fib.push_back(fib[i-1] + fib[i-2]);
            i += 1;
            if (fib.back() > n) break;
        }        
        fib.pop_back();
    }
    
    
    int findMinFibonacciNumbers(int k) {
        fill_fib(k);
        int count =0;
        while(k>0){
            auto it = upper_bound(fib.begin(), fib.end(), k);
            count++;
            it--;
            k = k-*it;
        }
        
        
        return count;
    }
};