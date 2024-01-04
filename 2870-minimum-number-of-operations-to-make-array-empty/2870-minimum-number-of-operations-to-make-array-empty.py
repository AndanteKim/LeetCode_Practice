class Solution:
    def minOperations(self, nums: List[int]) -> int:
        idx_table, ans = defaultdict(list), 0
        
        for i in range(len(nums)):
            idx_table[nums[i]].append(i)
            
        for num, l in idx_table.items():
            n, curr = len(l), float('inf')
            max_3 = n // 3
            
            for i in range(max_3 + 1):
                remain = n - (3 * i)
                if remain % 2 == 0:
                    curr = min(curr, i + (remain // 2))
            
            if curr == float('inf'):
                return -1
            ans += curr
       
        return ans
            