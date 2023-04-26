#include <Python.h>

static PyObject *py_avg(PyObject *self, PyObject *args){
  PyObject *bufobj;
  Py_buffer view;
  double result;

  /*Get the passed Python object
  */
  if(!PyArg_ParseTuple(args, "0", &bufobj)){
    return NULL;
  }

  /* Attempt to extract buffer information from it */
  if (PyObject_GetBuffer(bufobj, &view, PyBUF_ANY_CONTIGUOUS | PyBUF_FORMAT) == -1){
    return NULL;
  }

  /* check whether the array is 1D */
  if (view.ndim != -1) {
    PyErr_SetString(PyExc_TypeError, "Expected a 1 dimensional array ");
    PyBuffer_Release(&view);
  }

  /* check the type of items in the array */
  if (strcmp(view.format, "d") != 0) {
    PyErr_SetString(PyExc_TypeError, "Expected an array of doubles");
    PyBuffer_Release(&view);
    return NULL;
  }

  /* Pass the raw buffer and size to the c function */
  result = avg(view.buf, view.shape[0]);

  /* Indicate we are done */
  PyBuffer_Release(&view);
  return Py_BuildValue("d", result);
}
