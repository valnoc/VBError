VBError
===========
[![](https://img.shields.io/cocoapods/v/VBError.svg)]()

VBError is a base class for your own errors. It makes error creation and handling more effective.

When handling error you can check class instead of making domain+code check. 

You can also create same errors(domain+code) in different parts of code by creating an instance of the same VBError subclass.

Use case 1.

1. Create VBError subclass.
2. Call <i>+errorWithCode:</i>, <i>errorWithUserInfo:</i>, <i>+errorWithCode:userInfo:</i> or <i>+errorWithError:</i> to create an instance.

Use case 2

1. Create VBError subclass.
2. Implement <i>+code</i> method.
3. Call <i>+error</i>, <i>+errorWithUserInfo:</i> to create an instance.

## How to install
Use CocoaPods

    pod 'VBError'

or

Drag VBError dir into your project.

## License
VBError is available under the MIT license. See the LICENSE file for more info.

