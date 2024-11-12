class Solution:
    def maximumBeauty(self, items: List[List[int]], queries: List[int]) -> List[int]:
        def bin_search(items: List[int], target_price: int) -> int:
            l, r = 0, len(items) - 1
            max_beauty = 0
            
            while l <= r:
                mid = (l + r) >> 1
                
                if target_price < items[mid][0]:
                    r = mid - 1
                else:
                    # Found viable price. Keep moving to right
                    max_beauty = max(max_beauty, items[mid][1])
                    l = mid + 1
            return max_beauty
        
        # Sort and store max beauty
        items.sort()
        ans, mx = [0] * len(queries), items[0][1]
        
        for item in items:
            mx = max(mx, item[1])
            item[1] = mx
            
        for i in range(len(queries)):
            ans[i] = bin_search(items, queries[i])
            
        return ans