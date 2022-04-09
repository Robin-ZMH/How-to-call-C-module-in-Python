#include"Python.h"
#include"func.h"


static PyObject *py_multiply(PyObject *self, PyObject *args){
    int x, y, result;

    if (! PyArg_ParseTuple(args, "ii", &x, &y)){
        return NULL;
    }
    result = multiply(x, y);
    return Py_BuildValue("i", result);
}


static PyObject *py_divide(PyObject *self, PyObject *args){
    int x, y;
    float result;

    if (! PyArg_ParseTuple(args, "ii", &x, &y)){
        return NULL;
    }
    result = divide(x, y);
    return Py_BuildValue("f", result);
}


static PyObject *py_pointer(PyObject *self, PyObject *args){
    int x, result;

    if (! PyArg_ParseTuple(args, "i", &x)){
        return NULL;
    }
    result = pointer(x);
    return Py_BuildValue("i", result);
}

// 传入x, y，返回商和余数
static PyObject *py_mod(PyObject *self, PyObject *args){
    int x, y, remainder, result;

    if (! PyArg_ParseTuple(args, "ii", &x, &y)){
        return NULL;
    }

    // 原函数要求remainder为指针类型，所以我们传入remainder地址
    result = mod(x, y, &remainder);
    return Py_BuildValue("ii", result, remainder);
}

// 接收list或者array，转为C的array类型，然后传入avg()
static PyObject *py_avg(PyObject *self, PyObject *args){
    PyObject *obj;
    Py_buffer info;
    double result;

    if (! PyArg_ParseTuple(args, "O", &obj)){
        return NULL;
    }
    //先检查是否为list
    if (PyList_Check(obj)){
        //将list的元素一一取出，放入数组中
        int size = PyList_Size(obj);
        int arr[size];
        for (int i = 0; i < size; i++){
            PyObject *item = PyList_GetItem(obj, i);
            PyArg_Parse(item, "i", &arr[i]);
        }
        result = avg(arr, size);    
    }else{
        //如果不是list，那么把信息保存到缓冲区
        if (PyObject_GetBuffer(obj, &info, PyBUF_ANY_CONTIGUOUS | PyBUF_FORMAT) == -1){
            return NULL;
        }
        // 将info的信息传入函数
        result = avg(info.buf, info.shape[0]);
        // 释放缓存
        PyBuffer_Release(&info);
    }
    return Py_BuildValue("d", result);
}


static PyObject *py_test(PyObject *self, PyObject *args){
    int x, result;

    if (! PyArg_ParseTuple(args, "i", &x)){
        return NULL;
    }
    result = test(x);
    return Py_BuildValue("i", result);
}


// // 数组类型需要先获取信息，将信息保存到 Py_buffer类型的变量中
// static PyObject *py_avg(PyObject *self, PyObject *args){
//     PyObject *bufferObj;
//     Py_buffer info;
//     double result;

//     if (! PyArg_ParseTuple(args, "O", &bufferObj)){
//         return NULL;
//     }
//     // // 获取数组信息并将信息保存到info中
//     // if (PyObject_GetBuffer(bufferObj, &info, PyBUF_ANY_CONTIGUOUS | PyBUF_FORMAT) == -1){
//     //     return NULL;
//     // }

//     // 将info的信息传入函数
//     result = avg(bufferObj, 10);
//     return Py_BuildValue("d", result);
// }

static PyMethodDef SampleMethods[] = {
    {"multiply", py_multiply, METH_VARARGS, "mutiply 2 nums"},
    {"divide", py_divide, METH_VARARGS, "NULL"},
    {"pointer", py_pointer, METH_VARARGS, "NULL"},
    {"mod", py_mod, METH_VARARGS, "NULL"},
    {"avg", py_avg, METH_VARARGS, "NULL"},
    {"test", py_test, METH_VARARGS, "NULL"}
};







static struct PyModuleDef samplemodule ={
    PyModuleDef_HEAD_INIT,
    "sample",
    "A sample modules",
    -1,
    SampleMethods
};

// 模块导出函数
PyMODINIT_FUNC
PyInit_sample(void){
    return PyModule_Create(&samplemodule);
}