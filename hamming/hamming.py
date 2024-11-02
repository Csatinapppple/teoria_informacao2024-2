
#hamming(7,4) encoder and decoder deve ser capaz de codificar simbolos char
#dividindo os bits em 2 partes

def encode(in: chr):
    first_half = in & 0b00001111
    second_half = in >> 4 & 0b00001111

    
    

