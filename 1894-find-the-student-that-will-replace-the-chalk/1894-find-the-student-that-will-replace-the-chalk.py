class Solution:
    def chalkReplacer(self, chalk: List[int], k: int) -> int:
        self.n = len(chalk)
        prefix_sum = [0] * self.n
        prefix_sum[0] = chalk[0]
        
        for i in range(1, self.n):
            prefix_sum[i] = prefix_sum[i - 1] + chalk[i]
            
        remain = k % prefix_sum[-1]
        
        return self.bin_search(prefix_sum, remain)
    
    def bin_search(self, arr: List[int], remain: int) -> int:
        low, high = 0, self.n
        
        while low < high:
            mid = (low + high) >> 1
            if arr[mid] <= remain:
                low = mid + 1
            else:
                high = mid
        
        return high