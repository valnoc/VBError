VBError
===========

VBError is a base class for your own errors. It makes error creation and handling more effective.

When handling error you can check class instead of making domain+code check. 

You can also create same errors(domain+code) in different parts of code by creating an instance of the same VBError subclass.

Use case 1.

1. Create VBError subclass.
2. Implement <i>+domain</i> method.
3. Call <i>+errorWithCode:</i> or <i>+errorWithCode:userInfo:</i> to create an instance.

Use case 2

1. Create VBError subclass.
2. Implement <i>+domain</i> and <i>+code</i> values.
3. Call <i>+error</i> or <i>+errorWithUserInfo:</i> to create an instance.

## How to install
Use CocoaPods

    pod 'VBError'

or

Drag VBError dir into your project.

## License
VBError is available under the MIT license. See the LICENSE file for more info.

