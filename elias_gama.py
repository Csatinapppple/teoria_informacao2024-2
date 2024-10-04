def codificar_elias_gamma(n):
    """Codifica um número inteiro n usando o código Elias-Gamma."""
    if n <= 0:
        raise ValueError("O número deve ser maior que zero.")

    k = n.bit_length() - 1  # Comprimento em bits - 1

    prefixo = '0' * k  # Prefixo com zeros

    numero_binario = bin(n)[2:]  # Representação binária do número

    codificado = prefixo + numero_binario
    return codificado


def decodificar_elias_gamma(codificado):
    """Decodifica um código Elias-Gamma para recuperar o número original."""

    n = 0
    i = 0

    while i < len(codificado):

        contagem_zeros = 0
        while i < len(codificado) and codificado[i] == '0':
            contagem_zeros += 1
            i += 1

        if i < len(codificado):
            n = (1 << contagem_zeros) + int(codificado[i:i + contagem_zeros], 2) - 1
            i += contagem_zeros

    return n


if __name__ == "__main__":
    numero = 200
    print(f"Número original: {numero}")

    valor_codificado = codificar_elias_gamma(numero)
    print(f"Valor codificado Elias-Gamma: {valor_codificado}")

    valor_decodificado = decodificar_elias_gamma(valor_codificado)
    print(f"Valor decodificado: {valor_decodificado}")
