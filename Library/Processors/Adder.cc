
#include "Adder.hh"

#include "IntData.hh"


REGISTER_PROCESSOR( tettigoniidae, Adder, "adder" )

namespace tettigoniidae
{
    Adder::Adder( const std::string& name ) :
            Processor( name ),
            fAddValue( 0 ),
            fIntSignal( "int", this ),
            fAddIntSlot( "add-int", this, &Adder::Add, &fIntSignal )
    {}

    Adder::~Adder()
    {}

    void Adder::Configure( const scarab::param_node& node )
    {
        fAddValue = node.get_value( "to-add", fAddValue );

        return;
    }

    void Adder::Add( IntData& data )
    {
        data.SetIValue1( data.GetIValue1() + fAddValue );
        data.SetIValue2( data.GetIValue2() + fAddValue );
        return;
    }

} /* namespace tettigoniidae */
