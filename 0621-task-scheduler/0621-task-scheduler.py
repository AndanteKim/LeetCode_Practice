class Solution:
    def leastInterval(self, tasks: List[str], n: int) -> int:
        # Create a frequency array to keep track of the count of each task
        freq = [0] * 26
        for task in tasks:
            freq[ord(task) - 65] += 1
            
        # Sort the frequency array in non-decreasing order
        freq.sort()
        
        # Calculate the maximum frequency of any task
        max_freq = freq[25] - 1
        
        # Calculate the number of idle slots that will be required
        idle_slots = max_freq * n
        
        # Iterate over the frequency array from the second highest frequency to the lowest frequency
        for i in range(24, -1, -1):
            # Subtract the minimum of the maximum frequency and the current frequency from the idle slots
            idle_slots -= min(max_freq, freq[i])
            
        # If there are any idle slots left, add them to the total number of tasks
        return idle_slots + len(tasks) if idle_slots > 0 else len(tasks)