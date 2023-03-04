class Solution:
    def mostCompetitive(self, nums: List[int], k: int) -> List[int]:
        queue = deque()
        additionalCount = len(nums) - k
        for i in range(len(nums)):
            while queue and queue[-1] > nums[i] and additionalCount > 0:
                queue.pop()
                additionalCount -= 1
            queue.append(nums[i])
        
        result = []
        for i in range(k):
            result.append(queue.popleft())
        
        return result