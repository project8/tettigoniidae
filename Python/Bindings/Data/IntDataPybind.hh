/*
 * IntDataPybind.hh
 *
 *  Created on: Jun 14, 2022
 *      Author: A. Ziegler
 */

#ifndef PYTHON_BINDINGS_DATA_INTDATAPYBIND_HH_
#define PYTHON_BINDINGS_DATA_INTDATAPYBIND_HH_

#include <pybind11/pybind11.h>
#include <memory>

#include "IntData.hh"

namespace py = pybind11;

namespace tettigoniidaePybind
{

    void ExportIntData( py::module_& tettigoniidaeData)
    {
        py::class_< tettigoniidae::IntData >(tettigoniidaeData, "IntData")
                .def(py::init< >())
                .def_property("IValue1", &tettigoniidae::IntData::GetIValue1, &tettigoniidae::IntData::SetIValue1)
                .def_property("IValue2", &tettigoniidae::IntData::GetIValue2, &tettigoniidae::IntData::SetIValue2);
    }

}

#endif /* PYTHON_BINDINGS_DATA_INTDATAPYBIND_HH_ */

