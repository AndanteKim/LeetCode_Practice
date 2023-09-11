class Solution:
    def groupThePeople(self, groupSizes: List[int]) -> List[List[int]]:
        table, n = defaultdict(list), len(groupSizes)
        
        for i in range(n):
            table[groupSizes[i]].append(i)
        
        ans = []
        
        for sz, ids in table.items():
            curr = []
            for idx in ids:
                if len(curr) < sz: 
                    curr.append(idx)
                else:
                    ans.append(curr[:])
                    curr = [idx]
            if curr:
                ans.append(curr[:])
                curr.clear()
        
        return ans