class Solution {
public:
    int closestTarget(vector<string>& words, string target, int startIndex) {
        int n = words.size(), ans = n;

        for (int i = 0; i < n; ++i) {
            if (words[i] == target) {
                ans = min(ans, min(abs(i - startIndex), n - abs(i - startIndex)));
            }
        }

        return ans < n? ans : -1;
    }
};