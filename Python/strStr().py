class Solution:
    # @param haystack, a string
    # @param needle, a string
    # @return a string or None
    def strStr(self,haystack, needle):
        if haystack==needle or needle=='':
            return haystack
        if haystack=='':
            return None
        n = len(haystack)
        m = len(needle)
        if m>n:
            return None
        next = [0 for i in range(m+1)]
        k = 0
        for i in range(2,m+1):
            while k!=0 and needle[k]!=needle[i-1]:
                k = next[k]
            if needle[i-1]==needle[k]:
                k +=1
            next[i] = k
        hi = 0
        ni = 0
        while hi<n:
            ni = next[ni]
            while ni<m and hi<n:
                if needle[ni]==haystack[hi]:
                    ni+=1
                    hi+=1
                else:
                    break
            if ni==0:
                hi+=1
            elif ni==m:
                return haystack[hi-m:]
        
        return None
                
        
