class Solution:
    def reorganizeString(self, s: str) -> str:
        ans, counter, pq = [], dict(), []
        for c in s:
            counter[c] = counter.get(c, 0) + 1
        
        for k, count in counter.items():
            heappush(pq, (-count, k))
        
        while pq:
            count_first, char_first = heappop(pq)
            
            if not ans or char_first != ans[-1]:
                ans.append(char_first)
                if count_first + 1 != 0:
                    heappush(pq, (count_first + 1, char_first))
            else:
                if not pq:
                    return ""
                count_second, char_second = heappop(pq)
                ans.append(char_second)
                if count_second + 1 != 0:
                    heappush(pq, (count_second + 1, char_second))
                heappush(pq, (count_first, char_first))
            
        return "".join(ans)