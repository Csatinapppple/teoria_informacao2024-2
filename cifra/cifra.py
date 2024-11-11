

alfabeto = dict(enumerate("ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789@"))
alfabeto_value = {v: k for k, v in alfabeto.items()}

def decifer(string):
    
    for shift in range(0, len(alfabeto)):
        
        deciphered = ""

        for c in string:
            
            if c in alfabeto_value:

                offset = (shift + alfabeto_value[c]) % len(alfabeto)

                deciphered += alfabeto[offset]
            else:
                deciphered += c

        print(deciphered, shift)


print(alfabeto)
print(alfabeto_value)

decifer("slgqglmq")
