class Solution:
    def removeInterval(self, intervals: List[List[int]], toBeRemoved: List[int]) -> List[List[int]]:
        ans = []
        
        for start, end in intervals:
            if toBeRemoved[0] <= start and end <= toBeRemoved[1]:
                continue
            elif start > toBeRemoved[1] or end < toBeRemoved[0]:
                ans.append([start, end])
            elif start < toBeRemoved[0] and end > toBeRemoved[0]:
                ans.append([start, toBeRemoved[0]])
                if end > toBeRemoved[1]:
                    ans.append([toBeRemoved[1], end])
            else:
                if start < toBeRemoved[0]:
                    ans.append([start, toBeRemoved[0]])
                ans.append([toBeRemoved[1], end])
                
        return ans