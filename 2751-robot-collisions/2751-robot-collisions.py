class Solution:
    def survivedRobotsHealths(self, positions: List[int], healths: List[int], directions: str) -> List[int]:
        n, ans = len(positions), []
        indices, stack = list(range(n)), []
        
        # Sort indices based on their positions
        indices.sort(key = lambda x: positions[x])
        
        for curr_idx in indices:
            # Add right-moving robots to the stack
            if directions[curr_idx] == "R":
                stack.append(curr_idx)
                
            else:
                while stack and healths[curr_idx] > 0:
                    # Pop the top robot from the stack for collision check
                    top_idx = stack.pop()
                    
                    if healths[top_idx] > healths[curr_idx]:
                        # Top robot survivies, current robot is destroyed
                        healths[top_idx] -= 1
                        healths[curr_idx] = 0
                        stack.append(top_idx)
                    elif healths[top_idx] < healths[curr_idx]:
                        # Current robot survives, top robot is destroyed
                        healths[curr_idx] -= 1
                        healths[top_idx] = 0
                    else:
                        # Both robots are destroyed
                        healths[curr_idx] = 0
                        healths[top_idx] = 0
                        
        # Collect surviving robots
        for idx in range(n):
            if healths[idx] > 0:
                ans.append(healths[idx])
                
        return ans