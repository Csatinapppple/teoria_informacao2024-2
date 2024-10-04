import math

def codificar_golomb(N, M):
    """Codifica um número inteiro N usando o código de Golomb com parâmetro M."""
    q = N // M  
    r = N % M   

    b = math.floor(math.log2(M))
    k = 2 ** (b + 1) - M

    quociente = '0' * q + '1'

    if r < k:
        resto = bin(r)[2:]  
        resto = resto.zfill(b)  
    else:
        resto = bin(r + k)[2:]  
        resto = resto.zfill(b + 1)  

    codigo_golomb = quociente + resto
    print(f"O código de Golomb para N = {N} e M = {M} é: {codigo_golomb}")
    return codigo_golomb

def decodificar_golomb(codigo_golomb, M):
    """Decodifica um código de Golomb para recuperar o número original."""
    b = math.floor(math.log2(M))
    k = 2 ** (b + 1) - M

    q = 0
    while codigo_golomb[q] == '1':
        q += 1
    q += 1  

    bits_resto = codigo_golomb[q:]

    if len(bits_resto) == 0:
        raise ValueError("Código de Golomb inválido")
    
    r = 0
    if int(bits_resto[0]) < k:
        r = int(bits_resto, 2)  
    else:
        r = int(bits_resto, 2) - k  

    N = q * M + r
    return N

N = 10
M = 30
codigo_golomb = codificar_golomb(N, M)  
valor_decodificado = decodificar_golomb(codigo_golomb, M)  
print(f"O valor decodificado para o código de Golomb '{codigo_golomb}' com M = {M} é: {valor_decodificado}")
