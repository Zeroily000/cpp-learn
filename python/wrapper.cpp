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
      .def("get_protected_string", &cpplearn::Base::GetProtectedString);

  py::class_<cpplearn::Derived, cpplearn::Base>(m, "Derived")
      .def_static("get_instance", &cpplearn::Derived::GetInstance, py::return_value_policy::reference);
}
