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
 *  2. Call <i>+errorWithCode:</i>, <i>errorWithUserInfo:</i>, <i>+errorWithCode:userInfo:</i> or <i>+errorWithError:</i> to create an instance.
 *
 *  Use case 2
 *  1. Create VBError subclass.
 *  2. Implement <i>+code</i> method.
 *  3. Call <i>+error</i>, <i>+errorWithUserInfo:</i> to create an instance.
 *
 */

#define kVBError_noCode -1

#define kVBError_userInfo_originalDomain    @"kVBError_userInfo_originalDomain"
#define kVBError_userInfo_originalCode      @"kVBError_userInfo_originalCode"

@interface VBError : NSError

/**
 *  The main method for error creation.
 *  Calls @code +errorWithUserInfo:nil @endcode
 *  You <b>SHOULD NOT</b> override this method.
 *
 *  @return An VBError object for domain with the specified error code.
 */
+ (instancetype) error;

/**
 *  Creates error with userInfo using defined domain and code.
 *  You <b>SHOULD NOT</b> override this method.
 *
 *  @param userInfo User-defined error information.
 *
 *  @return An VBError object for domain with the specified error code and the dictionary of arbitrary data userInfo.
 */
+ (instancetype) errorWithUserInfo:(NSDictionary*) userInfo;

/**
 *  Creates error with code using defined domain and userInfo=nil.
 *  You <b>SHOULD NOT</b> override this method.
 *
 *  @param code Error code
 *
 *  @return An VBError object for domain with the specified error code.
 */
+ (instancetype) errorWithCode:(NSInteger)code;

/**
 *  Creates error with code and userInfo using defined domain.
 *  You <b>SHOULD NOT</b> override this method.
 *
 *  @param code     Error code
 *  @param userInfo User-defined error information.
 *
 *  @return An VBError object for domain with the specified error code and the dictionary of arbitrary data userInfo.
 */
+ (instancetype) errorWithCode:(NSInteger)code
                      userInfo:(NSDictionary*) userInfo;

/**
 *  You <b>SHOULD NOT</b> override this method.<br>
 *  Creates error based on given one. It helps to quickly transform errors from standard frameworks into smth like KeychainError, NetworkError, JSONError, etc <br>
 *  <b>domain</b> ==    [self domain] <br>
 *  <b>code</b> ==      [self code] if specified, otherwise = error.code <br>
 *  <b>userInfo</b> ==  error.userInfo + originalDomain/originalCode keys for error.domain and error.code info <br>
 *
 *  @param error Original error.
 *
 *  @return An VBError object for domain with the specified error code and the dictionary of arbitrary data userInfo.
 */
+ (instancetype) errorWithError:(NSError*)error;

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
 *  This method <b>SHOULD</b> be implemented in subclass.
 *  <br>Default value = kVBError_noCode
 *
 *  @return NSInteger for code.
 */
+ (NSInteger) code;

@end
