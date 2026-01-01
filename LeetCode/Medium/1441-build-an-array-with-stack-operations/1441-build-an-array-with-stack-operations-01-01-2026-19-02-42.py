class Solution:
    def buildArray(self, target: List[int], n: int) -> List[str]:
        ans, st, pt = [], [], 0

        for i in range(1, n + 1):
            if i == target[pt]:
                while st and st[-1] != target[max(0, pt - 1)]:
                    st.pop()
                    ans.append("Pop")
                pt += 1
            
            ans.append("Push")
            st.append(i)
            if pt == len(target):
                break

        return ans