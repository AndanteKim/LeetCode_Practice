class Solution:
    def dfs(self, i: int, prev: int, dp: Dict[Tuple[int, int], int], arr1: List[int], arr2: List[int]) -> int:
        if i == len(arr1):
            return 0
        
        if (i, prev) in dp:
            return dp[(i, prev)]
        
        cost = float('inf')
        
        if arr1[i] > prev:
            cost = self.dfs(i + 1, arr1[i], dp, arr1, arr2)
            
        idx = bisect_right(arr2, prev)
        
        if idx < len(arr2):
            cost = min(cost, 1 + self.dfs(i + 1, arr2[idx], dp, arr1, arr2))
        
        dp[(i, prev)] = cost
        return cost
    
    def makeArrayIncreasing(self, arr1: List[int], arr2: List[int]) -> int:
        arr2.sort()
        dp = dict()
        
        ans = self.dfs(0, -1, dp, arr1, arr2)
        return ans if ans < float('inf') else -1