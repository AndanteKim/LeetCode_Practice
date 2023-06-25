class Solution:
    def solve(self, curr_city: int, remain_fuel: int, finish: int, memo: Dict[Tuple[int], int], locations: List[int]) -> int:
        if remain_fuel < 0:
            return 0
        if (curr_city, remain_fuel) in memo:
            return memo[(curr_city, remain_fuel)]
        
        ans = 0
        if curr_city == finish:
            ans = 1
        
        for next_city in range(self.n):
            if next_city != curr_city:
                ans = (ans + self.solve(next_city, remain_fuel - abs(locations[curr_city] - locations[next_city]), finish, memo, locations)) % 1000000007
        
        memo[(curr_city, remain_fuel)] = ans
        return ans
    
    def countRoutes(self, locations: List[int], start: int, finish: int, fuel: int) -> int:
        ans, self.n = 0, len(locations)
        
        memo = dict()
        return self.solve(start, fuel, finish, memo, locations)
        
        