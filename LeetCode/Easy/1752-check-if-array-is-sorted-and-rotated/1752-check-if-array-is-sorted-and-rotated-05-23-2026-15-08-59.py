class Solution:
    def check(self, nums: List[int]) -> bool:
        n, q = len(nums), deque(sorted([n for n in nums]))

        for _ in range(n):
            q.append(q.popleft())

            if list(q) == nums:
                return True

        return False