class Solution:
    def suggestedProducts(self, products: List[str], searchWord: str) -> List[List[str]]:
        products.sort()
        ans = []
        bs_start, n = 0, len(products)
        prefix = ""
        for c in searchWord:
            prefix += c
            
            start = bisect_left(products, prefix, bs_start, n)
            ans.append([])
            
            for i in range(start, min(start + 3, n)):
                if not products[i][:len(prefix)] == prefix:
                    continue
                ans[-1].append(products[i])
            
            bs_start = start
        return ans