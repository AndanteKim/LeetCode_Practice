class Solution:
    def minimumTotalDistance(self, robot: List[int], factory: List[List[int]]) -> int:
        robot_count = len(robot)
        # Flatten factory positions according to their capacities
        factory_positions = []
        
        # Sort robots and factories by position
        robot.sort()
        factory.sort()
        for f in factory:
            factory_positions.extend([f[0]] * f[1])
        factory_count = len(factory_positions)
        dp = [[0] * (factory_count + 1) for _ in range(robot_count + 1)]
        
        # Initialize base cases
        for i in range(robot_count):
            dp[i][factory_count] = int(1e12)    # No factories left
            
        # Fill DP table bottom-up
        for i in range(robot_count - 1, -1, -1):
            for j in range(factory_count - 1, -1, -1):
                # Option 1: Assign current robot to current factory
                assign = abs(robot[i] - factory_positions[j]) + dp[i + 1][j + 1]
                
                # Option 2: Skip current factory for the current robot
                skip = dp[i][j + 1]
                
                # Take the minimum option
                dp[i][j] = min(assign, skip)
                
        # Minimum distance starting from the first robot and factory
        return dp[0][0]