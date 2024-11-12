class Solution:
    def maximumBeauty(self, items: List[List[int]], queries: List[int]) -> List[int]:
        reduced_items = defaultdict(int)
        for price, beauty in items:
            reduced_items[price] = max(reduced_items[price], beauty)
        
        max_items = []
        for price, item in reduced_items.items():
            max_items.append([price, item])
        max_items.sort()
        max_beauty = 0
        for i in range(len(max_items)):
            max_items[i][1] = max(max_beauty, max_items[i][1])
            max_beauty = max(max_beauty, max_items[i][1])
        
        n = len(queries)
        ans = [0] * n
        for i in range(n):
            if queries[i] < max_items[0][0]:
                continue
            
            max_idx = bisect_right(max_items, [queries[i], float('inf')])
            ans[i] = max_items[max_idx - 1][1]
            
        return ans