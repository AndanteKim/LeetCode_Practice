class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        int ans = 0;
        unordered_set<int> seen;

        for (int num : nums){
            if (seen.count(num)) continue;

            if (num < k) return -1;
            else if (num > k) ++ans;
            seen.insert(num);
        }

        return ans;
    }
};