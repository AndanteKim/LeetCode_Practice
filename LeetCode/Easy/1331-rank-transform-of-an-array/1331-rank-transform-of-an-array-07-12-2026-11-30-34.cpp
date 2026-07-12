class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        set<int> nums(arr.begin(), arr.end());
        int rank = 1;
        unordered_map<int, int> rankMap;
        for (int num : nums) {
            rankMap[num] = rank++;
        }

        vector<int> ans(arr.size());

        for (int i = 0; i < arr.size(); ++i) {
            ans[i] = rankMap[arr[i]];
        }

        return ans;
    }
};