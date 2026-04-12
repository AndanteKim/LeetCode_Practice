class Solution:
    def pourWater(self, heights: List[int], volume: int, k: int) -> List[int]:
        n, ans = len(heights), heights[:]
        for _ in range(volume):
            for d in (-1, 1):
                i = best = k
                while 0 <= i + d < n and ans[i + d] <= ans[i]:
                    if ans[i + d] < ans[i]:
                        best = i + d
                    i += d
                
                if best != k:
                    ans[best] += 1
                    break
            else:
                ans[k] += 1
        
        return ans