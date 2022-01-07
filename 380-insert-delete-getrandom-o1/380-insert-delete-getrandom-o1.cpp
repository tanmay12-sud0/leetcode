class RandomizedSet {
public:
    unordered_set<int>hash;
    RandomizedSet() {
        
    }
    
    bool insert(int val) {
        if(hash.count(val)){
            return false;
        }else{
            hash.insert(val);
            return true;
        }
    }
    
    bool remove(int val) {
        if(hash.count(val)){
            hash.erase(val);
            return true;
        }else{
            return false;
        }
    }
    
    int getRandom() {
        int len = hash.size();
        int idx = rand()%len;
        auto it = hash.begin();
        advance(it, idx);
        // for (int i = 0; i < idx; i++)
        // {
        //     it++;
        // }
        return *it;
    }
};

