import random

f = open("testcase.txt", "w")

n = int(input())

f.write(str(n) + "\n")

for t in range(0,2):
    for i in range(0,n):
        for j in range(0,n):
           f.write(str(int(random.random()*10)) + '\n') 
