class Solution:
    def summaryRanges(self, nums: List[int]) -> List[str]:
        if not nums:
            return []
        interval, ans = [nums[0], nums[0]], []
        n, i = len(nums), 1
        if n == 1:
            return [f'{nums[0]}']
        
        for i in range(1, n):
            if nums[i] - nums[i - 1] == 1:
                interval[1] += 1
            else:
                if interval[0] == interval[1]:
                    ans.append(f'{interval[0]}')
                else:
                    ans.append(f'{interval[0]}->{interval[1]}')
                interval[0], interval[1] = nums[i], nums[i]
            
            if i == n - 1:
                if interval[0] == interval[1]:
                    ans.append(f'{interval[0]}')
                else:
                    ans.append(f'{interval[0]}->{interval[1]}')
            
        return ans