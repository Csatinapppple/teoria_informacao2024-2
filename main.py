import hamming.hamming
import bsc.bsc


first_input = """
    Insira o que voce quer fazer:
    1. Codificar
    2. Decodificar
"""

second_input = """
    Insira o algoritimo
    1. BSC (Canal Binario Simetrico) Ri
    2. Hamming(7.4)
"""

third_input = """
    Insira a entrada para o algoritimo:
"""

while(True):
    

    first = int(input(first_input))
    second= int(input(second_input))
    third = str(input(third_input))

    encode("quake")

    encode = [bsc.encode, hamming.encode]
    decode = [bsc.decode, hamming.decode]
    
    

    match first:
        case 1:
            encode[second-1](third)
        case 2:
            decode[second-1](third)

       

