class Solution:
    def findXSum(self, nums: List[int], k: int, x: int) -> List[int]:
        ans, freq, n = [], defaultdict(int), len(nums)

        for i in range(k):
            freq[nums[i]] = freq.get(nums[i], 0) + 1

        for i1 in range(k, n + 1):
            biggest = []
            for num, count in freq.items():
                biggest.append((num, count))

            
            biggest.sort(key = lambda x : (-x[1], -x[0]))
            
            curr = 0
            for i2 in range(min(len(biggest), x)):
                curr += biggest[i2][0] * biggest[i2][1]
            ans.append(curr)
            
            if i1 < n:
                freq[nums[i1]] = freq.get(nums[i1], 0) + 1
                freq[nums[i1 - k]] -= 1

        return ans