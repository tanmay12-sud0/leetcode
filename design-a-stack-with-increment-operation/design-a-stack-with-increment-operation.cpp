class CustomStack {
public:
    vector<int>hash;
    int i = 0;
    CustomStack(int maxSize) {
        i = maxSize;
    }
    
    void push(int x) {
        if(hash.size() < i){
            hash.push_back(x);
        }
    }
    
    int pop() {
        if(hash.size() == 0){
            return -1;
        }
            int x = hash.back();
            hash.pop_back();
            return x;
        
    }
    
    void increment(int k, int val) {
        for(int x=0; x<k and x<hash.size(); x++){
            hash[x] += val;
        }
    }
};

