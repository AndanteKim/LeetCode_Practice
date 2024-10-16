class Solution:
    def longestDiverseString(self, a: int, b: int, c: int) -> str:
        pq = []
        if a > 0:
            heappush(pq, (-a, 'a'))
        if b > 0:
            heappush(pq, (-b, 'b'))
        if c > 0:
            heappush(pq, (-c, 'c'))
            
        ans = ""
        
        while pq:
            cnt, ch = heappop(pq)
            cnt = abs(cnt)
            
            if (len(ans) >= 2 and ans[-1] == ch and ans[-2] == ch):
                if not pq:
                    break
                temp_cnt, temp_ch = heappop(pq)
                ans += temp_ch
                
                if temp_cnt + 1 < 0:
                    heappush(pq, (temp_cnt + 1, temp_ch))
                heappush(pq, (-cnt, ch))
            else:
                cnt -= 1
                ans += ch
                if cnt > 0:
                    heappush(pq, (-cnt, ch))
                    
        return ans