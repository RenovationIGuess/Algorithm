from Crypto.Cipher import AES
from Crypto import Random
import math
import random
import hashlib

def convert_32byte(key):
    converted_key = hashlib.sha256(key.encode('utf-8')).digest()
    return converted_key

"""sha - 256: block 32 bytes
encode() convert ra bytes được acc
digest để trả về key đã chuyển"""

'''padding
nếu k cần pad thêm khối giả n byte
nếu không thì pad'''

def padding(text, size):
    block = math.ceil(len(text)/float(size))
    pad_value = int(block*size - len(text))
    if pad_value == 0:
        return text + chr(size)*size
    else:
        return text + chr(pad_value)*pad_value

'''math.ceil - làm tròn - lấy số block size byte
len() trả về số phần tử
size - byte'''

def unpad(s):
    return s[0:-ord(s[-1:])]
'''ord tra ve gia tri nguyen cua string/char
Lay tu 0 va tru so ord(phan tu cuoi) ky tu cuoi'''

'''Encrypt:
y-1 = IV
yi = Ek(yi-1 xor xi)
Decrypt:
x0 = IV
xi = Dk(yi - 1 xor Dk(yi))'''
def main():
    #dua ve byte
    key = b"fahweihcfkjsdfas"
    IV = ''.join(chr(random.randint(32, 126)) for i in range(16))
    '''IV - do dai 16 tao random voi cac ky tu in duoc ASCII'''
    plaintext = "Hoc bong loai A dang cho"
    print(padding(plaintext, 16))
    
    print("Encryption: ")
    obj = AES.new(key, AES.MODE_CBC, IV.encode())
    ciphertext = obj.encrypt(padding(plaintext, 16).encode())
    print(ciphertext)
    
    print("Decryption: ")
    obj1 = AES.new(key, AES.MODE_CBC, IV.encode())
    plaintext1 = unpad(obj1.decrypt(ciphertext))
    print(plaintext1)
    
main()
