from Crypto.Cipher import AES
#from Crypto import Random
from Crypto.Util import Counter
import random
import math


# Pad for short keys
pad = 'constant pad for short keys'

def padding(text, size):
    blocks = math.ceil(len(text)/float(size))
    pad_value = int(blocks*size - len(text))
    if pad_value == 0:
        return text + chr(size)*size
    else:
        return text + chr(pad_value)*pad_value

#random_generator = Random.new()
#IV = random_generator.read(16)
IV = ''.join(chr(random.randint(33, 126)) for i in range(16)).encode()
#print(IV)


# Encryption steps

user_keye = "asdfghjklzxcvbnm"
keye = (user_keye + pad)[:16]

# Create counter for encryptor
ctr_enc = Counter.new(128)

# Create encryptor, ask for plaintext to encrypt, then encrypt and print ciphertext
encryptor = AES.new(keye.encode(), AES.MODE_CTR, counter=ctr_enc)
plaintext = "Dai hoc Bach Khoa Ha Noi"
print(len(plaintext))
#plaintext = padding(plaintext, 16)
#print(len(encryptor))
# print(encryptor)
ciphertext = encryptor.encrypt(plaintext.encode())
print(ciphertext)


# Decryption steps

user_keyd = "asdfghjklzxcvbnm"
keyd = (user_keyd + pad)[:16]

# Create counter for decryptor: it is equal to the encryptor, but restarts from the beginning
ctr_dec = Counter.new(128)

# Create decryptor, then decrypt and print decoded text
decryptor = AES.new(keyd.encode(), AES.MODE_CTR, counter=ctr_dec)
plaintext2 = decryptor.decrypt(ciphertext)
print (plaintext2)