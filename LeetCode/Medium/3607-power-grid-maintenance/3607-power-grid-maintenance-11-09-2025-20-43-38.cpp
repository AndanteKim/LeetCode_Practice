class DSU {
private:
    vector<int> parents;

public:
    DSU(int size){
        parents.resize(size);
        iota(parents.begin(), parents.end(), 0);
    }

    int find(int x) {
        if (parents[x] != x) parents[x] = find(parents[x]);
        return parents[x];
    }

    void join(int u, int v) {
        parents[find(v)] = parents[find(u)];
    }
};


class Solution {
public:
    vector<int> processQueries(int c, vector<vector<int>>& connections, vector<vector<int>>& queries) {
        DSU *dsu = new DSU(c + 1);
        for (const auto& conn : connections) {
            dsu -> join(conn[0], conn[1]);
        }

        vector<bool> online(c + 1, true);
        vector<int> offlineCounts(c + 1, 0);
        unordered_map<int, int> minOnlineStations;

        for (auto& q : queries) {
            int op = q[0], x = q[1];

            if (op == 2) {
                online[x] = false;
                ++offlineCounts[x];
            }
        }

        for (int i = 1; i <= c; ++i) {
            int root = dsu -> find(i);

            if (!minOnlineStations.count(root)) minOnlineStations[root] = -1;
            
            int station = minOnlineStations[root];
            if (online[i]) {
                if (station == -1 || station > i) minOnlineStations[root] = i;
            }
        }

        vector<int> ans;

        for (int i = (int)queries.size() - 1; i >= 0; --i){
            int op = queries[i][0], x = queries[i][1];
            int root = dsu -> find(x);
            int station = minOnlineStations[root];

            if (op == 1) {
                if (online[x]) ans.push_back(x);
                else ans.push_back(station);
            }

            if (op == 2) {
                if (offlineCounts[x] > 1) --offlineCounts[x];
                else{
                    online[x] = true;
                    if (station == -1 || station > x) minOnlineStations[root] = x;
                }
            }
        }

        reverse(ans.begin(), ans.end());
        return ans;
    }
};