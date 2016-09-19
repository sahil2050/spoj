def main():
    n=int(raw_input())
    if(n==-1):
        return
    dp=[1,1,2]
    for i in xrange(3,n+1):
        temp=0
        for k in xrange(0,i):
            temp+=dp[k]*dp[i-1-k]
        dp.append(temp)
    print dp[n]
    return main()

main()

