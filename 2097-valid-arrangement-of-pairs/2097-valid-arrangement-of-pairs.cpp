class Solution {
public:
    vector<vector<int>> validArrangement(vector<vector<int>>& pairs) {
        unordered_map<int, deque<int>> adjacencyMatrix;
        unordered_map<int, int> inDegree, outDegree;
        
        // Build the adjacency list and track in-degrees and out-degrees
        for (const auto& p : pairs){
            int start = p[0], end = p[1];
            adjacencyMatrix[start].push_back(end);
            ++outDegree[start];
            ++inDegree[end];
        }
        
        // Find the start node (outDegree = inDegree + 1)
        int startNode = -1;
        for (const auto& [node, outCount] : outDegree){
            if (outCount == inDegree[node] + 1){
                startNode = node;
                break;
            }
        }
        
        // If no such node exists, start from the first pair's first element
        if (startNode == -1) startNode = pairs[0][0];
        
        stack<int> nodeStack; nodeStack.push(startNode);
        vector<int> result;
        
        // Iterative DFS using stack
        while (!nodeStack.empty()){
            int node = nodeStack.top();
            
            if (!adjacencyMatrix[node].empty()){
                // Visit the next node
                int nextNode = adjacencyMatrix[node].front();
                adjacencyMatrix[node].pop_front();
                nodeStack.push(nextNode);
            }
            else{
                // No more neighbors to visit, add node to result
                result.push_back(node);
                nodeStack.pop();
            }
        }
        
        // Reverse the result since we collected nodes in reverse order
        reverse(result.begin(), result.end());
        
        // Construct the result pairs
        vector<vector<int>> pairedResult;
        for (int i = 1; i < result.size(); ++i)
            pairedResult.push_back({result[i - 1], result[i]});
        
        return pairedResult;
    }
};