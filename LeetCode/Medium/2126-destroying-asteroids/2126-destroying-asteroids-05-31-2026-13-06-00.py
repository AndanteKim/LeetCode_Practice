class Solution:
    def asteroidsDestroyed(self, mass: int, asteroids: List[int]) -> bool:
        curr = mass
        asteroids.sort()

        for a in asteroids:
            if curr < a:
                return False
            curr += a

        return True