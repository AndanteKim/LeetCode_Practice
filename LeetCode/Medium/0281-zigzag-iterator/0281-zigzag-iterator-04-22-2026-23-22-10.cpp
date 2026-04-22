class ZigzagIterator {
private:
    queue<int> q;

public:
    ZigzagIterator(vector<int>& v1, vector<int>& v2) {
        int m = v1.size(), n = v2.size();
        for (int i = 0, j = 0; i < m || j < n; ++i, ++j) {
            if (i < m) {
                q.push(v1[i]);
            }

            if (j < n) q.push(v2[j]);
        }
    }

    int next() {
        int nxt = q.front(); q.pop();
        return nxt;
    }

    bool hasNext() {
        return q.size() > 0;
    }
};

/**
 * Your ZigzagIterator object will be instantiated and called as such:
 * ZigzagIterator i(v1, v2);
 * while (i.hasNext()) cout << i.next();
 */