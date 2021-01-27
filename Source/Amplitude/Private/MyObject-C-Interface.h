// Common C-only interface understood by both ObjC and C++
#ifndef __MYOBJECT_C_INTERFACE_H__
#define __MYOBJECT_C_INTERFACE_H__

class MyClassImpl // MyClass === an ObjC class
{
public:
    MyClassImpl ( void );
    ~MyClassImpl( void );

    void init( void ); // Used to instantiate instance of MyClass
    int  doSomethingWith( void * aParameter );
    void logMyMessage( char * aCStr );

private:
    void * self; // Pointer to ObjC object
};

#endif