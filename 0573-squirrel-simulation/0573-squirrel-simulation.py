class Solution:
    def minDistance(self, height: int, width: int, tree: List[int], squirrel: List[int], nuts: List[List[int]]) -> int:
        def distance(x: int, y: int, target: List[int]):
            return abs(x - target[0]) + abs(y - target[1])
        
        total_dist, squirrel_to_closest = 0, float('inf')
        for x, y in nuts:
            total_dist +=  2 * distance(x, y, tree)
            # Find the closest distance in which a nut is located from a squirrel, considering to deduct one-way distance between a nut and tree
            squirrel_to_closest = min(squirrel_to_closest, -distance(x, y, tree) + distance(x, y, squirrel))
            
        return total_dist + squirrel_to_closest