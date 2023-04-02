#define ll long long

class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        int rows = spells.size(), cols = potions.size();
        sort(potions.begin(), potions.end());
        vector<int> ans;
        for (int i = 0; i < rows; ++i){
            ll target = ceil((double)success / spells[i]);
            int cnt = cols - (lower_bound(potions.begin(), potions.end(), target) - potions.begin());
            ans.push_back(cnt);
        }
        
        return ans;
    }
};