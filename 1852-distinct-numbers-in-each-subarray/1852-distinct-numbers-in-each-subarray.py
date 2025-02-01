class Solution:
    def distinctNumbers(self, nums: List[int], k: int) -> List[int]:
        n = len(nums)
        ans = [0] * (n - k + 1)

        # Track frequency of numbers in current window
        freq = dict()

        # Process the first window
        for i in range(k):
            freq[nums[i]]= freq.get(nums[i], 0) + 1

        ans[0] = len(freq)

        # Slide window and update counts
        for pos in range(k, n):
            # Remove leftmost element
            left = nums[pos - k]
            freq[left] -= 1

            if freq[left] == 0:
                del freq[left]

            # Add rightmost element
            right = nums[pos]
            freq[right] = freq.get(right, 0) + 1

            ans[pos - k + 1] = len(freq)

        return ans  