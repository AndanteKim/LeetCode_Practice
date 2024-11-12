class Solution:
    def maximumBeauty(self, items: List[List[int]], queries: List[int]) -> List[int]:
        ans = [0] * len(queries)
        
        # sort both items and queries in ascending order
        items.sort()
        queries_with_idx = [(q, i) for i, q in enumerate(queries)]
        queries_with_idx.sort()
        
        item_idx, max_beauty, n = 0, 0, len(items)
        
        for i in range(len(queries)):
            query, original_idx = queries_with_idx[i]
            
            while item_idx < n and items[item_idx][0] <= query:
                max_beauty = max(max_beauty, items[item_idx][1])
                item_idx += 1
            ans[original_idx] = max_beauty
        
        return ans