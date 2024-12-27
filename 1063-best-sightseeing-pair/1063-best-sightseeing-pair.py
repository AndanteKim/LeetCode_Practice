class Solution:
    def maxScoreSightseeingPair(self, values: List[int]) -> int:
        n, max_score = len(values), 0
        
        # Initialize a list to store the maximum left scores up to each index
        max_left_score = [0] * n

        # The left score at the first index is just the value of the first element.
        max_left_score[0] = values[0]

        for i in range(1, n):
            curr_right_score, curr_left_score = values[i] - i, values[i] + i
            # Update the maximum score by combining the best left score so far with the current right score.
            max_score = max(max_score, max_left_score[i - 1] + curr_right_score)
            
            # Update the maximum left score up to the current index
            max_left_score[i] = max(max_left_score[i - 1], curr_left_score)

        return max_score