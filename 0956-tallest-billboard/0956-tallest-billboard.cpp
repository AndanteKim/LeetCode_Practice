class Solution {
private:
    unordered_map<int, int> helper(vector<int>& rods, int left, int right){
        set<pair<int, int>> states;
        states.insert({0, 0});
        for (int i = left; i < right; ++i){
            set<pair<int, int>> newStates;
            for (auto& [l, r] : states){
                newStates.insert({l + rods[i], r});
                newStates.insert({l, r + rods[i]});
            }
            
            for (auto& [l, r] : newStates){
                states.insert({l, r});
            }
            
        }
        
        unordered_map<int, int> dp;
        for (auto& [l, r] : states) dp[l - r] = max(dp[l - r], l);
        return dp;
    }
    
public:
    int tallestBillboard(vector<int>& rods) {
        int n = rods.size();
        
        unordered_map<int, int> firstHalf = helper(rods, 0, n / 2), secondHalf = helper(rods, n / 2, n);
        int answer = 0;
        for (auto& [key, diff] : firstHalf){
            if (secondHalf.find(-key) != secondHalf.end())
                answer = max(answer, diff + secondHalf[-key]);
        }
        return answer;
    }
};
    
