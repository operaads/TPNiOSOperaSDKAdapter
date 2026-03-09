Pod::Spec.new do |spec|
  # ――― 基本信息 ―――――――――――――――――――――――――――――――――――――――――――――――――――――――――― #
  spec.name         = "TPNiOSOperaSDKAdapter"
  spec.version      = "2.8.1.0"
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

  spec.homepage     = "https://github.com/luanchen/TPNiOSOperaSDKAdapter"
  spec.license      = { :type => "MIT", :file => "LICENSE" }
  spec.author       = { "Opera Ads" => "chenl@opera.com" }

  # ――― 平台设置 ――――――――――――――――――――――――――――――――――――――――――――――――――――――――――― #
  spec.platform     = :ios, "13.0"
  spec.ios.deployment_target = "13.0"

  # ――― 源码位置 ―――――――――――――――――――――――――――――――――――――――――――――――――――――――――― #
  spec.source       = { 
    :git => "https://github.com/luanchen/TPNiOSOperaSDKAdapter.git", 
    :tag => "#{spec.version}" 
  }

  # ――― 文件与依赖配置 ―――――――――――――――――――――――――――――――――――――――――――――――――――――――――― #
  
  # 制作静态包的关键设置
  spec.static_framework = true

  # 源码路径 - 适配TopOn 6.5.xx版本
  spec.source_files  = "OpAdxAdapterTopon/CustomAdapter_6.5.xx/**/*.{h,m}"
  
  # 公开头文件
  spec.public_header_files = [
    "OpAdxAdapterTopon/CustomAdapter_6.5.xx/AdapterVersion.h",
    "OpAdxAdapterTopon/CustomAdapter_6.5.xx/Base/*.h",
    "OpAdxAdapterTopon/CustomAdapter_6.5.xx/Banner/*.h",
    "OpAdxAdapterTopon/CustomAdapter_6.5.xx/Interstitial/*.h",
    "OpAdxAdapterTopon/CustomAdapter_6.5.xx/Native/*.h",
    "OpAdxAdapterTopon/CustomAdapter_6.5.xx/RewardVideo/*.h",
    "OpAdxAdapterTopon/CustomAdapter_6.5.xx/Splash/*.h"
  ]

  # --- 依赖项 ---
  # TopOn SDK - 要求6.5.34或更高版本
  spec.dependency 'TPNiOS', '>= 6.5.34'
  
  # Opera Ads SDK - 使用CocoaPods发布的版本
  spec.dependency 'OpAdxSdk', '>= 2.8.0'

  # ――― 工程配置 ―――――――――――――――――――――――――――――――――――――――――――――――――――――――――― #
  # 静态库需要 -ObjC 标志以加载 Category
  spec.pod_target_xcconfig = { 
    'OTHER_LDFLAGS' => '-ObjC',
    'VALID_ARCHS' => 'arm64 x86_64'
  }
  
  # Swift版本（如果有Swift代码）
  # spec.swift_version = '5.0'

  # ――― 元数据 ―――――――――――――――――――――――――――――――――――――――――――――――――――――――――――― #
  spec.requires_arc = true
  
end
