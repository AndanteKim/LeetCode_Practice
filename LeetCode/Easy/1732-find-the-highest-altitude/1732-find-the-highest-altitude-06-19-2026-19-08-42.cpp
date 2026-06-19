class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int ans = 0, currSum = 0;

        for (int a : gain) {
            currSum += a;
            ans = max(ans, currSum);
        }

        return ans;
    }
};