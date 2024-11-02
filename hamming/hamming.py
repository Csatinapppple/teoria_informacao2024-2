
#hamming(7,4) encoder and decoder deve ser capaz de codificar simbolos char
#dividindo os bits em 2 partes

def encode(char: str);

def encode_char(char: chr):
    first_half = ord(char) & 0b00001111
    second_half = ord(char) >> 4 & 0b00001111
    
    print(bin(ord(char)))

    print(bin(first_half))
    print(bin(second_half))


encode('a')
    

