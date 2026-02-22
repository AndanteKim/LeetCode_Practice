class Solution:
    def rearrangeString(self, s: str, k: int) -> str:
        freq = [0] * 26

        for c in s:
            freq[ord(c) - 97] += 1

        free = []
        # Insert the characters with frequencies as max heap
        for i in range(26):
            if freq[i] > 0:
                heappush(free, (-freq[i], i))

        # Busy: queues which characters cannot be used now.
        ans, busy = "", deque()

        while len(ans) != len(s):
            idx = len(ans)

            # Insert the character that could be used now into the free heap
            if busy and (idx - busy[0][0]) >= k:
                q = busy.popleft()
                heappush(free, (-freq[q[1]], q[1]))
            
            if not free:
                return ""
            
            curr_ch = heappop(free)[1]
            
            ans += chr(curr_ch + 97)
            freq[curr_ch] -= 1

            if freq[curr_ch] > 0:
                busy.append((idx, curr_ch))

        return ans