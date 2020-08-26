import sys
sys.stdout = open("output.txt","w")
sys.stdin = open("input.txt","r")
sys.stderr = open("error.txt","w")

k = list(input().split())
print(k)
print(''.join(k))
print(k*7)