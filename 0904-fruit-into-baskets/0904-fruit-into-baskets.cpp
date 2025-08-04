class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int left = 0, n = fruits.size(), ans = 0;
        unordered_map<int, int> seen;
        for (int right = 0; right < n; ++right){
            while (seen.count(fruits[right]) == 0 && seen.size() >= 2){
                --seen[fruits[left]];
                if (seen[fruits[left]] == 0) seen.erase(fruits[left]);
                ++left;
            }

            ++seen[fruits[right]];
            ans = max(ans, right - left + 1);
        }

        return ans;
    }
};