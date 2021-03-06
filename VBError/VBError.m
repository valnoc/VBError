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

#import "VBError.h"

@implementation VBError

+ (instancetype) error {
    return [self errorWithUserInfo:nil];
}

+ (instancetype) errorWithUserInfo:(NSDictionary*) userInfo {
    return [self errorWithDomain:[self domain]
                            code:[self code]
                        userInfo:userInfo];
}

+ (instancetype) errorWithCode:(NSInteger)code {
    return [self errorWithDomain:[self domain]
                            code:code
                        userInfo:nil];
}

+ (instancetype) errorWithCode:(NSInteger)code
                      userInfo:(NSDictionary*) userInfo {
    return [self errorWithDomain:[self domain]
                            code:code
                        userInfo:userInfo];
}

+ (instancetype) errorWithError:(NSError*)error {
    NSMutableDictionary* userInfo = [NSMutableDictionary new];
    [userInfo addEntriesFromDictionary:error.userInfo];
    userInfo[kVBError_userInfo_originalDomain] = error.domain;
    userInfo[kVBError_userInfo_originalCode] = @(error.code);
    
    NSInteger code = [self code] == kVBError_noCode ? error.code : kVBError_noCode;
    
    return [self errorWithCode:code
                      userInfo:[NSDictionary dictionaryWithDictionary:userInfo]];
}

#pragma mark - default values
+ (NSString *) domain {
    return [[NSBundle mainBundle].bundleIdentifier stringByAppendingPathComponent:NSStringFromClass(self)];
}

+ (NSInteger) code {
    return kVBError_noCode;
}

@end
