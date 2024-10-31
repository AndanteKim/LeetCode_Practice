class Solution:
    def minimumTotalDistance(self, robot: List[int], factory: List[List[int]]) -> int:
        def dp(robot_idx: int, factory_idx: int) -> int:
            if memo[robot_idx][factory_idx] != -1:
                return memo[robot_idx][factory_idx]
            
            # All robots assigned
            if robot_idx == robot_count:
                memo[robot_idx][factory_idx] = 0
                return 0
            
            # No factories left to assign
            if factory_idx == factory_count:
                memo[robot_idx][factory_idx] = int(1e12)
                return int(1e12)
            
            # Option 1: Assign current robot to current factory
            assign = abs(robot[robot_idx] - factory_positions[factory_idx]) + dp(robot_idx + 1, factory_idx + 1)

            # Option 2: Skip current factory for the current robot
            skip = dp(robot_idx, factory_idx + 1)
            
            memo[robot_idx][factory_idx] = min(assign, skip)
            # Take the option with the minimum distance.
            return memo[robot_idx][factory_idx]
            
        # Sort robots and factories by position
        robot.sort()
        factory.sort(key = lambda x: x[0])
        
        # Flatten factory positions according to their capacities
        factory_positions = []
        for f in factory:
            factory_positions.extend([f[0]] * f[1])
        
        robot_count, factory_count = len(robot), len(factory_positions)
        memo = [[-1] * (factory_count + 1) for _ in range(robot_count + 1)]
        # Recursively calculate minimum total distance
        return dp(0, 0)