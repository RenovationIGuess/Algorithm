# import string
# import collections
# import binascii
# import sets

c1 = "315c4eeaa8b5f8aaf9174145bf43e1784b8fa00dc71d885a804e5ee9fa40b16349c146fb778cdf2d3aff021dfff5b403b510d0d0455468aeb98622b137dae857553ccd8883a7bc37520e06e515d22c954eba5025b8cc57ee59418ce7dc6bc41556bdb36bbca3e8774301fbcaa3b83b220809560987815f65286764703de0f3d524400a19b159610b11ef3e"
c2 = "234c02ecbbfbafa3ed18510abd11fa724fcda2018a1a8342cf064bbde548b12b07df44ba7191d9606ef4081ffde5ad46a5069d9f7f543bedb9c861bf29c7e205132eda9382b0bc2c5c4b45f919cf3a9f1cb74151f6d551f4480c82b2cb24cc5b028aa76eb7b4ab24171ab3cdadb8356f"
c3 = "32510ba9a7b2bba9b8005d43a304b5714cc0bb0c8a34884dd91304b8ad40b62b07df44ba6e9d8a2368e51d04e0e7b207b70b9b8261112bacb6c866a232dfe257527dc29398f5f3251a0d47e503c66e935de81230b59b7afb5f41afa8d661cb"
c4 = "32510ba9aab2a8a4fd06414fb517b5605cc0aa0dc91a8908c2064ba8ad5ea06a029056f47a8ad3306ef5021eafe1ac01a81197847a5c68a1b78769a37bc8f4575432c198ccb4ef63590256e305cd3a9544ee4160ead45aef520489e7da7d835402bca670bda8eb775200b8dabbba246b130f040d8ec6447e2c767f3d30ed81ea2e4c1404e1315a1010e7229be6636aaa"
c5 = "3f561ba9adb4b6ebec54424ba317b564418fac0dd35f8c08d31a1fe9e24fe56808c213f17c81d9607cee021dafe1e001b21ade877a5e68bea88d61b93ac5ee0d562e8e9582f5ef375f0a4ae20ed86e935de81230b59b73fb4302cd95d770c65b40aaa065f2a5e33a5a0bb5dcaba43722130f042f8ec85b7c2070"
c6 = "32510bfbacfbb9befd54415da243e1695ecabd58c519cd4bd2061bbde24eb76a19d84aba34d8de287be84d07e7e9a30ee714979c7e1123a8bd9822a33ecaf512472e8e8f8db3f9635c1949e640c621854eba0d79eccf52ff111284b4cc61d11902aebc66f2b2e436434eacc0aba938220b084800c2ca4e693522643573b2c4ce35050b0cf774201f0fe52ac9f26d71b6cf61a711cc229f77ace7aa88a2f19983122b11be87a59c355d25f8e4"
c7 = "32510bfbacfbb9befd54415da243e1695ecabd58c519cd4bd90f1fa6ea5ba47b01c909ba7696cf606ef40c04afe1ac0aa8148dd066592ded9f8774b529c7ea125d298e8883f5e9305f4b44f915cb2bd05af51373fd9b4af511039fa2d96f83414aaaf261bda2e97b170fb5cce2a53e675c154c0d9681596934777e2275b381ce2e40582afe67650b13e72287ff2270abcf73bb028932836fbdecfecee0a3b894473c1bbeb6b4913a536ce4f9b13f1efff71ea313c8661dd9a4ce"
c8 = "315c4eeaa8b5f8bffd11155ea506b56041c6a00c8a08854dd21a4bbde54ce56801d943ba708b8a3574f40c00fff9e00fa1439fd0654327a3bfc860b92f89ee04132ecb9298f5fd2d5e4b45e40ecc3b9d59e9417df7c95bba410e9aa2ca24c5474da2f276baa3ac325918b2daada43d6712150441c2e04f6565517f317da9d3"
c9 = "271946f9bbb2aeadec111841a81abc300ecaa01bd8069d5cc91005e9fe4aad6e04d513e96d99de2569bc5e50eeeca709b50a8a987f4264edb6896fb537d0a716132ddc938fb0f836480e06ed0fcd6e9759f40462f9cf57f4564186a2c1778f1543efa270bda5e933421cbe88a4a52222190f471e9bd15f652b653b7071aec59a2705081ffe72651d08f822c9ed6d76e48b63ab15d0208573a7eef027"
c0 = "466d06ece998b7a2fb1d464fed2ced7641ddaa3cc31c9941cf110abbf409ed39598005b3399ccfafb61d0315fca0a314be138a9f32503bedac8067f03adbf3575c3b8edc9ba7f537530541ab0f9f3cd04ff50d66f1d559ba520e89a2cb2a83"
# ciphers = [c1, c2, c3, c4, c5, c6, c7, c8, c9, c10]
# Đối tượng cần được giải
c10 = "32510ba9babebbbefd001547a810e67149caee11d945cd7fc81a05e9f85aac650e9052ba6a8cd8257bf14d13e6f0a803b54fde9e77472dbff89d71b57bddef121336cb85ccb8f3315f4b52e301d16e9f52f904"
# Tại sao lại đặt tên số cho bản mã "466d06ece998..." là c0?
# Vì đó là bản mã có độ dài ngắn nhất (có thể đặt c0 ở bảng mã cùng độ dài vs nó)
# Vì khi ta xét ta chỉ làm với những vị trí có thể XOR (do độ dài các xâu khác nhau) nên ta sẽ dựa theo bản mã ngắn nhất mà làm

# Như đã giải thích trong file Word, cứ 2 ký tự mã 16 sẽ tương ứng 
# 1 ký tự mã ascii -> chia đôi độ dài xâu 
# Như vậy 1 vị trí có chỉ số gốc là i * 2
def Divide(s):
    str = []
    for i in range(len(s) // 2):
        # Ta sẽ đưa về 10 luôn = cách int(..., base) vs base = 16
        str.append(int(s[i * 2 : i * 2 + 2], 16))
    return (str)

# Hàm này sẽ chuyển các bản mã về list gồm các ký tự ở mã 10 tương ứng    
def Dec_Convert():
    Ciphertexts = []
    for i in range(11):
        # -> nó sẽ thực hiện câu lệnh của xâu bên trong
        converted = eval("Divide(c" + str(i) + ")")
        Ciphertexts.append(converted)
    return (Ciphertexts)
    
# Hàm này để tìm vị trí phím space
# Có điều lưu ý là độ dài xâu ko = nhau -> ta sẽ xét trong phạm vi
# Độ dài của xâu nhỏ hơn trong 2 xâu đang xét
def find_space(s1, s2):
    # đánh dấu cho mọi vị trí = 0
    # Nếu vị trí nào có thể là space đánh dấu cho = 1
    # Ta sẽ lấy độ dài của s1 do điều ta làm là so bản mã 1 vs 2,3,... và với 2 thì 1,3,...
    check = [0] * len(s1)
    if len(s1) > len(s2):
        for i in range(len(s2)):
            if 97 <= s1[i] ^ s2[i] <= 122 or 65 <= s1[i] ^ s2[i] <= 90 or s1[i] ^ s2[i] == 0:
                check[i] = 1
            # Với các vị trí còn thừa trong xâu dài hơn ta sẽ cho nó là " " để dễ thao tác
            for i in range(len(s2), len(s1)):
                check[i] = 1
    else: 
        for i in range(len(s1)):
            if 97 <= s1[i] ^ s2[i] <= 122 or 65 <= s1[i] ^ s2[i] <= 90 or s1[i] ^ s2[i] == 0:
                check[i] = 1
    return (check)

# sp - space's position - Hàm tìm vị trí ký tự space sau khi ta có tần số xuất hiện sau khi XOR
# input của hàm là mảng chứa vị trí các ký tự space
def space_posi_in_s(sp): 
    # Khác với hàm trên lần này ta sẽ tính số lần xuất hiện của " " khi XOR với các bản mã khác
    # Như đề cập ở đầu code, ta làm việc với bản mã độ dài min
    # Hay khi đó sp[0] lúc này là list gồm các vị trí có thể có 
    # space của ciphertext[i] với ciphertext có len min (XOR)
    min_len = len(sp[0])

    # Giả sử mọi vị trí đều thỏa mãn
    check = [1] * min_len

    for i in range(len(sp)): 
        for j in range(min_len): 
            check[j] += sp[i][j]
    
    for i in range(min_len):
        # Nếu tần số lớn / = 7 (theo tham khảo đó là khoảng tiêu chuẩn vừa đủ ạ) 
        if check[i] > 9: 
            check[i] = 1
        else:
            check[i] = 0
    return (check)

# Hàm này sẽ sử dụng để tìm key sau khi ta đã có được vị trí dấu space trong bản gốc
# của bản mã tương ứng (bản mã trong input của hàm)
# space_s là list chứa các vị trí có thể xuất hiện dấu cách ở bản gốc của bản mã t.ứ
def find_key_str(cipher, space_s):
    # string key - key dùng để mã hõa bản mã s
    key_str = []
    for i in range(len(space_s)): 
        # Nếu tại vị trí đó xuất hiện dấu cách -> XOR với ciphertext để ra key
        # đã dùng để mã hóa
        if space_s[i] == 1: 
            key_str.append(cipher[i] ^ 32)
        else: 
            key_str.append("") 
    return (key_str)

# Sau khi có hàm trên, việc bây giờ là 
def find_key_r(ciphers, space_possi):    
    # Tạo list với đánh số = 0 
    key = [0] * 250
    # final - key
    f_key = []
    for i in range(11):    
        # f_key sẽ lưu các key đã được sử dụng để mã hóa các bản mã
        f_key.append(find_key_str(ciphers[i], space_posi_in_s(space_possi[i])))
    for j in f_key:
        for k in range(len(j)):
            # điền key vào chỗ trống
            if j[k] != "":
                key[k] = j[k]
    return (key)

# Với khóa sau khi tìm được 
def Solve(s, key): 
    res = ""
    for i in range(len(s)): 
        if key[i] != 0: 
            # res += str(chr(s[i] ^ key[i]))
            res += chr(s[i] ^ key[i])
        else: 
            res += "_"
    return (res)

def main(): 
    # Chuyển cơ số 10
    ciphers = Dec_Convert()
    # space possible - list lưu những vị trí dấu cách của
    # các bản mã khi XOR với các bản mã còn lại VD: c0 - c1, c2, c3,... 
    space_possi = []
    for i in range(11): 
        # Tạo 1 list để lưu điều nói trên
        space_s = []
        for j in range(11):
            # XOR với các bản mã còn lại ko gồm chính nó
            if i != j:
                space_s.append(find_space(ciphers[i], ciphers[j]))
        space_possi.append(space_s)

    key = find_key_r(ciphers, space_possi)
    print("The key:")
    print(key)
    print("")
    print("The texts:")
    for i in range(11):    
        print(Solve(ciphers[i], key))    

main()
