class MyHashMap {
public:
    
    int hash[1000005] = {0};
    
    MyHashMap() {
       for(int i=0; i<1000005; i++){
        hash[i] = -1;
    } 
    }
    
    void put(int key, int value) {
        hash[key] = value;
    }
    
    int get(int key) {
        if(hash[key] != -1){
            return hash[key];
        }
        return -1;
    }
    
    void remove(int key) {
        hash[key] = -1;
    }
};

