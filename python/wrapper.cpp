#include <pybind11/pybind11.h>
#include <pybind11/stl.h>

#include "base.hpp"
#include "derived.hpp"

namespace py = pybind11;

PYBIND11_MODULE(cppLearnPyLib, m) {
    m.doc() = "python binding example";

    m.attr("the_answer") = 56;
    py::object world = py::cast("World");
    m.attr("what") = world;

    py::class_<cpplearn::Base>(m, "Base")
            .def(py::init<>())
            .def_readwrite("m_public_string", &cpplearn::Base::m_public_string)
            .def("getProtectedString", &cpplearn::Base::getProtectedString);

    py::class_<cpplearn::Derived, cpplearn::Base, std::unique_ptr<cpplearn::Derived, py::nodelete>>(m, "Derived")
            .def(py::init([](){
                return std::unique_ptr<cpplearn::Derived, py::nodelete>(&cpplearn::Derived::getInstance());
            }));
}
