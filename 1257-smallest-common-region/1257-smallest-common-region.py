class Solution:
    def findSmallestRegion(self, regions: List[List[str]], region1: str, region2: str) -> str:
        # Simplify LCA with Time complexity: O(max(m, n)), Space Complexity: O(m + n)
        parents = {region[i] : region[0] for region in regions for i in range(1, len(region))}
        
        r1 = region1
        ancestry_history = {r1}
        while r1 in parents:
            r1 = parents[r1]
            ancestry_history.add(r1)
            
        r2 = region2
        while r2 not in ancestry_history:
            r2 = parents[r2]
        return r2