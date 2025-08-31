class Solution:
    def shortestDistanceColor(self, colors: List[int], queries: List[List[int]]) -> List[int]:
        seen, n = defaultdict(list), len(queries)
        for i, c in enumerate(colors):
            seen[c].append(i)

        ans = [float('inf')] * n
        for i, (target, color) in enumerate(queries):
            if len(seen[color]) == 0:
                ans[i] = -1
                continue

            idx_list = seen[color]

            # Use binary search
            insert = bisect_left(idx_list, target)

            # Compare the index on the left and right of insert
            # make sure it'll not fall out of the idx_list
            left_nearest = abs(idx_list[max(insert - 1, 0)] - target)
            right_nearest = abs(idx_list[min(insert, len(idx_list) - 1)] - target)
            ans[i] = min(left_nearest, right_nearest)
        
        return ans