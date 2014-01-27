s = raw_input()
temp = s

ans = 0
while True:
    start = -1
    efound = False
    afound = False
    end = -1
    i = 0
    while (i < len(temp) - 3):
        if temp[i] == 'b' and temp[i+1] == 'e' and temp[i+2] == 'a' and temp[i+3] == 'r':
            start = i
            break
        i = i + 1
    if start == -1:
        break

    end = start + 3
    before = start + 1
    after = len(temp) - end
    
    ans = ans + before*after
    temp = temp[start+1:]
    
print ans
