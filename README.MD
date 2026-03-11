# TPNiOSOperaSDKAdapter

Opera Ads SDK 的 TopOn/AnyThink 聚合平台自定义适配器。

[![CocoaPods Compatible](https://img.shields.io/cocoapods/v/TPNiOSOperaSDKAdapter.svg)](https://cocoapods.org/pods/TPNiOSOperaSDKAdapter)
[![Platform](https://img.shields.io/cocoapods/p/TPNiOSOperaSDKAdapter.svg?style=flat)](https://cocoapods.org/pods/TPNiOSOperaSDKAdapter)
[![License](https://img.shields.io/cocoapods/l/TPNiOSOperaSDKAdapter.svg?style=flat)](https://github.com/operaads/TPNiOSOperaSDKAdapter/blob/main/LICENSE)

[English](README_EN.MD) | 简体中文

## 概述

TPNiOSOperaSDKAdapter 是一个自定义聚合适配器，使 Opera Advertising SDK (OpAdxSdk) 能够与 TopOn (AnyThink) 聚合平台无缝集成。该适配器将 Opera Ads SDK 的回调桥接到 TopOn 的聚合回调，实现通过 TopOn 平台进行广告投放。

## 支持的广告格式

- ✅ Banner 广告（标准、MREC）
- ✅ 插屏广告（Interstitial）
- ✅ 激励视频广告（Rewarded Video）
- ✅ 原生广告（Native）
- ✅ 开屏广告/App Open 广告（Splash/App Open）

## 版本要求

- iOS 13.0+
- TopOn SDK 6.5.34+
- OpAdxSdk 2.8.3
- Xcode 13.0+

## 安装

### CocoaPods

在您的 `Podfile` 中添加：

```ruby
# TopOn SDK
pod 'TPNiOS', '~> 6.5.34'

# Opera Ads SDK
pod 'OpAdxSdk', '2.8.3'

# Opera Ads TopOn 适配器
pod 'TPNiOSOperaSDKAdapter', '2.8.3.0'
```

然后运行：

```bash
pod install
```

## 快速开始

### 1. 初始化 TopOn SDK

```objective-c
#import <AnyThinkSDK/AnyThinkSDK.h>

// 在 AppDelegate 中初始化
- (BOOL)application:(UIApplication *)application 
    didFinishLaunchingWithOptions:(NSDictionary *)launchOptions {
    
    // 配置 TopOn
    [[ATAPI sharedInstance] setAppID:@"your_topon_app_id" 
                              appKey:@"your_topon_app_key"];
    
    // 添加 Opera Ads 为自定义广告平台
    // TopOn 会自动识别并使用 OpAdxToponInitAdapter
    
    return YES;
}
```

### 2. 配置广告位

在 TopOn 后台配置广告位时：

1. 选择"自定义广告平台"
2. 填写服务器参数（JSON格式）：

```json
{
  "app_id": "your_opera_app_id",
  "bundle_id": "your_bundle_id",
  "slot_id": "your_opera_placement_id"
}
```

### 3. 加载和展示广告

使用 TopOn 标准 API 加载和展示广告：

#### Banner 广告

```objective-c
#import <AnyThinkSDK/AnyThinkSDK.h>

@interface BannerViewController () <ATBannerDelegate>
@property (nonatomic, strong) ATBannerView *bannerView;
@end

@implementation BannerViewController

- (void)loadBanner {
    self.bannerView = [[ATBannerView alloc] initWithPlacementID:@"topon_placement_id"
                                                          frame:CGRectMake(0, 0, 320, 50)];
    self.bannerView.delegate = self;
    [self.bannerView loadAD];
}

#pragma mark - ATBannerDelegate

- (void)didFinishLoadingADWithBannerView:(ATBannerView *)bannerView {
    NSLog(@"Banner 加载成功");
    [self.view addSubview:bannerView];
}

- (void)didFailToLoadADWithBannerView:(ATBannerView *)bannerView error:(NSError *)error {
    NSLog(@"Banner 加载失败: %@", error);
}

@end
```

#### 插屏广告

```objective-c
#import <AnyThinkSDK/AnyThinkSDK.h>

@interface InterstitialViewController () <ATInterstitialDelegate>
@end

@implementation InterstitialViewController

- (void)loadInterstitial {
    [[ATAdManager sharedManager] loadADWithPlacementID:@"topon_placement_id"
                                                 extra:nil
                                              delegate:self];
}

- (void)showInterstitial {
    if ([[ATAdManager sharedManager] interstitialReadyForPlacementID:@"topon_placement_id"]) {
        [[ATAdManager sharedManager] showInterstitialWithPlacementID:@"topon_placement_id"
                                                              inViewController:self
                                                                      delegate:self];
    }
}

#pragma mark - ATInterstitialDelegate

- (void)didFinishLoadingADWithPlacementID:(NSString *)placementID {
    NSLog(@"插屏广告加载成功");
}

- (void)didFailToLoadADWithPlacementID:(NSString *)placementID error:(NSError *)error {
    NSLog(@"插屏广告加载失败: %@", error);
}

- (void)didShowInterstitialWithPlacementID:(NSString *)placementID {
    NSLog(@"插屏广告展示");
}

@end
```

#### 激励视频广告

```objective-c
#import <AnyThinkSDK/AnyThinkSDK.h>

@interface RewardedViewController () <ATRewardedVideoDelegate>
@end

@implementation RewardedViewController

- (void)loadRewardedVideo {
    [[ATAdManager sharedManager] loadADWithPlacementID:@"topon_placement_id"
                                                 extra:nil
                                              delegate:self];
}

- (void)showRewardedVideo {
    if ([[ATAdManager sharedManager] rewardedVideoReadyForPlacementID:@"topon_placement_id"]) {
        [[ATAdManager sharedManager] showRewardedVideoWithPlacementID:@"topon_placement_id"
                                                       inViewController:self
                                                               delegate:self];
    }
}

#pragma mark - ATRewardedVideoDelegate

- (void)didFinishLoadingADWithPlacementID:(NSString *)placementID {
    NSLog(@"激励视频加载成功");
}

- (void)didRewardSuccessForPlacemenID:(NSString *)placementID extra:(NSDictionary *)extra {
    NSLog(@"用户获得奖励");
}

@end
```

#### 原生广告

```objective-c
#import <AnyThinkSDK/AnyThinkSDK.h>

@interface NativeViewController () <ATNativeADDelegate>
@end

@implementation NativeViewController

- (void)loadNative {
    [[ATAdManager sharedManager] loadADWithPlacementID:@"topon_placement_id"
                                                 extra:@{kATExtraInfoNativeAdSizeKey: [NSValue valueWithCGSize:CGSizeMake(320, 250)]}
                                              delegate:self];
}

#pragma mark - ATNativeADDelegate

- (void)didFinishLoadingADWithPlacementID:(NSString *)placementID {
    // 获取原生广告
    ATNativeADCache *nativeAd = [[ATAdManager sharedManager] getNativeADWithPlacementID:placementID];
    
    // 创建自定义视图并渲染
    UIView *adView = [self createNativeAdViewWithNativeAd:nativeAd];
    [self.view addSubview:adView];
}

@end
```

## 版本历史

### 2.8.3.0 (2026-03-11)
- 使用xcode(16.2)编译,提高兼容性

### 2.8.1.0 (2026-03-09)
- ✅ 支持 TopOn SDK 6.5.34+
- ✅ 修复原生广告 MediaView 类型转换问题
- ✅ 修复激励视频奖励回调逻辑
- ✅ 添加 ATSafeThreadArray 实现线程安全
- ✅ 优化初始化回调队列管理
- ✅ 完善所有广告格式的生命周期回调

### 2.8.0.0
- 初始版本
- 支持 Banner、Interstitial、Rewarded、Native、Splash 广告格式

## 注意事项

### 1. 线程安全
适配器使用 `ATSafeThreadArray_OP` 确保初始化回调的线程安全。

### 2. 回调顺序
严格遵循 TopOn 文档要求的回调顺序：
- 加载成功：`atOnAdLoadedExtra:`
- 展示：`atOnAdShow:` → 广告展示回调
- 关闭：`atOnAdClosed:`

### 3. 原生广告渲染
原生广告需要正确注册交互视图：
```objective-c
[nativeAd registerViewForInteractionWithRootView:rootView
                                 interactionViews:interactionViews
                                   viewController:viewController
                                   clickableViews:clickableViews
                                adChoicePosition:position];
```

### 4. 错误处理
所有错误都会通过 TopOn 的错误回调返回，包含详细的错误码和错误信息。


### 常见问题

**Q: 广告无法加载？**
A: 检查以下项：
1. TopOn 后台配置的服务器参数是否正确
2. Opera Ads SDK 是否成功初始化
3. 查看日志中的详细错误信息

**Q: 初始化失败？**
A: 确保在 TopOn 后台配置了正确的 `app_id` 和 `bundle_id`。

**Q: 原生广告点击无效？**
A: 检查是否正确调用了 `registerViewForInteraction` 方法。

## 示例项目

完整的示例项目请参考：
- [OpAdxSDK Demo - TopOn Adapter](https://github.com/operaads/iOS-sdk/tree/main/Demo/ToponAdapter)

## 技术支持

- 📧 Email: chenl@opera.com
- 📖 文档: [Opera Ads iOS SDK 文档]
- 🐛 问题反馈: [GitHub Issues](https://github.com/operaads/TPNiOSOperaSDKAdapter/issues)

## 许可证

本项目采用 MIT 许可证。详见 [LICENSE](LICENSE) 文件。

## 相关链接

- [Opera Ads SDK](https://github.com/operaads/iOS-sdk)
- [TopOn/AnyThink 文档](https://docs.toponad.com/)
- [CocoaPods](https://cocoapods.org/pods/TPNiOSOperaSDKAdapter)
