#codigo de repeticao Ri

r = 3

def encode(input_string):
    encoded = []
    for character in input_string:
        pre_binary = bin(ord(character))[2:]
        binary = "0" * (8-len(pre_binary)) + pre_binary
        for bit in binary:
            encoded.append(bit * r)
    return ''.join(encoded)

def decode(input_string):
    decoded_binary = []
    for i in range(0, len(input_string), r):
        block = input_string[i:i + r]
        ones_count = block.count('1')
        decoded_binary.append('1' if ones_count > r / 2 else '0')

    decoded_text = []
    for i in range(0, len(decoded_binary), 8):
        byte_string = ''.join(decoded_binary[i:i + 8])
        decoded_text.append(chr(int(byte_string, 2)))

    return ''.join(decoded_text)
