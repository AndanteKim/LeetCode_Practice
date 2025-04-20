class Solution {
public:
    int numRabbits(vector<int>& answers) {
        unordered_map<int, int> count;
        for (int num : answers)
            ++count[num];

        int ans = 0;

        for (const auto& [k, v] : count){
            ans += ((k + 1) - v % (k + 1)) % (k + 1) + v;
        }

        return ans;
    }
};