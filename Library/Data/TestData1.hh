/*
 * TestData1.hh
 *
 *  Created on: Jan 6, 2022
 *      Author: N.S. Oblath
 */

#ifndef TTGD_TESTING_TESTDATA1
#define TTGD_TESTING_TESTDATA1

#include "Data.hh"
#include "MemberVariable.hh"

namespace tettigoniidae
{

    class TestData1 : public Nymph::Data
    {
        public:
            TestData1();

            virtual ~TestData1();

            MEMVAR( int, IValue1 );
            MEMVAR( int, IValue2 );
    };

} /* namespace tettigoniidae */

#endif /* TTGD_TESTING_TESTDATA1 */
