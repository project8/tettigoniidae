/*
 * tettigoniidaePybind.cc
 *
 *  Created on: Jun 14, 2022
 *      Author: A. Ziegler
 */

#include <pybind11/pybind11.h>

#include "Data/IntDataPybind.hh"
#include "Data/DoubleDataPybind.hh"

namespace py = pybind11;


PYBIND11_MODULE(_tettigoniidae, tettigoniidaePackage) {

    tettigoniidaePackage.doc() = "Tettigoniidae package";

    auto tettigoniidaeData = tettigoniidaePackage.def_submodule("data", "Data module");
    tettigoniidaePybind::ExportIntData(tettigoniidaeData);
    tettigoniidaePybind::ExportDoubleData(tettigoniidaeData);
}