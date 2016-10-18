t=int(raw_input())
while(t>0):
    n,i=map(int,raw_input().split())
    print(n**i-(n-2)**i)
    t=t-1
