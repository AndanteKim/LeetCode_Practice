class Solution:
    def findKthPositive(self, arr: List[int], k: int) -> int:
        track = [False] * 2000
        
        for num in arr:
            track[num-1] = True
        
        ans, i = 0, 0
        while i < k and ans < 2000:
            if not track[ans]:
                i += 1
            ans += 1
        
        return ans
        
        