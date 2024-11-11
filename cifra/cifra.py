

alfabeto = dict(enumerate("ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789@"))
alfabeto_value = {v: k for k, v in alfabeto.items()}

def decifer(string):
    
    for shift in range(0, len(alfabeto)):
        
        deciphered = ""

        for c in string:

            offset = (shift + alfabeto_value[c]) % len(alfabeto)



print(alfabeto)
print(alfabeto_value)
