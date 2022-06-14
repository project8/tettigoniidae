/*!
 * @file Adder.hh
 *
 *  Created on: Jun 14, 2022
 *      Author: A. Ziegler
 */

 #ifndef PYTHON_BINDINGS_TTGD_PROCESSOR_ADDER
 #define PYTHON_BINDINGS_TTGD_PROCESSOR_ADDER

 #include <pybind11/pybind11.h>
 #include "Adder.hh"
 #include "factory.hh"

 namespace py = pybind11;

 namespace tettigoniidaePybind
 {
     //trampoline class
    class PyAdder : public tettigoniidae::Adder {
        public:
            /* Inherit the constructors */
            using tettigoniidae::Adder::Adder;

            /* Trampoline (need one for each virtual function) */
            //void Configure( const scarab::param_node& node ) override {
            //    PYBIND11_OVERRIDE_PURE(
            //        void, /* Return type */
            //        Processor,      /* Parent class */
            //        Configure,          /* Name of function in C++ (must match Python name) */
            //        node/* Argument(s) */
            //    );
            //}

    void ExportProcessor( py::module_& nymphProcessor)
    {
        py::class_< Nymph::Processor, PyProcessor, std::shared_ptr<Nymph::Processor> >(nymphProcessor, "_Processor")
                .def(py::init<const std::string& >())
                .def("configure", &Nymph::Processor::Configure)
                .def("connect_signal_to_slot", &Nymph::Processor::ConnectSignalToSlot)
                .def("connect_a_slot", &Nymph::Processor::ConnectASlot)
                .def("connect_a_signal", &Nymph::Processor::ConnectASignal)
                .def("register_signal", &Nymph::Processor::RegisterSignal)
                .def("register_slot", &Nymph::Processor::RegisterSlot)
                .def("get_do_breakpoint", &Nymph::Processor::GetDoBreakpoint)
                .def("set_do_breakpoint", &Nymph::Processor::SetDoBreakpoint);
                //.def_property_readonly("name", &Nymph::Processor::Name);
        
        nymphProcessor.def("get_processor", &get_processor);
        
        //unfortunately this has to go into library code
        //for some reason the factory in the wrapped get_processor function above 
        //cannot find the test-proc when it is registered after the library was compiled
        //REGISTER_PROCESSOR(Nymph, TestProc, "test-proc");
    }
    };
 }

