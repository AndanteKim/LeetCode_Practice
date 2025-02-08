class Solution:
    def makePrefSumNonNegative(self, nums: List[int]) -> int:
        ans, prefix_sum, min_heap = 0, 0, []

        for num in nums:
            # Push negative elements to the min_heap
            if num < 0:
                heappush(min_heap, num)
            prefix_sum += num
            
            # Pop the minimum element from the heap and subtract from the sum.
            if prefix_sum < 0:
                prefix_sum -= heappop(min_heap)

                # Increment the operations required
                ans += 1

        return ans