class SnapshotArray {
public:
    vector<int> a;
    int lastSnapId = 0;
    map<pair<int, int>, int> element;
    vector<vector<int>> v;
    
    SnapshotArray(int length) {
        a.resize( length, 0 );
        v.resize(length, {0});
    }
    
    void set(int index, int val) {
        element[{index, lastSnapId}] = val;
        a[index] = lastSnapId;
        v[index].push_back(lastSnapId);
    }
    
    int snap() {
        lastSnapId++;
        return lastSnapId-1;
    }
    
    int get(int index, int snap_id) {
        int up = upper_bound ( v[index].begin(), v[index].end(), snap_id ) - v[index].begin();
        up--;
        return element[{ index, v[index][up]}];
    }
};