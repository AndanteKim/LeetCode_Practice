class Solution {
private:
    // topological sort nodes in a graph, return vector<int>{} if a cycle exists
    vector<int> topologicalSort(vector<vector<int>>& graph, vector<int>& indegree){
        vector<int> visited;
        stack<int> stack;
        for (int node = 0; node < graph.size(); ++node) if (indegree[node] == 0) stack.push(node);
        
        while (!stack.empty()){
            int curr = stack.top();
            stack.pop();
            visited.push_back(curr);
            
            for (int neighbor : graph[curr]){
                --indegree[neighbor];
                if (indegree[neighbor] == 0) stack.push(neighbor);
            }
        }
        
        return visited.size() == graph.size()? visited : vector<int>{};
    }
    
public:
    vector<int> sortItems(int n, int m, vector<int>& group, vector<vector<int>>& beforeItems) {
        // If an item belongs to zero group, assign it a unique group id
        int groupId = m;
        for (int i = 0; i < n; ++i){
            if (group[i] == -1){
                group[i] = groupId;
                ++groupId;
            }
        }
        
        // sort all items regardless of group dependencies
        vector itemGraph(n, vector<int>()), groupGraph(groupId, vector<int>());
        // sort all items regardless of item dependencies
        vector<int> itemIndegree(n), groupIndegree(groupId);
        
        for (int curr = 0; curr < n; ++curr){
            for (int prev : beforeItems[curr]){
                // Each (prev -> curr) represents an edge in the item graph
                itemGraph[prev].push_back(curr);
                ++itemIndegree[curr];
                // If they belong to differentiate groups, add an edge in the groupGraph
                if (group[curr] != group[prev]){
                    groupGraph[group[prev]].push_back(group[curr]);
                    ++groupIndegree[group[curr]];
                }
            }
        }
        
        vector<int> itemOrder = topologicalSort(itemGraph, itemIndegree), groupOrder = topologicalSort(groupGraph, groupIndegree);
        if (itemOrder.empty() || groupOrder.empty()) return {};
        
        // Items are sorted regardless of groups, we need to differentiate them by the groups they belong to
        map<int, vector<int>> orderedGroups;
        for (int item : itemOrder){
            orderedGroups[group[item]].push_back(item);
        }
        
        // concatenate sorted items in all sorted groups [group 1, group 2, ...] -> [(item 1, item 2, ...), ...]
        vector<int> ans;
        for (int groupIndex : groupOrder) ans.insert(ans.end(), orderedGroups[groupIndex].begin(), orderedGroups[groupIndex].end());
        return ans;
    }
};