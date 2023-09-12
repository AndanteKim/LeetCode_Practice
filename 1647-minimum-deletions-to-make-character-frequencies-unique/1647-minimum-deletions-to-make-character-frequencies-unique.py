class Solution:
    def minDeletions(self, s: str) -> int:
        # store the frequency of each character
        frequency = [0] * 26
        for c in s:
            frequency[ord(c) - 97] += 1
        
        # Add all non-zero frequencies to max priority queue
        # Create a max priority queue by flipping the sign of each element
        pq = []
        
        for freq in frequency:
            if freq:
                heappush(pq, -freq)
        
        ans = 0
        while len(pq) > 1:
            # Flip the sign back to positive when removing from the max priority queue
            top_element = -heappop(pq)
            
            # If the top two elements in the priority queue are the same
            if top_element == -pq[0]:
                # Decrement the popped value and push it back into the queue
                if top_element - 1 > 0:
                    top_element -= 1
                    heappush(pq, -top_element)
                
                ans += 1
        
        return ans
        