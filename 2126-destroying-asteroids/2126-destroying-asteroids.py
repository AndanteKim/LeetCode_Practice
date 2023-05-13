class Solution:
    def asteroidsDestroyed(self, mass: int, asteroids: List[int]) -> bool:
        asteroids.sort()
        new_planet = mass
        for asteroid in asteroids:
            if new_planet >= asteroid:
                new_planet += asteroid
            else:
                return False
        return True