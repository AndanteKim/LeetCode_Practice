class Solution:
    def rearrangeString(self, s: str, k: int) -> str:
        freq = [0] * 26
        
        # store the frequency for each character
        for c in s:
            freq[ord(c) - 97] -= 1
        
        max_heap = []
        
        # insert the characters with their frequencies in the max heap
        for i in range(26):
            if freq[i]:
                heappush(max_heap, (freq[i], i))
        
        ans, busy = "", deque([])
        while len(ans) != len(s):
            idx = len(ans)
            
            # insert the character that could be used now into the free heap
            if busy and idx - busy[0][0] >= k:
                prev_idx, ch_idx = busy.popleft()
                heappush(max_heap, (freq[ch_idx], ch_idx))
            
            # if the free heap is empty, it implies no character can be used at this index
            if not max_heap:
                return ""
            
            f, curr_char_idx = heappop(max_heap)
            ans += chr(curr_char_idx + 97)
            
            # insert the used character into busy queue with the current index.
            freq[curr_char_idx] += 1
            if freq[curr_char_idx] < 0:
                busy.append((idx, curr_char_idx))
        
        return ans
            