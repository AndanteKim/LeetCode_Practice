class Solution:
    def maximumLength(self, nums: List[int]) -> int:
        freq = dict()

        for num in nums:
            freq[num] = freq.get(num, 0) + 1

        one_cnt = freq.get(1, 0)

        ans = one_cnt if one_cnt % 2 else one_cnt - 1
        freq.pop(1, None)

        for num in freq:
            curr, x = 0, num

            while x in freq and freq[x] > 1:
                curr += 2
                x *= x
            
            ans = max(ans, curr + (1 if x in freq else -1))
        
        return ans