class SnapshotArray {
private:
    int id = 0;
    vector<vector<pair<int, int>>> snapshot;
    
public:
    SnapshotArray(int length) {
        snapshot.resize(length);
        for (int i = 0; i < length; ++i){
            snapshot[i].push_back({0, 0});
        }
    }
    
    void set(int index, int val) {
        snapshot[index].push_back({id, val});
    }
    
    int snap() {
        return id++;
    }
    
    int get(int index, int snap_id) {
        int left = 0, right = snapshot[index].size();
        
        while (left < right){
            int mid = left + (right - left) / 2;
            if (snap_id < snapshot[index][mid].first) right = mid;
            else left = mid + 1;
        }
        
        return snapshot[index][left - 1].second;
    }
};

/**
 * Your SnapshotArray object will be instantiated and called as such:
 * SnapshotArray* obj = new SnapshotArray(length);
 * obj->set(index,val);
 * int param_2 = obj->snap();
 * int param_3 = obj->get(index,snap_id);
 */