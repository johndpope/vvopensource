
#if IPHONE
#import <UIKit/UIKit.h>
#else
#import <Cocoa/Cocoa.h>
#endif

#include <stdio.h>
#import "OSCBundle.h"
#import "OSCMessage.h"



///	Used to parse raw OSC data or to assemble raw OSC data from OSCMessages/OSCBundles
/*!
An OSC packet is the basic unit of transmitting OSC data- the OSCPacket class is mostly used internally to either parse received raw data or to assemble raw data from OSCMessages/OSCBundles for sending.
*/

@interface OSCPacket : NSObject {
	int					bufferLength;
	unsigned char		*payload;
}

+ (void) parseRawBuffer:(unsigned char *)b ofMaxLength:(int)l toInPort:(id)p;
///	Creates & returns an auto-released packet from either an OSCBundle or an OSCMessage
+ (id) createWithContent:(id)c;
- (id) initWithContent:(id)c;

- (int) bufferLength;
- (unsigned char *) payload;

@end
