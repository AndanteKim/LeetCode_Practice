class Solution:
    def rearrangeString(self, s: str, k: int) -> str:
        freqs, max_freq = dict(), 0
        
        # store the frequency and find the highest frequency
        for c in s:
            freqs[c] = freqs.get(c, 0) + 1
            max_freq = max(max_freq, freqs[c])
            
        most_chars, second_chars = set(), set()
        
        # store all the characters with the highest and second highest frequency - 1
        for c, freq in freqs.items():
            if freq == max_freq:
                most_chars.add(c)
            elif freq == max_freq - 1:
                second_chars.add(c)
        
        # create max_freq number of different strings
        segments = [''] * max_freq
        # insert one instance of characters with frequency max_freq and max_freq - 1 in each segment
        for i in range(max_freq):
            for c in most_chars:
                segments[i] += c
        
            # skip the last segment as the frequency is only max_freq - 1
            if i < max_freq - 1:
                for c in second_chars:
                    segments[i] += c
        
        segment_id = 0
        # iterate over the remaining characters, and for each, distribute the instances over the segments
        for curr_char, _ in freqs.items():
            if curr_char in most_chars or curr_char in second_chars:
                continue
            
            # distribute the instances of these characters over the segments in a round-robin manner
            for freq in range(freqs[curr_char], 0, -1):
                segments[segment_id] += curr_char
                segment_id = (segment_id + 1) % (max_freq - 1)
        
        # each segment except the last should have exactly k elements; otherwise, return ""
        for i in range(max_freq - 1):
            if len(segments[i]) < k:
                return ""
            
        ans = ""
        for s in segments:
            ans += s
        
        return ans
        
        