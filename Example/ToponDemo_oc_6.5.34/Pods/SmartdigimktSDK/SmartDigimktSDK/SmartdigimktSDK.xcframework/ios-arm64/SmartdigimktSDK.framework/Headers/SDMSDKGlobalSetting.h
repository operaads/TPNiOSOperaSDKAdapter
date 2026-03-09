//
//  SDMSDKGlobalSetting.h
//  SmartdigimktSDK
//
//  Created by Smartdigimkt on 8/23/23.
//  Copyright © 2023 Smartdigimkt. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#import <SmartdigimktSDK/SDMAdHeaderDefine.h>
#import <SmartdigimktSDK/SDMDebuggerConfig.h>

NS_ASSUME_NONNULL_BEGIN
@class SDMAntiBrushConfig, SDMRiskControlModel, SDMAdCustomFilter;
extern NSString *const kSDMDeviceDataInfoOSVersionNameKey; //System version name
extern NSString *const kSDMDeviceDataInfoOSVersionCodeKey; //System version code
extern NSString *const kSDMDeviceDataInfoPackageNameKey; //Application package name
extern NSString *const kSDMDeviceDataInfoAppVersionNameKey; //Application version name
extern NSString *const kSDMDeviceDataInfoAppVersionCodeKey; //Application version code
extern NSString *const kSDMDeviceDataInfoBrandKey; //Phone brands
extern NSString *const kSDMDeviceDataInfoCPUKey; //Phone cpu
extern NSString *const kSDMDeviceDataInfoModelKey; //Phone model
extern NSString *const kSDMDeviceDataInfoScreenKey; //Screen Resolution
extern NSString *const kSDMDeviceDataInfoNetworkTypeKey; //Network Type
extern NSString *const kSDMDeviceDataInfoMNCKey; //Mobile Network Code
extern NSString *const kSDMDeviceDataInfoMCCKey; //Mobile Country Code
extern NSString *const kSDMDeviceDataInfoLanguageKey; //Language
extern NSString *const kSDMDeviceDataInfoTimeZoneKey; //Time zone
extern NSString *const kSDMDeviceDataInfoUserAgentKey; //User Agent
extern NSString *const kSDMDeviceDataInfoOrientKey; //Screen orientation
extern NSString *const kSDMDeviceDataInfoIDFAKey; //idfa
extern NSString *const kSDMDeviceDataInfoIDFVKey; //idfv
extern NSString *const kSDMDeviceDataInfoSIMCardStateKey; //sim card status
extern NSString *const kSDMDeviceDataInfoBatteryKey; //sim card status
extern NSString *const kSDMDeviceDataInfoSensorDeny;

typedef NS_ENUM(NSUInteger, SDMSplashAdClickResultType) {
    SDMSplashAdClickResultTypeDidCloseAd         = 1,  // After clicking on the jump button, close the splash ad
    SDMSplashAdClickResultTypePauseCountdown     = 2,  // Pause the countdown after clicking the jump button, and continue the countdown when the splash ad is visible
};

/// Debug values for testing geography.
typedef NS_ENUM(NSInteger, SDMUMPDebugGeography) {
    SDMUMPDebugGeographyDisabled = 0,  ///< Disable geography debugging.
    SDMUMPDebugGeographyEEA = 1,       ///< Geography appears as in EEA for debug devices.
    SDMUMPDebugGeographyNotEEA = 2,    ///< Geography appears as not in EEA for debug devices.
};

typedef NS_ENUM(NSInteger, SDMSystemPlatformType) {
    SDMSystemPlatformTypeUnknown = 0,
    SDMSystemPlatformTypeIOS = 1,
    SDMSystemPlatformTypeUnity = 2,
    SDMSystemPlatformTypeCocos2dx = 3,
    SDMSystemPlatformTypeCocosCreator = 4,
    SDMSystemPlatformTypeReactNative = 5,
    SDMSystemPlatformTypeFlutter = 6,
    SDMSystemPlatformTypeAdobeAir = 7
};

@interface SDMSDKGlobalSetting : NSObject

+ (instancetype)sharedManager;

@property (nonatomic, strong) NSDictionary *customData;
/// Splash Shake Text String, Only for DirectlyAd
@property (nonatomic, strong) NSString *directlySplashAdShakeTextString;
/// Splash CTA Button BackgroundColor, Only for DirectlyAd
@property (nonatomic, strong) UIColor *directlySplashAdCTAButtonBackgroundColor;
/// Splash Shake Custom View, Only for DirectlyAd
@property (nonatomic, strong) UIView *directlySplashAdCustomShakeView;
/// Splash CTA Custom View, Only for DirectlyAd
@property (nonatomic, strong) UIView *directlySplashAdCustomCTAView;
/// Splash Video Mute Icon hidden, Not hidden by default,  Only for DirectlyAd
@property (nonatomic, assign) BOOL directlySplashAdVideoMuteIconHidden;
/// Whether to pause the countdown after clicking on the  Splash ad to jump, the default is NO, Only for smartdigimkt ADX、DirectlyAd and Cross Promotion
@property (nonatomic, assign) SDMSplashAdClickResultType splashAdClickResultType;

// ump test ids
@property (nonatomic, nullable,strong) NSArray<NSString *> *umpTestDeviceIdentifiers;
/// Debug geography.
@property (nonatomic, assign) SDMUMPDebugGeography umpGeography;
/// set header bidding test mode,only support incoming device idfa.
/// setLogEnabled must be turned on before use
@property (nonatomic, strong) NSString *headerBiddingTestModeDeviceID;
/// system platform Information
@property (nonatomic, assign) SDMSystemPlatformType systemPlatformType;
/// set whether WX is installed
@property (nonatomic, assign) BOOL isInstallWX;
/// for setLocationLongitude:dimension:
@property (nonatomic, readonly) NSDictionary *locationDictionary;

///// shake sensor type
//@property (nonatomic, assign, readonly) SDMNetworkSensorType networkSensorType;

/// set custom data for the ad placement
/// @param customData - custom data
/// @param placementID - placement id
- (void)setCustomData:(NSDictionary *)customData forPlacementID:(NSString *)placementID;

/// get custom data
- (NSDictionary *)customDataForPlacementID:(NSString *)placementID;

/// set Wechat appID and universalLink, for register WechatOpenSDK
/// @param appID - Wechat appID
/// @param universalLink - Wechat universalLink
- (void)setWeChatAppID:(NSString *)appID universalLink:(NSString *)universalLink;

/// set exlude appleid list for sdk to filter offers
- (void)setExludeAppleIdArray:(NSArray *)appleIdArray;

/// get exlude appleid list
- (NSArray *)exludeAppleIdArray;

/// set denied Upload Info list for sdk to Control report
- (void)setDeniedUploadInfoArray:(NSArray *)uploadInfoArray;

/// get denied Upload Info list
- (NSArray *)deniedUploadInfoArray;

/// Determine whether the Denied key is included
/// @param key - key string
- (BOOL)isContainsForDeniedUploadInfoArray:(NSString *)key;

/// 是否允许异常信息收集
/// - Parameter isPermit: default YES
- (void)setAbnormalCollect:(BOOL)isPermit;

#pragma mark - Sensor
- (BOOL)isDenySensor;
- (BOOL)isDenySensorWithExtra:(NSDictionary *)extra;
- (void)setDenySensor:(BOOL)isShakeEnabled;
- (void)setDenySensor:(BOOL)isShakeEnabled extra:(NSDictionary *)extra;

#pragma mark - DeviceInfo
/// set location longitude
- (void)setLocationLongitude:(double)longitude dimension:(double)dimension;
- (void)setDebuggerConfig:(void(^_Nullable)(SDMDebuggerConfig * _Nullable debuggerConfig))debuggerConfigBlock;

@end

NS_ASSUME_NONNULL_END
