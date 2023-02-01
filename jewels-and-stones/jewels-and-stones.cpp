class Solution {
public:
    int numJewelsInStones(string jewels, string stones) {
        unordered_map<char, int> counter;
        int ans = 0;
        for (const char&c : stones) ++counter[c];
        for (const char&c : jewels) ans += counter[c];
            
        return ans;
    }
};