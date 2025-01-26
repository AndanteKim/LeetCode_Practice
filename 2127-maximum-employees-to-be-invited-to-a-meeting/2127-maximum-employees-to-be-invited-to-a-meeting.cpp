class Solution {
public:
    int maximumInvitations(vector<int>& favorite) {
        int n = favorite.size();
        vector<int> indegree(n);
        
        // Calculate in-degree for each node
        for (int p = 0; p < n; ++p)
            ++indegree[favorite[p]];

        // Topological sorting to remove non-cycle nodes
        queue<int> q;
        for (int p = 0; p < n; ++p)
            if (indegree[p] == 0)
                q.push(p);

        vector<int> depth(n, 1);    // Depth of each node
        while (!q.empty()){
            int currNode = q.front(); q.pop();
            int nextNode = favorite[currNode];
            depth[nextNode] = max(depth[nextNode], depth[currNode] + 1);

            --indegree[nextNode];
            if (indegree[nextNode] == 0)
                q.push(nextNode);
        }

        int longestCycle = 0, twoCycleInvitations = 0;

        // Detect cycles
        for (int person = 0; person < n; ++person){
            if (indegree[person] == 0)   // Already processed
                continue;
            
            int cycleLength = 0, current = person;
            while (indegree[current] != 0){
                indegree[current] = 0;  // Mark as visited
                ++cycleLength;
                current = favorite[current];
            }
            
            if (cycleLength == 2)
                // For 2-cycles, add the depth of both nodes
                twoCycleInvitations += depth[person] + depth[favorite[person]];
            else
                longestCycle = max(longestCycle, cycleLength);
        }

        return max(longestCycle, twoCycleInvitations);
    }
};