class Solution:
    def addToArrayForm(self, num: List[int], k: int) -> List[int]:
        
        for i in range(len(num) - 1, -1, -1):
            k, d = divmod(k, 10)
            carry, num[i] = divmod(num[i] + d, 10)
            k += carry
            if not k:
                break
                
        if k:
            num = list(map(int, str(k))) + num
        return num