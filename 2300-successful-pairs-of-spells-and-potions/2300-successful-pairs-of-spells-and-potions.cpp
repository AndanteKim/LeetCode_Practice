#define ll long long

class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        vector<pair<int, int>> SortedSpells;
        for (int i = 0; i < spells.size(); ++i){
            SortedSpells.push_back({spells[i], i});
        }
        sort(SortedSpells.begin(), SortedSpells.end());
        sort(potions.begin(), potions.end());
        vector<int> answer(spells.size(), 0);
        int m = potions.size(), potionIndex = m - 1;
        
        for (auto& [spell, index] : SortedSpells){
            while (potionIndex >= 0 && ((ll)spell * potions[potionIndex]) >= success)
                --potionIndex;
            answer[index] = m - (potionIndex + 1);
        }
        
        return answer;
    }
};