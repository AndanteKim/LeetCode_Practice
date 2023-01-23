class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        if (trust.size() < n - 1) return -1;
        int indegree[n+1], outdegree[n+1];
        fill_n(indegree, n+1, 0);
        fill_n(outdegree, n+1, 0);
        
        
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