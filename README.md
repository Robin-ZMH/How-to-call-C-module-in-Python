# How-to-call-C-module-in-Python
Python调用C++函数的几种方法

主要有三种：
1.使用ctypes调用.dll(Linux下是.so文件)文件
2.使用cython将.pyx文件转换为.dll(Linux为.so文件)文件
3.直接编写用于Py_Extension的c++文件，头文件引入"Python.h"模块
