class Solution {
public:
    int maxDistance(vector<int>& colors) {
        int ans = 0, n = colors.size();
        for (int i = 0; i < n; ++i) {
            if (colors[i] != colors[0]) ans = max(ans, i);
            if (colors[i] != colors.back()) ans = max(ans, n - 1 - i);
        }

        return ans;
    }
};