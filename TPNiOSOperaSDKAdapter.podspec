Pod::Spec.new do |spec|
  spec.name         = "TPNiOSOperaSDKAdapter"
  spec.version      = "2.9.1.0"
  spec.summary      = "Opera Ads Custom Adapter for TopOn/AnyThink Mediation Platform."
  spec.description  = <<-DESC
    TPNiOSOperaSDKAdapter is a custom mediation adapter that enables the integration of
    Opera Advertising SDK (OpAdxSdk) with the TopOn (AnyThink) mediation platform.

    Supported Ad Formats:
    - Banner Ads (Standard, MREC)
    - Interstitial Ads
    - Rewarded Video Ads
    - Native Ads
    - Splash/App Open Ads

    This adapter bridges Opera Ads SDK callbacks to TopOn mediation callbacks,
    enabling seamless ad serving through the TopOn platform.
  DESC

  spec.homepage     = "https://github.com/operaads/TPNiOSOperaSDKAdapter"
  spec.license      = { :type => "MIT", :file => "LICENSE" }
  spec.author       = { "Opera Ads" => "chenl@opera.com" }

  spec.platform     = :ios, "13.0"
  spec.ios.deployment_target = "13.0"
  spec.swift_version = "5.0"

  spec.source       = {
    :git => "https://github.com/operaads/TPNiOSOperaSDKAdapter.git",
    :tag => "#{spec.version}"
  }

  spec.static_framework = true
  
  spec.vendored_frameworks = "OpAdxAdapterTopon.xcframework"

  # spec.source_files  = "OpAdxAdapterTopon/CustomAdapter_6.5.xx/**/*.{h,m}"

  # spec.public_header_files = "OpAdxAdapterTopon/CustomAdapter_6.5.xx/**/*.h"

  spec.dependency 'TPNiOS', '>= 6.5.34'
  spec.dependency 'OpAdxSdk', '2.9.1'

  # spec.pod_target_xcconfig = {
  #   'OTHER_LDFLAGS' => '-ObjC',
  #   'VALID_ARCHS' => 'arm64 x86_64'
  # }

  # spec.requires_arc = true

end
