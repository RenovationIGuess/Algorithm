from Crypto.Cipher import AES
from Crypto.Util import Counter
import random
import math

def padding(text, size):
    block = math.ceil(len(text)/float(size))
    pad_value = int(block*size - len(text))
    if pad_value == 0:
        return text + chr(size)*size
    else:
        return text + chr(pad_value)*pad_value

IV = ''.join(chr(random.randint(32, 126)) for i in range (16)).encode()

user_keye = "rtweioltrjhfsdjg"
keye = (user_keye)[:16]

ctr_encrypt = Counter.new(128)

ecryptor = AES.new(keye.encode(), AES.MODE_CTR, counter = ctr_encrypt)
plaintext = "An toan thong tin kho qua"
print(len(plaintext))
print("Encryption: ")
ciphertext = ecryptor.encrypt(plaintext.encode())
print(ciphertext)

user_keyd = "rtweioltrjhfsdjg"
keyd = user_keyd[:16]

ctr_decrypt = Counter.new(128)

print("Decryption: ")
decryptor = AES.new(keyd.encode(), AES.MODE_CTR, counter = ctr_decrypt)
plaintext1 = decryptor.decrypt(ciphertext)
print(plaintext1)
    