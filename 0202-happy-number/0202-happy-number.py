class Solution:
    def isHappy(self, n: int) -> bool:
        lookup, happy = set(), n
        
        while happy != 1:
            temp = 0
            while happy != 0:
                temp += ((happy % 10) ** 2)
                happy //= 10
            
            if temp not in lookup:
                lookup.add(temp)
            else:
                return False
            
            happy = temp
            
        return True