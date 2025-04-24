class Solution:
    def countCompleteSubarrays(self, nums: List[int]) -> int:
        ans, right = 0, 0
        n, cnt = len(nums), dict()
        distinct = len(set(nums))

        for left in range(n):
            if left > 0:
                remove = nums[left - 1]
                cnt[remove] -= 1
                if cnt[remove] == 0:
                    cnt.pop(remove)
            
            while right < n and len(cnt) < distinct:
                add = nums[right]
                cnt[add] = cnt.get(add, 0) + 1
                right += 1
            
            if len(cnt) == distinct:
                ans += n - right + 1
        
        return ans
