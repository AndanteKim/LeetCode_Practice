class Solution:
    def removeInterval(self, intervals: List[List[int]], toBeRemoved: List[int]) -> List[List[int]]:
        remove_start, remove_end = toBeRemoved
        ans = []
        
        for start, end in intervals:
            # If there are no overlaps, add the interval to the list as is.
            if start > remove_end or end < remove_start:
                ans.append([start, end])
            else:
                # Is there a left interval we need to keep?
                if start < remove_start:
                    ans.append([start, remove_start])
                
                # Is there a right interval we need to keep?
                if end > remove_end:
                    ans.append([remove_end, end])
        
        return ans