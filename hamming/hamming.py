
#hamming(7,4) encoder and decoder deve ser capaz de codificar simbolos char
#dividindo os bytes 2 nibbles de 4 bits

def encode(bits: str):
    
    t1 = int(bits[0]) ^ int(bits[1]) ^ int(bits[2])
    t2 = int(bits[1]) ^ int(bits[2]) ^ int(bits[3])
    t3 = int(bits[0]) ^ int(bits[2]) ^ int(bits[3])

    print(str(t1) + str(t2) + str(t3))
    
    return bits + str(t1) + str(t2) + str(t3)   
    

def encode_char(char: chr):
    first_half = ord(char) & 0xf
    second_half = ord(char) >> 4 & 0xf
    
    print(bin(ord(char)))
    
    """
    pega meio byte e transforma em uma string de bits para encodar no
    hamming(7,4)
    """

    first_half_bin = bin(first_half)[2:]
    missing_zeros = 4 - len(first_half_bin)
    first_half_bin = '0'*missing_zeros + first_half_bin
 
    second_half_bin = bin(second_half)[2:]
    missing_zeros = 4 - len(second_half_bin)
    second_half_bin = '0'*missing_zeros + second_half_bin



    print(first_half_bin)
    print(second_half_bin)

    return encode(first_half_bin) + encode(second_half_bin)


def decode(bits: str):
    
    integrity = [int(bits[4]), int(bits[5]), int(bits[6])]

    t1 = (int(bits[0]) ^ int(bits[1]) ^ int(bits[2]) == integrity[0])  
    t2 = (int(bits[1]) ^ int(bits[2]) ^ int(bits[3]) == integrity[1])
    t3 = (int(bits[0]) ^ int(bits[2]) ^ int(bits[3]) == integrity[2])

    print(t1, t2, t3)
    
    print(bits)

    if (not t1 and not t2 and t3):
        bits = bits[:1] + str((int(bits[1]) ^ 1)) + bits[2:]
    elif ( t1 and not t2 and not t3):
        bits = bits[:3] + str((int(bits[3]) ^ 1)) + bits[4:]
    elif (not t1 and t2 and not t3):
        bits = bits[:0] + str((int(bits[0]) ^ 1)) + bits[1:]
    elif (not t1 and not t2 and not t3):
        return False
    return bits[:4]
        

       


#assuming that the bits are always the size of two hamming(7,4) encodings so 14 bits
def decode_char(bits: str):
    
    first_half_bin = bits[:7]
    second_half_bin = bits[7:]
    
    print("decode char")
    print(first_half_bin)
    print(second_half_bin)
    

    binary_result = decode(second_half_bin) + decode(first_half_bin)
    print(binary_result)
    print(chr(int(binary_result,2)))
    

