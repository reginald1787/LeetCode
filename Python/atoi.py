def atoi(str):
        INT_MAX = 2147483647  
        INT_MIN = -2147483648
        numbers='0123456789'
        if str=='':
            return 0
        i=0
        while i<len(str) and str[i]==' ':
            i+=1
        signed = False
        if str[i]=='-':
            signed= True
            i+=1
        elif str[i]=='+':
            i+=1
        if i==len(str) or str[i] not in numbers:
                return 0
        num = ''
        while i<len(str):
            if str[i] in numbers:
                num+=str[i]
                i+=1
            else:
                break
        #print num
        if num == '':
            return 0
        if not signed:
            num = int(num)
            return min(INT_MAX,num)
        else:
            num = -1*int(num)
            return max(INT_MIN,num)
