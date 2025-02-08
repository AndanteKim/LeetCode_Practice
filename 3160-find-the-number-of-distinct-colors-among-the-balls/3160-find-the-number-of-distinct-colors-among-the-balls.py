class Solution:
    def queryResults(self, limit: int, queries: List[List[int]]) -> List[int]:
        n, color_map, ball_map = len(queries), dict(), dict()
        ans = [0] * n

        # Iterate through queries
        for i, (ball, color) in enumerate(queries):
            # Check if ball is already colored
            if ball in ball_map:
                # Decrement count of the previous color on the ball
                prev_color = ball_map[ball]
                color_map[prev_color] -= 1

                # If there are no balls with previous color left, remove color from color map
                if color_map[prev_color] == 0:
                    del color_map[prev_color]
                
            # Set color of ball to the new color
            ball_map[ball] = color
        
            # Increment the count of the new color
            color_map[color] = color_map.get(color, 0) + 1
            ans[i] = len(color_map)

        return ans