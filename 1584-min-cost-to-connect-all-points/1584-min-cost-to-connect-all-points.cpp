class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        int edgesUsed = 0, mstCost = 0, n = points.size();
        vector<int> minDist(n, INT_MAX);
        vector<bool> inMST(n);
        minDist[0] = 0;
        
        while (edgesUsed < n){
            int currMinEdge = INT_MAX, currNode = -1;
            
            // pick least weight node which is not in MST
            for (int node = 0; node < n; ++node){
                if (!inMST[node] && currMinEdge > minDist[node]){
                    currMinEdge = minDist[node];
                    currNode = node;
                }
            }
            
            mstCost += currMinEdge;
            ++edgesUsed;
            inMST[currNode] = true;
            
            // update adjacent nodes of current node
            for (int nextNode = 0; nextNode < n; ++nextNode){
                int weight = abs(points[currNode][0] - points[nextNode][0]) + abs(points[currNode][1] - points[nextNode][1]);
                if(!inMST[nextNode] && minDist[nextNode] > weight)
                    minDist[nextNode] = weight;
            }
        }
        
        return mstCost;
    }
};