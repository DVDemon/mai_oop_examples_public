// pybind_shape.cpp
#include <pybind11/pybind11.h>
#include "circle.h"

namespace py = pybind11;

PYBIND11_MODULE(shapes, m) {
    py::class_<Shape>(m, "Shape")
        .def("area", &Shape::area)
        .def("perimeter", &Shape::perimeter)
        .def("getName", &Shape::getName);

    py::class_<Circle, Shape>(m, "Circle")
        .def(py::init<double>());
}