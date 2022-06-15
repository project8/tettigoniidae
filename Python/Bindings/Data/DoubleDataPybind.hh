/*
 * DoubleDataPybind.hh
 *
 *  Created on: Jun 15, 2022
 *      Author: A. Ziegler
 */

#ifndef PYTHON_BINDINGS_DATA_DOUBLEDATAPYBIND_HH_
#define PYTHON_BINDINGS_DATA_DOUBLEDATAPYBIND_HH_

#include <pybind11/pybind11.h>
#include <memory>

#include "DoubleData.hh"

namespace py = pybind11;

namespace tettigoniidaePybind
{

    void ExportDoubleData( py::module_& tettigoniidaeData)
    {
        py::class_< tettigoniidae::DoubleData >(tettigoniidaeData, "DoubleData")
                .def(py::init< >())
                .def_property("DValue1", &tettigoniidae::DoubleData::GetDValue1, &tettigoniidae::DoubleData::SetDValue1)
                .def_property("DValue2", &tettigoniidae::DoubleData::GetDValue2, &tettigoniidae::DoubleData::SetDValue2);

    }

}

#endif /* PYTHON_BINDINGS_DATA_DOUBlEDATAPYBIND_HH_ */

