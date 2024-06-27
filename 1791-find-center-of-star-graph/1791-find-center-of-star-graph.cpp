class Solution {
public:
    int findCenter(vector<vector<int>>& edges) {
        vector<int> firstEdge = edges[0], secondEdge = edges[1];
        
        return find(secondEdge.begin(), secondEdge.end(), firstEdge[0]) != secondEdge.end()? firstEdge[0] : firstEdge[1];
    }
};