/*
 * TestProcessorClasses.hh
 *
 *  Created on: Nov 25, 2021
 *      Author: N.S. Oblath
 */

#ifndef TTGD_PROCESSORS_ADDER
#define TTGD_PROCESSORS_ADDER

#include "Processor.hh"
#include "SignalData.hh"
#include "SlotData.hh"

namespace tettigoniidae
{
    class IntData;

    // This processor has a data slot that takes TestData1 as input and has no output (TestData1 is modified in place)
    class Adder : public Nymph::Processor
    {
        public:
            Adder( const std::string& name = "adder" );

            virtual ~Adder();

            void Configure( const scarab::param_node& node );

            MEMVAR( int, AddValue );

        public:
            void Add( IntData& data );

        public:
            Nymph::SignalData fIntSignal;

            Nymph::SlotData< Nymph::In<IntData>, Nymph::Out<> > fAddIntSlot;

    };

} /* namespace tettigoniidae */

#endif /* TTGD_PROCESSORS_ADDER */
