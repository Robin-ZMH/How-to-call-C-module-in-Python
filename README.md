# Python调用C++函数的几种方法

1.使用ctypes调用xxx.so文件  
2.使用cython将xxx.pyx编译为xxx.so文件  
3.直接编写用于Py_Extension的c++文件，头文件引入"Python.h"模块

# 效率提升对比  
Py_Extension ≈ cython_plus(使用cdef关键字) > ctypes > cython(不使用cdef关键字) ≈ python

# Linux下测试结果  
time span=0.0383763313293457s, res=499999500000  
time span=0.027170419692993164s, res=499999500000  
time span=0.0022478103637695312s, res=1783293664  
time span=0.00028586387634277344s, res=1783293664  
time span=0.0002522468566894531s, res=1783293664  

Cython is 1x faster than Python  
Ctypes is 17x faster than Python  
Cython_plus is 160x faster than Python  
C is 160x faster than Python  

