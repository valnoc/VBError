VBError
===========

VBError makes error creation and handling more effective.

It can be used as a base class for your own errors. Create VBError subclass. Implement domain and code default values. Call <i>+error</i> or <i>+errorWithUserInfo:</i> to create an instance.
Using subclassing allows to create errors by short call [VBErrorSubclass error]. When handling error you can only check for class instead of making domain+error check.

You can also implement only default domain and call <i>+errorWithCode:</i> or <i>+errorWithCode:userInfo:</i>.

## How to install
Use CocoaPods

    pod 'VBError'

or

Drag VBError dir into your project.

## License
VBError is available under the MIT license. See the LICENSE file for more info.

