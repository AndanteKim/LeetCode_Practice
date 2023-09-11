class Solution:
    def groupThePeople(self, groupSizes: List[int]) -> List[List[int]]:
        ans, n = [], len(groupSizes)
        
        size_to_group = [[] for _ in range(n + 1)]
        for i in range(0, n):
            size_to_group[groupSizes[i]].append(i)
            
            if len(size_to_group[groupSizes[i]]) == groupSizes[i]:
                ans.append(size_to_group[groupSizes[i]][:])
                size_to_group[groupSizes[i]].clear()
        
        return ans