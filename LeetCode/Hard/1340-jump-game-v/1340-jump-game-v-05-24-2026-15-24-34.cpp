class Solution {
public:
    int maxJumps(vector<int>& arr, int d) {
        int n = arr.size();
        unordered_map<int, int> seen;

        function<void(int)> dfs = [&](int pos) -> void {
            if (seen.contains(pos)) return;

            seen[pos] = 1;
            int k = pos - 1;
            for (;k >= 0 && pos - k <= d && arr[pos] > arr[k]; --k) {
                dfs(k);
                seen[pos] = max(seen[pos], seen[k] + 1);
            }
        
            k = pos + 1;
            for (;k < n && k - pos <= d && arr[pos] > arr[k]; ++k) {
                dfs(k);
                seen[pos] = max(seen[pos], seen[k] + 1);
            }
        };

        for (int i = 0; i < n; ++i) dfs(i);

        int ans = 0;
        for (const auto& [_, freq] : seen) ans = max(ans, freq);

        return ans;
    }
};