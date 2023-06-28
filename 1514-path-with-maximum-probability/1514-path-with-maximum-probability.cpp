class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start, int end) {
        vector<double> maxProb(n, 0.0);
        maxProb[start] = 1.0;
        
        for (int i = 0; i < n - 1; ++i){
            bool hasUpdate = false;
            for (int j = 0; j < edges.size(); ++j){
                int u = edges[j][0], v = edges[j][1];
                double currProb = succProb[j];
                if (maxProb[u] * currProb > maxProb[v]){
                    maxProb[v] = maxProb[u] * currProb;
                    hasUpdate = true;
                }
                
                if (maxProb[v] * currProb > maxProb[u]){
                    maxProb[u] = maxProb[v] * currProb;
                    hasUpdate = true;
                }
            }
            
            if (!hasUpdate) break;
        }
        
        return maxProb[end];
    }
};