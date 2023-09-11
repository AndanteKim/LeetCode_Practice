class Solution:
    def groupThePeople(self, groupSizes: List[int]) -> List[List[int]]:
        groups = defaultdict(list)
        ans = []
        
        for pid, group_size in enumerate(groupSizes):
            groups[group_size].append(pid)
            if len(groups[group_size]) == group_size:
                ans.append(groups.pop(group_size));
        return ans