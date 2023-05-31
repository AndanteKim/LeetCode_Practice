typedef long long ll;

class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        int n = spells.size();
        vector<int> ans(n, 0);
        sort(potions.begin(), potions.end());
        
        for (int i = 0; i < n; ++i){
            int left = 0, right = potions.size();
            int curr = right;
            while (left < right){
                int mid = left + (right - left) / 2;
                if ((ll)spells[i] * potions[mid] < success) left = mid + 1;
                else right = mid;
            }
            ans[i] = curr - left;
        }
        
        return ans;
    }
};