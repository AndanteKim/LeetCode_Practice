class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        if (trust.size() == 0 && n == 1) return n;
        
        unordered_map<int, set<int>> trust_give;
        unordered_map<int, set<int>> trust_receive;
        int ans = -1;
        for (const auto &t:trust){
            trust_give[t[0]].insert(t[1]);
            trust_receive[t[1]].insert(t[0]);
        }
        
        vector<int> candidates;
        
        for (const auto m: trust_receive){
            if (m.second.size() == n - 1) candidates.push_back(m.first);
        }
        
        for (const auto candidate: candidates){
            if (trust_give[candidate].empty()) ans = candidate;
        }
        
        return ans;
    }
};