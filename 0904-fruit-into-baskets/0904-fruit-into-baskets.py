class Solution:
    def totalFruit(self, fruits: List[int]) -> int:
        baskets_2 = defaultdict(int)
        left, quantity = 0, 0
        for right in range(len(fruits)):
            baskets_2[fruits[right]] += 1
            
            while left < right and len(baskets_2) > 2:
                baskets_2[fruits[left]] -= 1
                if baskets_2[fruits[left]] == 0:
                    del baskets_2[fruits[left]]
                left += 1
            
            quantity = max(quantity, sum(baskets_2.values()))
            
        return quantity