class Solution:
    def __init__(self):
        # Slightly larger than 2 * max coordinate value
        self.HASH_MULTIPLIER = 60001
        
    # Hash function to convert (x, y) coordinates to a unique integer value
    def _hash_coordinates(self, x: int, y: int) -> int:
        return x + self.HASH_MULTIPLIER * y
    
    def robotSim(self, commands: List[int], obstacles: List[List[int]]) -> int:
        # Store obstacles in an set for efficient lookup
        obstacle_set = {self._hash_coordinates(x, y) for x, y in obstacles}
        
        # Define direction vectors: North, East, South, West
        directions = [(0, 1), (1, 0), (0, -1), (-1, 0)]
        
        x, y = 0, 0
        max_dist_squared = 0
        
        # 0: North, 1: East, 2: South, 3: West
        curr_dir = 0
        
        for command in commands:
            # Turn right
            if command == -1:
                curr_dir = (curr_dir + 1) % 4
                continue
                
            # Turn left
            if command == -2:
                curr_dir = (curr_dir + 3) % 4
                continue
                
            # Move forward
            dx, dy = directions[curr_dir]
            
            for _ in range(command):
                next_x, next_y = x + dx, y + dy
                if self._hash_coordinates(next_x, next_y) in obstacle_set:
                    break
                x, y = next_x, next_y
                
            max_dist_squared = max(max_dist_squared, x * x + y * y)
            
        return max_dist_squared
        