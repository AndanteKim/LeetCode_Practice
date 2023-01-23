class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        if (trust.size() < n - 1) return -1;
        int indegree[1001] = {0};
        int outdegree[1001] = {0};
        
        
        for (const auto &t : trust){
            ++outdegree[t[0]];
            ++indegree[t[1]];
        }
        
        for (int i = 1; i <= n; ++i){
            if (indegree[i] == n - 1 && outdegree[i] == 0) return i;
        }
        return -1;
    }
};