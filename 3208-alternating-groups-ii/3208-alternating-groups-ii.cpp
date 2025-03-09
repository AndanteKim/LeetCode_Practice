class Solution {
public:
    int numberOfAlternatingGroups(vector<int>& colors, int k) {
        int ans = 0, prev = -1, n = colors.size();
        int left = 0;

        for (int right = 0; right < n + k - 1; ++right){
            while (prev == colors[right % n] && left < right) ++left;

            prev = colors[right % n];

            if (right - left + 1 >= k) ++ans;
        }

        return ans;
    }
};