#import "MyObject-C-Interface.h"
#import <Foundation/NSObject.h>
#import <Foundation/Foundation.h>

@interface MyObject : NSObject
{
    int someVar;
}

- (int)  doSomethingWith:(void *) aParameter;
- (void) logMyMessage:(char *) aCStr;

@end