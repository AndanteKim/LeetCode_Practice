class Solution:
    def sortItems(self, n: int, m: int, group: List[int], beforeItems: List[List[int]]) -> List[int]:
        # If an item belongs to zero group, assign it a unique group id
        group_id = m
        for i in range(n):
            if group[i] == -1:
                group[i] = group_id
                group_id += 1
        
        # sort all item regardless of group dependencies
        item_graph = [[] for _ in range(n)]
        item_indegree = [0] * n
        
        # sort all groups regardless of item dependencies
        group_graph = [[] for _ in range(group_id)]
        group_indegree = [0] * group_id
        
        for curr in range(n):
            for prev in beforeItems[curr]:
                # Each prev -> curr represents an edge in the item graph
                item_graph[prev].append(curr)
                item_indegree[curr] += 1
            
                # If they belong to different groups, add an edge in the group graph
                if group[curr] != group[prev]:
                    group_graph[group[prev]].append(group[curr])
                    group_indegree[group[curr]] += 1
                    
        # Topological sort nodes in graph, return [] if a cycle exists
        def topologicalSort(graph: List[List[int]], indegree: List[int]) -> List[int]:
            visited = []
            stack = [node for node in range(len(graph)) if indegree[node] == 0]
            while stack:
                curr = stack.pop()
                visited.append(curr)
                for neighbor in graph[curr]:
                    indegree[neighbor] -= 1
                    if indegree[neighbor] == 0:
                        stack.append(neighbor)
            return visited if len(visited) == len(graph) else []
        
        item_order = topologicalSort(item_graph, item_indegree)
        group_order = topologicalSort(group_graph, group_indegree)
        
        if not item_order or not group_order:
            return []
        
        # Items are sorted regardless of groups, we need to differentiate them by the groups they belong to
        ordered_groups = defaultdict(list)
        for item in item_order:
            ordered_groups[group[item]].append(item)
        
        # Concatenate sorted items in all sorted groups
        # [group 1, group 2, ... ] -> [(item 1, item 2, ...), (item 1, item 2, ...), ...]
        ans = []
        for group_index in group_order:
            ans += ordered_groups[group_index]
        return ans