direction = input("'encode' or 'decode'? ").lower()
text = input("Enter the text to encrypt/decrypt: ")
key = int(input("Enter the key: "))
symbol = [' ', '.', '!', '?', '>', '<', '@', '#', '%', '/']


def encrypt(text, key):
    # encrypted = [ord(c) + (key % 26) if c not in symbol else ord(c)
    #              for c in text]
    encrypted = []
    for c in text:
        if c.isupper():
            encrypted.append(((ord(c) - ord('A') + key) % 26) + ord('A'))
        elif c.islower():
            encrypted.append(((ord(c) - ord('a') + key) % 26) + ord('a'))
        elif c in symbol:
            encrypted.append(ord(c))
    return ''.join(chr(c) for c in encrypted)


def decrypt(text, key):
    # decrypted = [ord(c) - (key % 26) if c not in symbol else ord(c)
    #              for c in text]
    # return ''.join(chr(c) for c in decrypted)
    decrypted = []
    for c in text:
        if c.isupper():
            decrypted.append(((ord(c) - ord('A') - key) % 26) + ord('A'))
        elif c.islower():
            decrypted.append(((ord(c) - ord('a') - key) % 26) + ord('a'))
        elif c in symbol:
            decrypted.append(ord(c))
    return ''.join(chr(c) for c in decrypted)


if direction == 'encode':
    print(encrypt(text, key))
elif direction == 'decode':
    print(decrypt(text, key))
