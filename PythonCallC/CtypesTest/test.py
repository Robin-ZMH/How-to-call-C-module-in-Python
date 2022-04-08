import ctypesAPI as ct

print(ct.testCBaseType(1, 2, 'G', False))

print(ct.testCstring(b'hi,Robin'))

print(ct.testCWideString('I love Python'))

print(ct.testArray([1, 2, 3, 4, 5, 6, 7]))

print(ct.testPointer(666))

print(ct.testReturnPointer(233))

print(ct.distance((1, 2), (4, 5)))
