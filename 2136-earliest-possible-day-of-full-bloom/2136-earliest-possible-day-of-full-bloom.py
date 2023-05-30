class Solution:
    def earliestFullBloom(self, plantTime: List[int], growTime: List[int]) -> int:
        cur_plant_time, ans = 0, 0
        indices = sorted(range(len(plantTime)), key = lambda x: -growTime[x])
        
        for i in indices:
            cur_plant_time += plantTime[i]
            ans = max(ans, cur_plant_time + growTime[i])
        return ans