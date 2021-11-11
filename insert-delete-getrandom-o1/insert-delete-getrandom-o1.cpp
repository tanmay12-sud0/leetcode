class RandomizedSet {
public:
    set<int>hash;
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
        for (int i = 0; i < idx; i++)
        {
            it++;
        }
        return *it;
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */