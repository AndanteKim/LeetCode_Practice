class Solution:
    def videoStitching(self, clips: List[List[int]], time: int) -> int:
        clips.sort()
        
        end, end2, ans = -1, 0, 0
        for i, j in clips:
            if end2 >= time or i > end2:
                break
            elif end < i <= end2:
                ans, end = ans + 1, end2
            end2 = max(end2, j)
        
        return ans if end2 >= time else -1