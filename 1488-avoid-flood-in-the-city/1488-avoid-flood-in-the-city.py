class Solution:
    def avoidFlood(self, rains: List[int]) -> List[int]:
        ans, st = [1] * len(rains), SortedList()
        mp = dict()        

        for i, rain in enumerate(rains):
            if rain == 0:
                st.add(i)
            else:
                ans[i] = -1
                if rain in mp:
                    it = st.bisect(mp[rain])
                    if it == len(st):
                        return []
                    ans[st[it]] = rain
                    st.discard(st[it])
                mp[rain] = i

        return ans