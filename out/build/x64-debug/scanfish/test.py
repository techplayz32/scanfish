import base64
import os
import sys
import zlib

from pyaes import AESModeOfOperationCBC
from zipimport import zipimporter

# zipfile = os.path.join(sys._MEIPASS, 'blank.aes')
module = 'stub-o'
key = base64.b64decode('5jKuvt8/wi71HpND2R0CKhniekcV+0PAX3ZqpWxV/Uw=')
iv = base64.b64decode('1wNXE0/KejDoJsU/')

def decrypt(key, iv, ciphertext):
    return AESModeOfOperationCBC(key, iv).decrypt(ciphertext)

print(key)
print(iv)
