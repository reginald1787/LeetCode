class Solution:
    # @param gas, a list of integers
    # @param cost, a list of integers
    # @return an integer
    def canCompleteCircuit(self, gas, cost):
    
        total = gas[0]-cost[0]
        mt = total
        mi =0 
        for i in range(1,len(gas)):
        
            total += (gas[i] - cost[i])
            if (total < mt):
            
                mt = total
                mi = i
            
        if total>=0:
            return (mi+1)%len(gas)
        else:
            return -1
        
