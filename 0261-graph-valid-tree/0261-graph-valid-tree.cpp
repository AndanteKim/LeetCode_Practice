class Solution {
public:
    bool validTree(int n, vector<vector<int>>& edges) {
        // Iterative DFS
        if (edges.size() != n - 1)
            return false;

        vector graph(n, vector<int>());

        for (const vector<int>& edge : edges){
            graph[edge[0]].push_back(edge[1]);
            graph[edge[1]].push_back(edge[0]);
        }

        unordered_map<int, int> parent{{0, -1}};
        stack<int> st;
        st.push(0);

        while (!st.empty()){
            int node = st.top(); st.pop();
            
            for (int neighbor : graph[node]){
                if (neighbor == parent[node])
                    continue;
                
                if (parent.count(neighbor)) return false;
                parent[neighbor] = node;
                st.push(neighbor);
            }
        }
        
        return parent.size() == n;
    }
};