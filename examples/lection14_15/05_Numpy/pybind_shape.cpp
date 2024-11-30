// pybind_shape.cpp
#include <pybind11/pybind11.h>
#include <pybind11/numpy.h>
#include "circle.h"

namespace py = pybind11;

PYBIND11_MODULE(shapes_numpy, m) {
    py::class_<Shape>(m, "Shape")
        .def("area", &Shape::area)
        .def("perimeter", &Shape::perimeter)
        .def("getName", &Shape::getName);

    py::class_<Circle, Shape>(m, "Circle")
        .def(py::init<double>());

    // Пример функции, которая принимает numpy массив
    m.def("process_array", [](py::array_t<double> array) {
        auto buf = array.request();
        double *ptr = static_cast<double *>(buf.ptr);
        size_t size = buf.size;

        // Пример обработки массива
        double sum = 0;
        for (size_t i = 0; i < size; ++i) {
            sum += ptr[i];
        }

        return sum;
    });
}