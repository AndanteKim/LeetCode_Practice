class Solution:
    def highFive(self, items: List[List[int]]) -> List[List[int]]:
        records = defaultdict(list)

        for id, score in items:
            records[id].append(score)
        
        ans = []
        for id in records:
            records[id].sort(reverse = True)
            ans.append([id, sum(records[id][:5]) // 5])
        
        ans.sort()
        return ans