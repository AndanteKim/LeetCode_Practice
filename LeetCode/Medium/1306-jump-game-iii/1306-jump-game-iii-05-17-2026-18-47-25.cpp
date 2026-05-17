class Solution {
public:
    bool canReach(vector<int>& arr, int start) {
        int n = arr.size();
        queue<int> q;
        q.push(start);

        while (!q.empty()) {
            int node = q.front(); q.pop();
            if (arr[node] == 0) return true;

            if (arr[node] < 0) continue;

            for (int nxtNode : vector<int>{node - arr[node], node + arr[node]}) {
                if (0 <= nxtNode && nxtNode < n) q.push(nxtNode);
            }

            arr[node] = -arr[node];
        }

        return false;
    }
};