from ctypes import *
lib = CDLL('./libctypes.so')


def getPyFunc(func, args: tuple, returnType=None):
	if args is not None: func.argtypes = args
	if returnType is not None: func.restype = returnType
	return func

def test(x):
	func = getPyFunc(lib.testTime, args=(c_int,), returnType=c_int)
	return func(x)