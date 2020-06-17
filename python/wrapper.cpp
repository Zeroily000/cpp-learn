#include <pybind11/pybind11.h>
#include <pybind11/stl.h>

//#include "cpp-learn.hpp"

namespace py = pybind11;

PYBIND11_MODULE(cppLearnPyLib, m) {
    m.doc() = "python binding example";

//    py::class_<CppLearn>(m, "CppLearn")
//        .def(py::init<>())
//        .def_static("findLeft", &CppLearn::findLeft<int>,
//                    "Binary search a sorted array, return the first index of the target if exists, otherwise, return the index of the next largest element",
//                    py::arg("nums"), py::arg("target"))
//        .def_static("findRight", &CppLearn::findRight<int>,
//                    "Binary search a sorted array, return the last index of the target it exists, otherwise, return the index of the next smallest element",
//                    py::arg("nums"), py::arg("target"))
//        ;

    m.attr("the_answer") = 56;
    py::object world = py::cast("World");
    m.attr("what") = world;
}
