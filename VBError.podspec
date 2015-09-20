#
# Be sure to run `pod lib lint MyLib.podspec' to ensure this is a
# valid spec and remove all comments before submitting the spec.
#
# Any lines starting with a # are optional, but encouraged
#
# To learn more about a Podspec see http://guides.cocoapods.org/syntax/podspec.html
#

Pod::Spec.new do |s|
  s.name             = "VBError"
  s.version          = "1.1.0"
  s.summary          = "VBError is a base class for your own errors."
  s.description      = <<-DESC
VBError is a base class for your own errors. It makes error creation and handling more effective.

When handling error you can check class instead of making domain+code check.

You can also create same errors(domain+code) in different parts of code by creating an instance of the same VBError subclass.

Use case 1.
1. Create VBError subclass.
2. Call <i>+errorWithCode:</i>, <i>errorWithUserInfo:</i> or <i>+errorWithCode:userInfo:</i> to create an instance.

Use case 2
1. Create VBError subclass.
2. Implement <i>+code</i> method.
3. Call <i>+error</i>, <i>+errorWithUserInfo:</i> to create an instance.
                       DESC
  s.homepage         = "https://github.com/valnoc/VBError"

  s.license          = 'MIT'
  s.author           = { "Valeriy Bezuglyy" => "valnocorner@gmail.com" }
  s.source           = { :git => "https://github.com/valnoc/VBError.git", :tag => "v#{s.version}" }

  s.platform     = :ios, '8.0'
  s.requires_arc = true

  s.source_files = 'VBError/**/*'

end
