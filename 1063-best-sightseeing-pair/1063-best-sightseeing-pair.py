class Solution:
    def maxScoreSightseeingPair(self, values: List[int]) -> int:
        # Space optimized Kadane algorithm
        # The left score is initially just the value of the first element.
        max_left_score, n = values[0], len(values)
        max_score = 0

        for i in range(1, n):
            curr_left_score, curr_right_score = values[i] + i, values[i] - i

            # Update the maximum score by combining the best left score so far with the current right score.
            max_score = max(max_score, max_left_score + curr_right_score)
            
            # Update the maximum left score up to the current index.
            max_left_score = max(max_left_score, curr_left_score)
            
        return max_score

