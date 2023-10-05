class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        vector<pair<int, int>> sortedSpells;
        int n = spells.size(), m = potions.size();
        for (int i = 0; i < n; ++i)
            sortedSpells.push_back({spells[i], i});
        
        sort(sortedSpells.begin(), sortedSpells.end());
        sort(potions.begin(), potions.end());
        
        int pointIndex = m - 1;
        vector<int> ans(n);
        for (auto& [spell, i] : sortedSpells){
            while (pointIndex >= 0 && success <= (long long) spell * potions[pointIndex]){
                --pointIndex;
            }
            ans[i] = m - (pointIndex + 1);
        }
        
        return ans;
    }
};