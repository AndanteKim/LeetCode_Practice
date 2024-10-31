class Solution:
    def minimumTotalDistance(self, robot: List[int], factory: List[List[int]]) -> int:
        # Sort robots and factories by position
        robot.sort()
        factory.sort()
        factory_positions = []
        
        # Flatten factory positions according to their capacities
        for f in factory:
            factory_positions.extend([f[0]] * f[1])
            
        robot_count, factory_count = len(robot), len(factory_positions)
        prev_dp, dp = [0] * (factory_count + 1), [0] * (factory_count + 1)
        
        # Fill DP table using two rows for optimization
        for i in range(robot_count - 1, -1, -1):
            # No factories left case
            if i != robot_count - 1:
                prev_dp[-1] = int(1e12)
            
            # Initialize current row
            dp[-1] = int(1e12)
            for j in range(factory_count - 1, -1, -1):
                # Assign current robot to current factory
                assign = abs(robot[i] - factory_positions[j]) + prev_dp[j + 1]
                
                # Skip current factory for this robot
                skip = dp[j + 1]
                
                # Take the minimum option
                dp[j] = min(assign, skip)
            
            # Move to next robot
            prev_dp = dp[:]
            
        # Return minimum distance starting from the first robot
        return prev_dp[0]