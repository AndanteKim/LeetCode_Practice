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
        auto comp = [](pair<double, int>& p1, pair<double, int>& p2){return p1.first < p2.first;};
        priority_queue<pair<double, int>, vector<pair<double, int>>, decltype(comp)> pq(comp);
        pq.push({1.0, start});
        
        while (!pq.empty()){
            auto [currProb, currNode] = pq.top();
            pq.pop();
            if (currNode == end) return currProb;
            for (auto& [nextNode, nextProb] : graph[currNode]){
                if (currProb * nextProb > maxProb[nextNode]){
                    maxProb[nextNode] = currProb * nextProb;
                    pq.push({maxProb[nextNode], nextNode});
                }
            }
        }
        
        return 0.0;
    }
};