class Solution:
    def maxSatisfied(self, customers: List[int], grumpy: List[int], minutes: int) -> int:
        happy = sum((c * (g ^ 1) for c, g in zip(customers, grumpy)))
        max_happy = happy
        
        for i in range(len(customers)):
            if i >= minutes and grumpy[i - minutes] == 1:
                happy -= customers[i - minutes]
            
            if grumpy[i] == 1:
                happy += customers[i]
            
            max_happy = max(max_happy, happy)
            
        return max_happy