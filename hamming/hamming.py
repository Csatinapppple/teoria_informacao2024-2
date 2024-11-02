
#hamming(7,4) encoder and decoder deve ser capaz de codificar simbolos char
#dividindo os bits em 2 partes

def encode(bits: str):
    
    t1 = int(bits[0]) ^ int(bits[1]) ^ int(bits[2])

    print(t1)

    

def encode_char(char: chr):
    first_half = ord(char) & 0b00001111
    second_half = ord(char) >> 4 & 0b00001111
    
    print(bin(ord(char)))
    
    first_half_bin = bin(first_half)[2:]
    missing_zeros = 4 - len(first_half_bin)
    first_half_bin = '0'*missing_zeros + first_half_bin
 
    second_half_bin = bin(second_half)[2:]
    missing_zeros = 4 - len(second_half_bin)
    second_half_bin = '0'*missing_zeros + second_half_bin



    print(first_half_bin)
    print(second_half_bin)

    encode(second_half_bin)


encode_char('a')
    

