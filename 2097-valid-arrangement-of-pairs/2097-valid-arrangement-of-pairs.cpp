class Solution {
public:
    vector<vector<int>> validArrangement(vector<vector<int>>& pairs) {
        unordered_map<int, deque<int>> adjacencyMatrix;
        unordered_map<int, int> indegree, outdegree;
        
        // Build the adjacency list and track in-degrees and out-degrees
        for (const auto& p : pairs){
            int start = p[0], end = p[1];
            adjacencyMatrix[start].push_back(end);
            ++outdegree[start];
            ++indegree[end];
        }
        
        vector<int> processes;
        
        // Helper lambda function for DFS traversal
        function<void(int)> visit = [&](int node){
            while (!adjacencyMatrix[node].empty()){
                int nextNode = adjacencyMatrix[node].front();
                adjacencyMatrix[node].pop_front();
                visit(nextNode);
            }
            processes.push_back(node);
        };
        
        
        // Find the start node (outdegree == 1 + indegree)
        int startNode = -1;
        for (const auto& [node, count] : outdegree){
            if (count == indegree[node] + 1){
                startNode = node;
                break;
            }
        }
        
        // If no such node exists, start from the first pair's first element
        if (startNode == -1)
            startNode = pairs[0][0];
        
        // Start DFS traversal
        visit(startNode);
        
        // Reverse the result since DFS gives us the path in reverse
        reverse(processes.begin(), processes.end());
        
        vector<vector<int>> ans;
        // Construct the result pairs
        for (int i = 1; i < processes.size(); ++i)
            ans.push_back(vector<int>{processes[i - 1], processes[i]});
        
        return ans;
    }
};