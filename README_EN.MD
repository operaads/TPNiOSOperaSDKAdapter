# TPNiOSOperaSDKAdapter

Custom adapter for integrating Opera Ads SDK with TopOn/AnyThink mediation platform.

[![CocoaPods Compatible](https://img.shields.io/cocoapods/v/TPNiOSOperaSDKAdapter.svg)](https://cocoapods.org/pods/TPNiOSOperaSDKAdapter)
[![Platform](https://img.shields.io/cocoapods/p/TPNiOSOperaSDKAdapter.svg?style=flat)](https://cocoapods.org/pods/TPNiOSOperaSDKAdapter)
[![License](https://img.shields.io/cocoapods/l/TPNiOSOperaSDKAdapter.svg?style=flat)](https://github.com/operaads/TPNiOSOperaSDKAdapter/blob/main/LICENSE)

English | [简体中文](README.MD)

## Overview

TPNiOSOperaSDKAdapter is a custom mediation adapter that enables seamless integration of Opera Advertising SDK (OpAdxSdk) with the TopOn (AnyThink) mediation platform. This adapter bridges Opera Ads SDK callbacks to TopOn mediation callbacks, enabling ad serving through the TopOn platform.

## Supported Ad Formats

- ✅ Banner Ads (Standard, MREC)
- ✅ Interstitial Ads
- ✅ Rewarded Video Ads
- ✅ Native Ads
- ✅ Splash/App Open Ads

## Requirements

- iOS 13.0+
- TopOn SDK 6.5.34+
- OpAdxSdk 2.8.3
- Xcode 13.0+

## Installation

### CocoaPods

Add the following to your `Podfile`:

```ruby
# TopOn SDK
pod 'TPNiOS', '~> 6.5.34'

# Opera Ads SDK
pod 'OpAdxSdk', '2.8.3'

# Opera Ads TopOn Adapter
pod 'TPNiOSOperaSDKAdapter', '2.8.3.0'
```

Then run:

```bash
pod install
```

## Quick Start

### 1. Initialize TopOn SDK

```objective-c
#import <AnyThinkSDK/AnyThinkSDK.h>

// Initialize in AppDelegate
- (BOOL)application:(UIApplication *)application 
    didFinishLaunchingWithOptions:(NSDictionary *)launchOptions {
    
    // Configure TopOn
    [[ATAPI sharedInstance] setAppID:@"your_topon_app_id" 
                              appKey:@"your_topon_app_key"];
    
    // Add Opera Ads as custom ad network
    // TopOn will automatically detect and use OpAdxToponInitAdapter
    
    return YES;
}
```

### 2. Configure Ad Placements

When configuring ad placements in TopOn dashboard:

1. Select "Custom Ad Network"
2. Fill in server parameters (JSON format):

```json
{
  "app_id": "your_opera_app_id",
  "bundle_id": "your_bundle_id",
  "slot_id": "your_opera_placement_id"
}
```

### 3. Load and Show Ads

Use TopOn's standard APIs to load and show ads:

#### Banner Ads

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
    NSLog(@"Banner loaded successfully");
    [self.view addSubview:bannerView];
}

- (void)didFailToLoadADWithBannerView:(ATBannerView *)bannerView error:(NSError *)error {
    NSLog(@"Banner failed to load: %@", error);
}

@end
```

#### Interstitial Ads

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
    NSLog(@"Interstitial loaded successfully");
}

- (void)didFailToLoadADWithPlacementID:(NSString *)placementID error:(NSError *)error {
    NSLog(@"Interstitial failed to load: %@", error);
}

- (void)didShowInterstitialWithPlacementID:(NSString *)placementID {
    NSLog(@"Interstitial displayed");
}

@end
```

#### Rewarded Video Ads

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
    NSLog(@"Rewarded video loaded successfully");
}

- (void)didRewardSuccessForPlacemenID:(NSString *)placementID extra:(NSDictionary *)extra {
    NSLog(@"User earned reward");
}

@end
```

#### Native Ads

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
    // Get native ad
    ATNativeADCache *nativeAd = [[ATAdManager sharedManager] getNativeADWithPlacementID:placementID];
    
    // Create custom view and render
    UIView *adView = [self createNativeAdViewWithNativeAd:nativeAd];
    [self.view addSubview:adView];
}

@end
```

## Version History

### 2.8.3.0 (2026-03-11)
- Built with Xcode 16.2 for improved compatibility

### 2.8.1.0 (2026-03-09)
- ✅ Support for TopOn SDK 6.5.34+
- ✅ Fixed native ad MediaView type conversion issue
- ✅ Fixed rewarded video reward callback logic
- ✅ Added ATSafeThreadArray for thread safety
- ✅ Optimized initialization callback queue management
- ✅ Improved lifecycle callbacks for all ad formats

### 2.8.0.0
- Initial release
- Support for Banner, Interstitial, Rewarded, Native, and Splash ad formats

## Important Notes

### 1. Thread Safety
The adapter uses `ATSafeThreadArray_OP` to ensure thread-safe initialization callbacks.

### 2. Callback Order
Strictly follows TopOn documentation requirements for callback order:
- Load success: `atOnAdLoadedExtra:`
- Display: `atOnAdShow:` → ad display callbacks
- Close: `atOnAdClosed:`

### 3. Native Ad Rendering
Native ads require proper interaction view registration:
```objective-c
[nativeAd registerViewForInteractionWithRootView:rootView
                                 interactionViews:interactionViews
                                   viewController:viewController
                                   clickableViews:clickableViews
                                adChoicePosition:position];
```

### 4. Error Handling
All errors are returned through TopOn's error callbacks with detailed error codes and messages.


### Common Issues

**Q: Ads not loading?**
A: Check the following:
1. Verify server parameters in TopOn dashboard are correct
2. Ensure Opera Ads SDK is successfully initialized
3. Review detailed error messages in logs

**Q: Initialization failed?**
A: Make sure correct `app_id` and `bundle_id` are configured in TopOn dashboard.

**Q: Native ad clicks not working?**
A: Verify that `registerViewForInteraction` method is called correctly.

## Sample Project

For complete sample projects, see:
- [OpAdxSDK Demo - TopOn Adapter](https://github.com/operaads/iOS-sdk/tree/main/Demo/ToponAdapter)

## Support

- 📧 Email: chenl@opera.com
- 📖 Documentation: [Opera Ads iOS SDK Documentation]
- 🐛 Issue Tracker: [GitHub Issues](https://github.com/operaads/TPNiOSOperaSDKAdapter/issues)

## License

This project is licensed under the MIT License. See the [LICENSE](LICENSE) file for details.

## Related Links

- [Opera Ads SDK](https://github.com/operaads/iOS-sdk)
- [TopOn/AnyThink Documentation](https://docs.toponad.com/)
- [CocoaPods](https://cocoapods.org/pods/TPNiOSOperaSDKAdapter)
