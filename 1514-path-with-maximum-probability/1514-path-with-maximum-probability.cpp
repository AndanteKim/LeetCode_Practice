class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start, int end) {
        vector<vector<pair<int, double>>> graph(n);
        for (int i = 0; i < edges.size(); ++i){
            graph[edges[i][0]].push_back({edges[i][1], succProb[i]});
            graph[edges[i][1]].push_back({edges[i][0], succProb[i]});
        }
        
        vector<double> maxProb(n, 0.0);
        maxProb[start] = 1.0;
        queue<int> queue{{start}};
        
        while (!queue.empty()){
            int currNode = queue.front();
            queue.pop();
            
            for (auto& [nextNode, currProb] : graph[currNode]){
                if (maxProb[currNode] * currProb > maxProb[nextNode]){
                    maxProb[nextNode] = maxProb[currNode] * currProb;
                    queue.push(nextNode);
                }
            }
        }
        
        return maxProb[end];
    }
};