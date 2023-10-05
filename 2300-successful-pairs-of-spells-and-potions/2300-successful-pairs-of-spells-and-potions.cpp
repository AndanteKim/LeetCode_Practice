class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        vector<int> ans;
        int n = potions.size();
        sort(potions.begin(), potions.end());
        
        for (int spell : spells){
            int left = 0, right = n;
            while (left < right){
                int mid = left + ((right - left) >> 1);
                if (success <= (long long)potions[mid] * spell)
                    right = mid;
                else
                    left = mid + 1;
            }
            ans.push_back(n - left);
        }
        
        return ans;
    }
};