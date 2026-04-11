class Solution {
public:
    int minimumDistance(vector<int>& nums) {
        unordered_map<int, vector<int>> groups;

        for (int i = 0; i < nums.size(); ++i) {
            groups[nums[i]].push_back(i);
        }

        int ans = std::numeric_limits<int>::max();
        for (const auto& [_, group] : groups) {
            if (group.size() < 2) continue;

            for (int i = 0; i < group.size() - 2; ++i){
                int curr = abs(group[i] - group[i + 1]) + abs(group[i + 1] - group[i + 2]) + abs(group[i + 2] - group[i]);
                ans = min(ans, curr);
            }
        }

        return ans == std::numeric_limits<int>::max()? -1 : ans;
    }
};