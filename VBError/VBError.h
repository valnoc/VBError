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
 *  VBError is a base class for your own errors. It makes error creation and handling more effective.
 *  When handling error you can check class instead of making domain+code check. 
 *  You can also create same errors(domain+code) in different parts of code by creating an instance of the same VBError subclass.
 *
 *  Use case 1.
 *  1. Create VBError subclass.
 *  2. Call <i>+errorWithCode:</i> or <i>+errorWithCode:userInfo:</i> to create an instance.
 *
 *  Use case 2
 *  1. Create VBError subclass.
 *  2. Implement <i>+code</i> method.
 *  3. Call <i>+error</i>, <i>+errorWithUserInfo:</i> to create an instance.
 *
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
 *  Creates error with userInfo using defined domain and code.
 *  You should NOT override this method.
 *
 *  @param userInfo User-defined error information.
 *
 *  @return An VBError object for domain with the specified error code and the dictionary of arbitrary data userInfo.
 */
+ (instancetype) errorWithUserInfo:(NSDictionary*) userInfo;

/**
 *  Creates error with code using defined domain and userInfo=nil.
 *  You should NOT override this method.
 *
 *  @param code Error code
 *
 *  @return An VBError object for domain with the specified error code.
 */
+ (instancetype) errorWithCode:(NSInteger)code;

/**
 *  Creates error with code and userInfo using defined domain.
 *  You should NOT override this method.
 *
 *  @param code     Error code
 *  @param userInfo User-defined error information.
 *
 *  @return An VBError object for domain with the specified error code and the dictionary of arbitrary data userInfo.
 */
+ (instancetype) errorWithCode:(NSInteger)code
                      userInfo:(NSDictionary*) userInfo;

#pragma mark - default values
/**
 *  Error domain. 
 *  Default implementation returns <i>bundleIdentifier.className</i>
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
