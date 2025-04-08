class Solution:
    def minimumOperations(self, nums: List[int]) -> int:
        ans, counter, i, n = 0, Counter(nums), 0, len(nums)

        while True:
            unique_count = 0
            for key, val in counter.items():
                if val == 1:
                    unique_count += 1
            
            if unique_count == len(counter):
                break

            for _ in range(min(3, n - i)):
                counter[nums[i]] -= 1
                if counter[nums[i]] == 0:
                    del counter[nums[i]]
                i += 1

            ans += 1

        return ans