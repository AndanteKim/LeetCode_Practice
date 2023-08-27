class Solution:
    def maximumProduct(self, nums: List[int], k: int) -> int:
        ans = 1
        heapify(nums)
        while k > 0:
            elem = heappop(nums)
            elem += 1
            k -= 1
            heappush(nums, elem)
        
        for num in nums:
            ans = (ans * num) % (10 ** 9 + 7)
        return ans