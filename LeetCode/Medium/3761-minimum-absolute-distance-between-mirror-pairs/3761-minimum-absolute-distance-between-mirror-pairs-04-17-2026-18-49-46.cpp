class Solution {
public:
    int minMirrorPairDistance(vector<int>& nums) {
        unordered_map<int, int> prev;
        int ans = std::numeric_limits<int>::max();

        for (int i = 0; i < nums.size(); ++i) {
            if (prev.contains(nums[i])){
                ans = min(ans, i - prev[nums[i]]);
            }

            string num = to_string(nums[i]);
            reverse(num.begin(), num.end());
            prev[stoi(num)] = i;
        }

        return ans == std::numeric_limits<int>::max()? -1 : ans;
    }
};