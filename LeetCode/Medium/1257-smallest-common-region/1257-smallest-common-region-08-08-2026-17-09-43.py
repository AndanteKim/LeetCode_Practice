class Solution:
    def findSmallestRegion(self, regions: List[List[str]], region1: str, region2: str) -> str:
        def fetch_paths(curr: str) -> List[str]:
            paths = [curr]

            while curr in ancestors:
                parent = ancestors[curr]
                paths.append(parent)
                curr = parent

            paths.reverse()
            return paths
        
        ancestors = dict()
        for region in regions:
            parent = region[0]
            for i in range(1, len(region)):
                ancestors[region[i]] = parent

        p1, p2 = fetch_paths(region1), fetch_paths(region2)
        i, j = 0, 0
        ans = ""

        while i < len(p1) and j < len(p2) and p1[i] == p2[j]:
            ans = p1[i]
            i += 1
            j += 1

        return ans