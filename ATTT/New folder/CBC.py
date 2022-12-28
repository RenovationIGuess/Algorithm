
from Crypto.Cipher import AES
from Crypto import Random
import math
import random
import hashlib

def ConvertKey_to_32_byte(key):
    Converted_key = hashlib.sha256(key.encode('utf-8')).digest()
    return Converted_key

''' PKCS#7 padding'''
def padding(text, size):
    blocks = math.ceil(len(text)/float(size))
    pad_value = int(blocks*size - len(text))
    if pad_value == 0: 
        return text + chr(size)*size
    else:
        return text + chr(pad_value)*pad_value

def unpad(s): 
    return s[0:-ord(s[-1:])]

def main():
    key = b"asdfghjklzxcvbnm"
    iv = ''.join(chr(random.randint(0, 126)) for i in range(16))
    #iv = 'asdfghjklzxcvbnm'
    plaintext = 'Dai hoc Bach Khoa Ha Noi'
    print(padding(plaintext, 16))

    print("Encryption: ")
    obj = AES.new(key, AES.MODE_CBC, iv.encode())
    ciptext = obj.encrypt(padding(plaintext, 16).encode())
    print(ciptext)

    print("Decryption: ")
    obj2 = AES.new(key, AES.MODE_CBC, iv.encode())
    plaintext2 = unpad(obj2.decrypt(ciptext))
    print(plaintext2)


main()



