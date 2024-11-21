import  bsc

string = "welcome to quake 3 arena"

result = bsc.encode(string,3)

print(result)

decode = bsc.decode(result,3)

print(decode)
