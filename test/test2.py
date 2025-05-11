# xor_cipher.py
message = [72, 101, 108, 108, 111]  # "Hello" in ASCII
key = 42
encrypted = []
i = 0

while i < 5:
    encrypted_value = message[i] ^ key
    encrypted.append(encrypted_value)
    i = i + 1

print(encrypted)
