class Solution:
    def leftmostBuildingQueries(self, heights: List[int], queries: List[List[int]]) -> List[int]:
        def search(height: int) -> int:
            ans, left, right = -1, 0, len(stack) - 1

            while left <= right:
                mid = (left + right) >> 1
                if stack[mid][0] > height:
                    ans = max(ans, mid)
                    left = mid + 1
                else:
                    right = mid - 1
            return ans

        m, n = len(heights), len(queries)
        new_queries, stack = [[] for _ in range(m)], []
        ans = [-1] * n
        
        for curr, (a, b) in enumerate(queries):
            if a > b:
                a, b = b, a

            if a == b or heights[a] < heights[b]:
                ans[curr] = b
            else:
                new_queries[b].append((heights[a], curr))
            
        for i in range(m - 1, -1, -1):
            stack_sz = len(stack)

            for a, b in new_queries[i]:
                pos = search(a)

                if pos < stack_sz and pos >= 0:
                    ans[b] = stack[pos][1]
            
            while stack and stack[-1][0] <= heights[i]:
                stack.pop()
            stack.append((heights[i], i))

        return ans