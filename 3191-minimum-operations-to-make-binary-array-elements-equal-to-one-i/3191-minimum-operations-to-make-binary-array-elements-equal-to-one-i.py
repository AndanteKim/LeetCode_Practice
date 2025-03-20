class Solution:
    def minOperations(self, nums: List[int]) -> int:
        # Store indices of flip operations
        # Number of operations performed
        queue, ans = deque(), 0

        for i in range(len(nums)):
            # Remove expired flips (older than 3 indices)
            while queue and i > queue[0] + 2:
                queue.popleft()
            
            # If the current element needs flipping
            if (nums[i] + len(queue)) % 2 == 0:
                # Cannot flip a full triplet
                if i + 2 >= len(nums):
                    return -1
                ans += 1
                queue.append(i)

        return ans