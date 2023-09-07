import base64
h = hex(0x584b51f48bca9572acd08d378362 ^ 0x2e2e3f9dabbcfc16c5f0fb5ee00b)[2:]
print(h)
print(base64.b16decode(h.upper()))