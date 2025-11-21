for i in range(2,101):
    for a in range(10,100001):
        for b in range(1,min(a-1,100001-1)):
            st = str(i) * (a-b)
            if st == "":
                continue
            z = int(st)
            if z == a*i-b:
                print(i, " ", a," ", b,"\n")
             

    
