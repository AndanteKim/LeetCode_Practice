class Solution:
    def asteroidCollision(self, asteroids: List[int]) -> List[int]:
        stack = []
        for asteroid in asteroids:
            is_destroyed = False
            while stack and stack[-1] > 0 and asteroid < 0:
                if abs(asteroid) > stack[-1]:
                    stack.pop()
                else:
                    is_destroyed = True
                    if asteroid + stack[-1] == 0:
                        stack.pop()
                    break
                
            if not is_destroyed:
                stack.append(asteroid)
            
        return stack