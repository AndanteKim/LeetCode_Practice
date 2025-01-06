class Solution:
    def minOperations(self, boxes: str) -> List[int]:
        n = len(boxes)
        balls_to_left, moves_to_left = 0, 0
        balls_to_right, moves_to_right = 0, 0
        ans = [0] * n

        # Single pass: Calculate moves from both left and right
        for i in range(n):
            # Left pass
            ans[i] += moves_to_left
            balls_to_left += int(boxes[i])
            moves_to_left += balls_to_left

            # Right pass
            j = n - 1 - i
            ans[j] += moves_to_right
            balls_to_right += int(boxes[j])
            moves_to_right += balls_to_right

        return ans