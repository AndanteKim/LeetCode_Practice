class Solution:
    def doesValidArrayExist(self, derived: List[int]) -> bool:
        XOR = 0
        
        for num in derived:
            XOR ^= num

        return True if XOR == 0 else False