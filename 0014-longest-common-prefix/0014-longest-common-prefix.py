class Solution:
    def longestCommonPrefix(self, strs: List[str]) -> str:
        ans, n = "", len(strs)
        
        for i_1 in range(len(strs[0])):
            ch = strs[0][i_1]
            for i_2 in range(1, n):
                if i_1 >= len(strs[i_2]) or ch != strs[i_2][i_1]:
                    return ans
            ans += ch
        
        return ans