from ctypes import *

lib = CDLL('libctypes')


# int, float, bool, (char, wchar_t), wchar_t* 分别对应整型，浮点，字符和字符串 都可以直接传参
# char* 需要b'字符串'以字节码形式传参

def getPyFunc(func, args: tuple, returnType=None):
    if args is not None: func.argtypes = args
    if returnType is not None: func.restype = returnType
    return func


def testCBaseType(x: int, y: float, z: str, isTrue: bool):
    return getPyFunc(lib.testCBaseType, args=(c_int, c_float, c_wchar, c_bool), returnType=c_float)(x, y, z, isTrue)


def testCstring(x: bytes):
    return getPyFunc(lib.testCstring, args=(c_char_p,), returnType=c_char_p)(x)


def testCWideString(x: str):
    return getPyFunc(lib.testCWideString, args=(c_wchar_p,), returnType=c_wchar_p)(x)


def testPointer(x: int):
    arg = c_int(x)
    return getPyFunc(lib.testPointer, args=(POINTER(c_int),), returnType=c_int)(arg), arg.value


def testReturnPointer(x: int) -> c_int:
    arg = c_int(x)
    res = getPyFunc(lib.testReturnPointer, args=(POINTER(c_int),), returnType=POINTER(c_int))(arg)
    return res.contents.value


def testArray(li: list):
    arrType = c_int * len(li)
    return getPyFunc(lib.testArray, args=(POINTER(c_int), c_int), returnType=c_double)(arrType(*li), len(li))


# 先定义结构体
class Point(Structure):
    _fields_ = [('x', c_double), ('y', c_double)]


def distance(x: tuple, y: tuple):
    p1, p2 = Point(*x), Point(*y)
    return getPyFunc(lib.distance, args=(POINTER(Point), POINTER(Point)), returnType=c_double)(p1, p2)
