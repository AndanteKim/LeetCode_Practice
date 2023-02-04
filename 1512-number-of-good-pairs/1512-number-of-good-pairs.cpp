class Solution {
    int comb(int cases, int k){
        if (k == 0) return 1;
        else if (cases < k) return 0;
        return comb(cases-1, k-1) + comb(cases-1, k);
        
    }
    
public:
    int numIdenticalPairs(vector<int>& nums) {
        unordered_map<int, vector<int>> dic;
        int ans = 0;
        for (int i = 0; i < nums.size(); ++i){
            dic[nums[i]].push_back(i);
        }
        
        for (const auto&[key, value] : dic){
            ans += comb(value.size(), 2);
        }
        return ans;
    }
};