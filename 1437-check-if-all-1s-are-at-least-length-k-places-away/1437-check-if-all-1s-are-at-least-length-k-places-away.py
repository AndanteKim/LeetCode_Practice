class Solution:
    def kLengthApart(self, nums: List[int], k: int) -> bool:
        min_length, detect_one = float('inf'), []

        for i in range(len(nums)):
            if nums[i] == 1:
                detect_one.append(i)

        for i in range(len(detect_one) - 1):
            min_length = min(min_length, detect_one[i + 1] - detect_one[i] - 1)

        return min_length >= k
        