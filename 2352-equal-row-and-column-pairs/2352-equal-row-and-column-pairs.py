class Solution:
    def convert_to_keys(self, arr: List[List[int]]) -> tuple[List[int]]:
        return tuple(arr)
    def equalPairs(self, grid: List[List[int]]) -> int:
        dic = defaultdict(int)
        for row in grid:
            dic[self.convert_to_keys(row)] += 1
        
        dic2 = defaultdict(int)
        
        for col in zip(*grid):
            dic2[self.convert_to_keys(col)] += 1
        
        ans = 0
        for arr in dic:
            ans += dic[arr] * dic2[arr]
        
        return ans