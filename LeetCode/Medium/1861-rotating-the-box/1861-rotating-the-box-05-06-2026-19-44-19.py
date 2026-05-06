class Solution:
    def rotateTheBox(self, boxGrid: List[List[str]]) -> List[List[str]]:
        m, n = len(boxGrid), len(boxGrid[0])
        ans = [['.'] * m for _ in range(n)]

        for i in range(m):
            st = []
            for j in range(n):
                if boxGrid[i][j] == '#':
                    st.append('#')
                elif boxGrid[i][j] == '*':
                    ans[j][i] = '*'
                    k = j - 1
                    while st:
                        ans[k][i] = st.pop()
                        k -= 1
            
            j = n - 1
            while st:
                ans[j][i] = st.pop()
                j -= 1
                
        for i in range(n):
            ans[i].reverse()
            

            
        return ans