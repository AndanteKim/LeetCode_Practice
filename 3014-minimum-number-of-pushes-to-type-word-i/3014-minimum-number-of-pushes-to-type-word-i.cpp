class Solution {
public:
    int minimumPushes(string word) {
        int ans = 0, push = 0;

        for (const char& c : word) {
            ans += (push++ / 8 + 1);
        }

        return ans;
    }
};