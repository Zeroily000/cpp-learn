#include "pybind11/pybind11.h"

namespace py = pybind11;

int add(int i=1, int j=2) {
    return i+j;
}

PYBIND11_MODULE(myPyLib, m) {
    m.doc() = "pybind11 example plugin";

    m.def("add", &add, "A function which add two numbers",
            py::arg("i") = 1,py::arg("j") = 2);

    m.attr("the_answer") = 56;
    py::object world = py::cast("World");
    m.attr("what") = world;
}