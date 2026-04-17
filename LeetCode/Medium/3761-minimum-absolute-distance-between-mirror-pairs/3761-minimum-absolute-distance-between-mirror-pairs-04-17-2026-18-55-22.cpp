class Solution {
public:
    int minMirrorPairDistance(vector<int>& nums) {
        auto reverseNum = [](int x) {
            int y = 0;

            while (x > 0) {
                y = y * 10 + x % 10;
                x /= 10;
            }

            return y;
        };
        
        
        unordered_map<int, int> prev;
        int ans = std::numeric_limits<int>::max();

        for (int i = 0; i < nums.size(); ++i) {
            if (prev.contains(nums[i])){
                ans = min(ans, i - prev[nums[i]]);
            }

            prev[reverseNum(nums[i])] = i;
        }

        return ans == std::numeric_limits<int>::max()? -1 : ans;
    }
};