class MyHashSet {
public:
    vector<int> umap;
    MyHashSet() {
        umap.resize(1000003, 0);
    }
    
    void add(int key) {
        umap[key] = 1;
    }
    
    void remove(int key) {
        umap[key] = 0;
    }
    
    bool contains(int key) {
        return umap[key];
    }
};
