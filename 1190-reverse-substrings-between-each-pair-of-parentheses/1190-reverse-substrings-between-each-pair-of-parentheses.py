class Solution:
    def reverseParentheses(self, s: str) -> str:
        st = []
        
        for c in s:
            if c == ')':
                curr = []
                while st and st[-1] != '(':
                    curr.append(st.pop())
                st.pop()
                for c in curr:
                    st.append(c)

            else:
                st.append(c)

        return "".join(st)