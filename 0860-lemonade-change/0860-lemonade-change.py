class Solution:
    def lemonadeChange(self, bills: List[int]) -> bool:
        # Index 0: $5 ~ Index 2: $20
        currencies, mapping_idx_to_dollar = [0] * 3, {0 : 5, 1 : 10, 2 : 20}
        mapping_dollar_to_idx = {5 : 0, 10 : 1, 20: 2}
        
        for i in range(len(bills)):
            change = bills[i] - 5
            for currency in range(2, -1, -1):
                if change == 0:
                    break
                units = min(change // mapping_idx_to_dollar[currency], currencies[currency])
                currencies[currency] -= units
                change -= mapping_idx_to_dollar[currency] * units
            
            if change > 0:
                return False
            currencies[mapping_dollar_to_idx[bills[i]]] += 1
            
        return True