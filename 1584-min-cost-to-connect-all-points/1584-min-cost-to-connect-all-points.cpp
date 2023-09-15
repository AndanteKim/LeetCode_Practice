class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n = points.size();
        
        // min_heap to store minimum edge at top
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        pq.push({0, 0});
        int mstCost = 0, edgesUsed = 0;
        
        // Track nodes which are included in MST
        vector<bool> InMST(n);
        
        while (edgesUsed < n){
            auto [weight, currNode] = pq.top();
            pq.pop();
            
            // If node was already include in MST we will discard this edge
            if (InMST[currNode]) continue;
            InMST[currNode] = true;
            ++edgesUsed;
            mstCost += weight;
            
            for (int nextNode = 0; nextNode < n; ++nextNode){
                // If next node is not in MST, then edge from curr node
                // to next node can be pushed in the priority queue
                if (!InMST[nextNode]){
                    int nextWeight = abs(points[currNode][0] - points[nextNode][0]) + abs(points[currNode][1] - points[nextNode][1]);
                    pq.push({nextWeight, nextNode});
                }
            }
        }
        
        return mstCost;
    }
};