/*
The "bridge" class. All methods sohuld defer to respective methods of objc file MyClass
Maybe could use some helper functions
*/

#import "MyObject.h"

@implementation MyObject

MyClassImpl::MyClassImpl( void )
    : self( NULL )
{   }

MyClassImpl::~MyClassImpl( void )
{
    [(id)self dealloc];
}

void MyClassImpl::init( void )
{    
    self = [[MyObject alloc] init];
}

int MyClassImpl::doSomethingWith( void *aParameter )
{
    return [(id)self doSomethingWith:aParameter];
}

void MyClassImpl::logMyMessage( char *aCStr )
{
    [(id)self doLogMessage:aCStr];
}

- (int) doSomethingWith:(void *) aParameter
{
    int result;

    result = 5;
    // ... some code to calculate the result

    return result;
}

- (void) logMyMessage:(char *) aCStr
{
    // NSLog( aCStr );
    NSLog(@"Hello World");
}

@end