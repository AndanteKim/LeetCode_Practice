class Solution:
    def findSmallestRegion(self, regions: List[List[str]], region1: str, region2: str) -> str:
        graph = defaultdict(str)
        
        for i in range(len(regions)):
            for j in range(1, len(regions[i])):
                graph[regions[i][j]] = regions[i][0]
        
        r1_ancestor = region1
        while r1_ancestor:
            r2_ancestor = region2
            while r2_ancestor:
                if r1_ancestor == r2_ancestor:
                    return r1_ancestor
                r2_ancestor = graph[r2_ancestor]
            r1_ancestor = graph[r1_ancestor]
        
        return ""