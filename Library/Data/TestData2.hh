/*
 * TestData2.hh
 *
 *  Created on: Jan 6, 2022
 *      Author: N.S. Oblath
 */

#ifndef TTGD_TESTING_TESTDATA2
#define TTGD_TESTING_TESTDATA2

#include "Data.hh"
#include "MemberVariable.hh"

namespace tettigoniidae
{

    class TestData2 : public Nymph::Data
    {
        public:
            TestData2();

            virtual ~TestData2();

            MEMVAR( double, DValue1 );
            MEMVAR( double, DValue2 );
    };


} /* namespace tettigoniidae */

#endif /* TTGD_TESTING_TESTDATA2 */
