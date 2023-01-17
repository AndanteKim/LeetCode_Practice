class Solution:
    def longestOnes(self, nums: List[int], k: int) -> int:
        left, cnt, ans = 0, 0, 0
        
        for right in range(len(nums)):
            if nums[right] == 0:
                if cnt == k:
                    while nums[left] != 0:
                        left += 1
                    left += 1
                else:
                    cnt += 1
                
            print(f'{right}, {left}, {nums[right]}')
            ans = max(ans, right - left + 1)            
        
        return ans