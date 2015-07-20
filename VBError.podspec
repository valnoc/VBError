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
  s.version          = "1.0.0"
  s.summary          = "VBError is a base class for your own errors."
  s.description      = <<-DESC
                       VBError is a base class for your own errors.
Create a subclass and implement <i>+domain</i> and <i>+code</i> methods to provide useful error information.
                       DESC
  s.homepage         = "https://github.com/valnoc/VBError"

  s.license          = 'MIT'
  s.author           = { "Valeriy Bezuglyy" => "valnocorner@gmail.com" }
  s.source           = { :git => "https://github.com/valnoc/VBError.git", :tag => "v#{s.version}" }

  s.platform     = :ios, '7.0'
  s.requires_arc = true

  s.source_files = 'VBError/**/*'

end
