class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        vector<int> ans(spells.size());
        vector<long long> multiple(potions.size());
        sort(potions.begin(), potions.end());

        for (int i = 0; i < spells.size(); ++i){
            int count = (int)(potions.size()) - static_cast<int>(lower_bound(potions.begin(), potions.end(), (double)success / spells[i]) - potions.begin()); 
            ans[i] = count;
        }
        
        return ans;
    }
};