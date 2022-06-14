/*
 * TettigoniidaePybind.cc
 *
 *  Created on: Jun 14, 2022
 *      Author: A. Ziegler
 */

#include <pybind11/pybind11.h>

#include "Processor/AdderPybind.hh"
#include "Data/IntDataPybind.hh"

namespace py = pybind11;


PYBIND11_MODULE(_tettigoniidae, tettigoniidaePackage) {

    tettigoniidaePackage.doc() = "Tettigoniidae package";

    //auto nymphControl = nymphPackage.def_submodule("control", "Control module");
    auto tettigoniidaeData = tettigoniidaePackage.def_submodule("data", "Data module");
    TettigoniidaePybind::ExportData(tettigoniidaeData);
    //auto nymphImplementation = nymphPackage.def_submodule("implementation", "Implementation module");
    auto tettigoniidaeProcessor = tettigoniidaePackage.def_submodule("processor", "Processor module");
    TettigoniidaePybind::ExportProcessor(tettigoniidaeProcessor);
    //auto nymphUtility = nymphPackage.def_submodule("utility", "Utility module");
}
