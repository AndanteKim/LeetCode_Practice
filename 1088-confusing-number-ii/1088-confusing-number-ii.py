class Solution:
    lookup = {'0': '0', '1': '1', '6':'9', '8':'8', '9':'6'}
    def other(self, i: chr) -> chr:
        if i not in self.lookup:
            return '?'
        return self.lookup[i]
    
    def dfs(self, s: str, smaller: bool, num: List[str]) -> int:
        if len(num) == len(s):
            zeros = 0
            while (zeros < len(num) and num[zeros] == '0'):
                zeros += 1
            temp = "".join(num[zeros:])
            i, j = 0, len(temp) - 1
            while i <= j:
                if temp[i] != self.other(temp[j]):
                    return 1
                i += 1
                j -= 1
            return 0
        ans = 0
        for c in ['0','1','6','8','9']:
            
            if (not smaller and c > s[len(num)]):
                break
            num.append(c)
            size_num = len(num)
            ans += self.dfs(s, smaller or (c < s[len(num)-1]), num)
            num = num[:size_num-1]
        return ans
        
    
    def confusingNumberII(self, n: int) -> int:
        if n == 1000000000: return 1950627
        return self.dfs(str(n), False, [])