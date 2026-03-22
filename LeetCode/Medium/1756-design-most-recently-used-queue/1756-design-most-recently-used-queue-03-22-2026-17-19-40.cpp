class MRUQueue {
private:
    int totalElems;
    const int BUCKET_SIZE;
    vector<vector<int>> data;
    vector<int> index;

public:
    MRUQueue(int n): totalElems(n), BUCKET_SIZE(sqrt(n)) {
        for (int num = 1; num <= n; ++num) {
            int bucketIdx = (num - 1) / BUCKET_SIZE;
            if (bucketIdx == data.size()) {
                data.push_back({});
                index.push_back(num);
            }

            data.back().push_back(num);
        }
    }
    
    int fetch(int k) {
        int bucketIdx = upper_bound(index.begin(), index.end(), k) - index.begin() - 1;
        int elem = data[bucketIdx][k - index[bucketIdx]];

        data[bucketIdx].erase(data[bucketIdx].begin() + (k - index[bucketIdx]));

        for (int i = bucketIdx + 1; i < index.size(); ++i) --index[i];

        if (data.back().size() >= BUCKET_SIZE) {
            data.push_back({});
            index.push_back(totalElems);
        }

        data.back().push_back(elem);

        if (data[bucketIdx].empty()) {
            data.erase(data.begin() + bucketIdx);
            index.erase(index.begin() + bucketIdx);
        }

        return elem;
    }
};

/**
 * Your MRUQueue object will be instantiated and called as such:
 * MRUQueue* obj = new MRUQueue(n);
 * int param_1 = obj->fetch(k);
 */