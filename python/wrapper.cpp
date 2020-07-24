#include <pybind11/pybind11.h>
#include <pybind11/stl.h>

#include "base.hpp"

namespace py = pybind11;

PYBIND11_MODULE(cppLearnPyLib, m) {
    m.doc() = "python binding example";

    m.attr("the_answer") = 56;
    py::object world = py::cast("World");
    m.attr("what") = world;
    py::class_<cpplearn::Base>(m, "Base")
            .def(py::init<>())
            .def("getProtectedString", &cpplearn::Base::getProtectedString);
}
