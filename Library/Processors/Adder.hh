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

    /*!
     @class Adder
     @author N. S. Oblath

     @brief Adds a value to data in place.

     @details
     Addition is performed in place

     Processor type: adder

     Available configuration options:
     - int-value: int -- Value to add to IntData

     Slots:
     - add-int: Adds a value to IntData; Requires IntData; Adds no data; Emits signal "int"

     Signals:
     - int: void (Nymph::DataHandle) -- Emitted after adding to IntData
    */
    class Adder : public Nymph::Processor
    {
        public:
            Adder( const std::string& name = "adder" );

            virtual ~Adder();

            void Configure( const scarab::param_node& node );

            MEMVAR( int, IntValue );

        public:
            void Add( IntData& data );

        public:
            Nymph::SignalData fIntSignal;

            Nymph::SlotData< Nymph::In<IntData>, Nymph::Out<> > fAddIntSlot;

    };

} /* namespace tettigoniidae */

#endif /* TTGD_PROCESSORS_ADDER */
