class Solution {
public:
    int findLucky(vector<int>& arr) {
        int ans = -1;
        unordered_map<int, int> freq;

        for (int num : arr) ++freq[num];
        for (const auto& [num, val] : freq){
            if (num == val) ans = max(ans, num);
        }

        return ans;
    }
};