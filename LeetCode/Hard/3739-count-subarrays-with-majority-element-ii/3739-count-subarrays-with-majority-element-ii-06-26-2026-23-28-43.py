class Solution:
    def countMajoritySubarrays(self, nums: List[int], target: int) -> int:
        n = len(nums)

        # Prefix sum from -n to n
        pre = [0] * (2 * n + 1)
        pre[n] = 1
        cnt = n
        ans = pre_sum = 0

        for i in range(n):
            if nums[i] == target:
                pre_sum += pre[cnt]
                cnt += 1
                pre[cnt] += 1
            else:
                cnt -= 1
                pre_sum -= pre[cnt]
                pre[cnt] += 1
            
            ans += pre_sum

        return ans