class Solution:
    def threeConsecutiveOdds(self, arr: List[int]) -> bool:
        n = len(arr)
        
        for i in range(n - 2):
            product = arr[i] * arr[i + 1] * arr[i + 2]
            
            # Check if the product is odd
            if product % 2:
                return True
            
        return False