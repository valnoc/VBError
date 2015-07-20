//
//    The MIT License (MIT)
//
//    Copyright (c) 2015 Valeriy Bezuglyy.
//
//    Permission is hereby granted, free of charge, to any person obtaining a copy
//    of this software and associated documentation files (the "Software"), to deal
//    in the Software without restriction, including without limitation the rights
//    to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
//    copies of the Software, and to permit persons to whom the Software is
//    furnished to do so, subject to the following conditions:
//
//    The above copyright notice and this permission notice shall be included in all
//    copies or substantial portions of the Software.
//
//    THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
//    IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
//    FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
//    AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
//    LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
//    OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
//    SOFTWARE.
//

#import <Foundation/Foundation.h>

/**
 *  VBError is a base class for your own errors.
 *  Create a subclass and implement <i>+domain</i> and <i>+code</i> methods to provide useful error information.
 */
@interface VBError : NSError

/**
 *  The main method for error creation.
 *  Calls @code +errorWithUserInfo:nil @endcode
 *  You should NOT override this method.
 *
 *  @return An VBError object for domain with the specified error code.
 */
+ (instancetype) error;

/**
 *  Creates error with userInfo.
 *  You should NOT override this method.
 *
 *  @param userInfo User-defined exception information.
 *
 *  @return An VBError object for domain with the specified error code and the dictionary of arbitrary data userInfo.
 */
+ (instancetype) errorWithUserInfo:(NSDictionary*) userInfo;

#pragma mark - default values
/**
 *  Error domain. 
 *  Default implementation returns bundleIdentifier. Add your own domain part by calling @code [[super domain] stringByAppendingString:] @endcode
 *
 *  @return NSSring to be used as error domain.
 */
+ (NSString *) domain;

/**
 *  Error code.
 *  This method MUST be implemented in subclass.
 *
 *  @return NSInteger for code.
 */
+ (NSInteger) code;

@end
