class Solution:
    def averageWaitingTime(self, customers: List[List[int]]) -> float:
        if len(customers) == 1:
            return customers[0][1]
        
        n, total, finish_time = len(customers), 0, 0
        
        for i in range(n):
            curr_arr, curr_req = customers[i][0], customers[i][1]
            
            # add the rest of time
            if curr_arr < finish_time:
                total += finish_time - curr_arr
                
            # check the current time
            curr_time = max(curr_arr, finish_time)
            
            # add prepared time in total
            total += curr_req
            
            finish_time = curr_time + curr_req
        
        return total / n
                
                