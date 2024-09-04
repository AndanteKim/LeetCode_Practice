class Solution:
    def robotSim(self, commands: List[int], obstacles: List[List[int]]) -> int:
        # change data structure of obstacles as set
        obstacles = set([tuple(obstacle) for obstacle in obstacles])
        
        # Directions: North, East, South, West
        directions, curr_turn, curr_coordinates = [(0, 1), (1, 0), (0, -1), (-1, 0)], 0, [0, 0]
        max_dist = 0
        
        for command in commands:
            if command == -1:
                curr_turn = (curr_turn + 1) % 4
                continue
            elif command == -2:
                curr_turn = (curr_turn - 1) % 4
                continue
            else:
                # If we'll meet the obstacles, then updated it to sign there's an obstacle.
                updated = False
                for k in range(1, min(command + 1, 10)):
                    if tuple([curr_coordinates[0] + directions[curr_turn][0] * k, \
                        curr_coordinates[1] + directions[curr_turn][1] * k]) in obstacles:
                        if directions[curr_turn][0] == 1:
                            curr_coordinates[0] += directions[curr_turn][0] * k - 1
                        elif directions[curr_turn][0] == -1:
                            curr_coordinates[0] += directions[curr_turn][0] * k + 1
                        elif directions[curr_turn][1] == 1:
                            curr_coordinates[1] += directions[curr_turn][1] * k - 1
                        else:
                            curr_coordinates[1] += directions[curr_turn][1] * k + 1
                        updated = True
                        break
                    
                if not updated:
                    # Update the coordinates to move
                    curr_coordinates[0] += directions[curr_turn][0] * command
                    curr_coordinates[1] += directions[curr_turn][1] * command
                
                max_dist = max(max_dist, curr_coordinates[0] ** 2 + curr_coordinates[1] ** 2)
            
        return max_dist