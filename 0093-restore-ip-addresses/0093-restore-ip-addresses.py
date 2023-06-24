class Solution:
    def backtrack(self, start: int, addr: str, boundary: int, s: str, ans: List[str]) -> None:
        if boundary == 0:
            if start == len(s):
                ans.append(addr[:-1])
            return
        
        if start + 1 <= len(s):
            self.backtrack(start + 1, addr + s[start] +'.', boundary - 1, s, ans)
        if start + 2 <= len(s) and s[start] != '0':
            self.backtrack(start + 2, addr + s[start] + s[start + 1] + '.', boundary - 1, s, ans)
        if start + 3 <= len(s) and s[start] != '0' and 0 <= int(s[start:start+3]) <= 255:
            self.backtrack(start + 3, addr + s[start] + s[start + 1] + s[start + 2] + '.', boundary - 1, s, ans)
    
    def restoreIpAddresses(self, s: str) -> List[str]:
        ans = []
        self.backtrack(0, "", 4, s, ans)
        
        return ans