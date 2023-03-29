class Solution {
public:
    int maxSatisfaction(vector<int>& satisfaction) {
        sort(satisfaction.begin(), satisfaction.end());
        if (satisfaction.back() < 0) return 0;
        int ans = 0;
        for (int i = 0; i < satisfaction.size() - 1; ++i){
            int time = 1, curr = 0;
            for (int j = i; j < satisfaction.size(); ++j){
                curr += satisfaction[j] * time;
                ++time;
            }
            ans = max(ans, curr);
        }
        return ans;
    }
};