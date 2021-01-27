#include "MyCPPClass.h"
#include "MyObject-C-Interface.h"

MyCPPClass::MyCPPClass( void )
    : _impl ( NULL )
{   }

void MyCPPClass::init( void )
{
    _impl = new MyClassImpl();
}

MyCPPClass::~MyCPPClass( void )
{
    if ( _impl ) { delete _impl; _impl = NULL; }
}

void MyCPPClass::doSomethingWithMyClass( void )
{
    int result = _impl->doSomethingWith( _myValue );
    if ( result == cANSWER_TO_LIFE_THE_UNIVERSE_AND_EVERYTHING )
    {
        _impl->logMyMessage( "Hello, Arthur!" );
    }
    else
    {
        _impl->logMyMessage( "Don't worry." );
    }
}