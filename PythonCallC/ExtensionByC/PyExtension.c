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

static PyMethodDef SampleMethods[] = {
    {"multiply", py_multiply, METH_VARARGS, "mutiply 2 nums"}
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