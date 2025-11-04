class Solution:
    def findXSum(self, nums: List[int], k: int, x: int) -> List[int]:
        ans, n = [], len(nums)

        for i in range(n - k + 1):
            cnt = Counter(nums[i : i + k])
            freq = sorted(cnt.items(), key = lambda x: (-x[1], -x[0]))
            x_sum = sum(key * val for key, val in freq[:x])
            ans.append(x_sum)

        return ans