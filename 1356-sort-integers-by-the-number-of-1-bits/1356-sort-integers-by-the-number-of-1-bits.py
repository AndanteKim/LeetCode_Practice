class Solution:
    def sortByBits(self, arr: List[int]) -> List[int]:
        ans, trans = [], sorted([bin(elem)[2:] for elem in arr], key = lambda x: (x.count('1'), int(x, 2)))
        for binary in trans:
            i, decimal, binary = 0, 0, [*binary]
            while binary:
                decimal += (int(binary.pop()) * (2 ** i))
                i += 1
                
            ans.append(decimal)
        
        return ans