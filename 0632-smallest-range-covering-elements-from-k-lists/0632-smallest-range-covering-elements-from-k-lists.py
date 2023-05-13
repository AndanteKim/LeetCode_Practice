class Solution:
    def smallestRange(self, nums: List[List[int]]) -> List[int]:
        heap = []
        max_value = 0
        
        for i in range(len(nums)):
            heappush(heap, [nums[i][0], i, 0])
            max_value = max(max_value, nums[i][0])
            
        ans = [heap[0][0], max_value]
        
        while True:
            _, row, col = heappop(heap)
            if col == len(nums[row]) - 1:
                break
            
            next_num = nums[row][col + 1]
            heappush(heap, [next_num, row, col + 1])
            max_value = max(max_value, next_num)
            
            if max_value - heap[0][0] < ans[1] - ans[0]:
                ans = [heap[0][0], max_value]
        
        return ans