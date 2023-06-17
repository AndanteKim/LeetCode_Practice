class Solution {
private:
    struct defaultVal{
        int val = INT_MAX;
    };
    
public:
    int makeArrayIncreasing(vector<int>& arr1, vector<int>& arr2) {
        unordered_map<int, defaultVal> dp;
        dp[-1].val = 0;
        sort(arr2.begin(), arr2.end());
        int n = arr2.size();
        
        for (int i = 0; i < arr1.size(); ++i){
            unordered_map<int, defaultVal> newDp;
            for (auto& [prev, container] : dp){
                if (arr1[i] > prev){
                    newDp[arr1[i]].val = min(container.val, newDp[arr1[i]].val);
                }
                int idx = upper_bound(arr2.begin(), arr2.end(), prev) - arr2.begin();
                if (idx < n) newDp[arr2[idx]].val = min(newDp[arr2[idx]].val, 1 + container.val);
            }
            dp = newDp;
        }
        
        if (dp.empty()) return -1;
        
        int ans = INT_MAX;
        for (auto& [key, container] : dp){
            ans = min(ans, container.val);
        }
        return ans;
    }
};