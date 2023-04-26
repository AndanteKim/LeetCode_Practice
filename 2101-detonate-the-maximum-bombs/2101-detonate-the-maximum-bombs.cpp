#define ll long long
class Solution {
public:
    int maximumDetonation(vector<vector<int>>& bombs) {
        int n = bombs.size();
        vector<vector<int>> adj(n);
        //sort(bombs.begin(), bombs.end(), [](vector<int>& a, vector<int>& b){return a[2] < b[2];});
        for (int i = 0; i < n - 1; ++i){
            for (int j = i + 1; j < n; ++j){
                int x1 = bombs[i][0], y1 = bombs[i][1], r1 = bombs[i][2];
                int x2 = bombs[j][0], y2 = bombs[j][1], r2 = bombs[j][2];
                double d = sqrt(((ll)(x2 - x1) * (x2 - x1) + (ll)(y2 - y1) * (y2 - y1)));
                if (d <= r1) adj[i].push_back(j);
                if (d <= r2) adj[j].push_back(i);
            }
        }
        
        int ans = 0;
        unordered_set<int> d;
        for (int b0 = 0; b0 < n; ++b0){
            if (d.find(b0) != d.end() or d.size() == n) continue;
            
            queue<int> queue{{b0}};
            unordered_set<int> v{{b0}};
            while (!queue.empty()){
                int b1 = queue.front();
                queue.pop();
                d.insert(b1);
                for (int b2 : adj[b1]){
                    if (v.find(b2) == v.end()){
                        v.insert(b2);
                        queue.push(b2);
                    }
                }
            }
            int cnt = v.size();
            ans = max(ans, cnt);
            
        }
        
        return ans;
    }
};