class Solution:
    def earliestFinishTime(self, landStartTime: List[int], landDuration: List[int], waterStartTime: List[int], waterDuration: List[int]) -> int:
        def solve(s1: List[int], d1: List[int], s2: List[int], d2: List[int]) -> int:
            f1 = float('inf')

            for i in range(len(s1)):
                f1 = min(f1, s1[i] + d1[i])
            
            f2 = float('inf')

            for i in range(len(s2)):
                f2 = min(f2, max(f1, s2[i]) + d2[i])

            return f2

        land_water = solve(landStartTime, landDuration, waterStartTime, waterDuration)
        water_land = solve(waterStartTime, waterDuration, landStartTime, landDuration)
        return min(land_water, water_land)