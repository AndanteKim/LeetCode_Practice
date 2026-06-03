class Solution:
    def earliestFinishTime(self, landStartTime: List[int], landDuration: List[int], waterStartTime: List[int], waterDuration: List[int]) -> int:
        def solve(start1: List[int], duration1: List[int], start2: List[int], duration2: List[int]) -> int:
            f1 = float('inf')
            for i in range(len(start1)):
                f1 = min(f1, start1[i] + duration1[i])
            
            f2 = float('inf')
            for i in range(len(start2)):
                f2 = min(f2, max(start2[i], f1) + duration2[i])
            
            return f2
        
        land_water = solve(
            landStartTime, landDuration, waterStartTime, waterDuration
        )

        water_land = solve(
            waterStartTime, waterDuration, landStartTime, landDuration
        )

        return min(land_water, water_land)