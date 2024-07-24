class Solution {
public:
    vector<int> sortJumbled(vector<int>& mapping, vector<int>& nums) {
        vector<pair<int, int>> storePairs;
        
        for (int i = 0; i < nums.size(); ++i){
            
            // Start making changes from the units place.
            int temp = nums[i], place = 1;
            
            // If the value initially is 0, return mapping[0] and index.
            if (temp == 0){
                storePairs.push_back({mapping[0], i});
                continue;
            }
            
            // Repeat the process for units, tenths, hundredths, .., places.
            int mappedValue = 0;
            while (temp != 0){
                mappedValue = place * mapping[temp % 10] + mappedValue;
                place *= 10;
                temp /= 10;
            }
            
            storePairs.push_back({mappedValue, i});
        }
        
        // Sort the array in non-decreasing order by the first value (default).
        sort(storePairs.begin(), storePairs.end());
        vector<int> ans;
        for (auto& [_, idx] : storePairs)
            ans.push_back(nums[idx]);
        
        return ans;
    }
};