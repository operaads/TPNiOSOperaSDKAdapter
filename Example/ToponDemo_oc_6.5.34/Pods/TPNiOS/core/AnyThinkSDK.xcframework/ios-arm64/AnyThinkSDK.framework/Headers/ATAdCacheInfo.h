//
//  ATAdvert.h
//  ToponSdkDemo
//
//  Created by li zhixuan on 2022/11/19.
//

#import <Foundation/Foundation.h>
#import <AnyThinkSDK/ATAd.h>


NS_ASSUME_NONNULL_BEGIN

typedef NS_ENUM(NSUInteger, ATAdvertCategoryType) {
    ATAdvertCategoryTypeNative = 0,
    ATAdvertCategoryTypeRewardedVideo,
    ATAdvertCategoryTypeBanner,
    ATAdvertCategoryTypeInterstitial,
    ATAdvertCategoryTypeSplash,
    ATAdvertCategoryTypeUnknow
};

@interface ATAdCacheInfo : NSObject<ATStorageEntityProtocol>

@property (nonatomic, copy, readonly) NSString *placementId;
@property (nonatomic, copy, readonly) NSString *unitId;
@property (nonatomic, copy, readonly) NSString *requestId;
@property (nonatomic, copy, readonly) id<ATAd> ad;

@property (nonatomic, assign, readonly) NSInteger showTimes;

/// ad source load interval time
@property (nonatomic, assign, readonly) BOOL upStatus;

/// showTimes <= 0,  is ready,  !expired upStatus,
@property (nonatomic, assign, readonly) BOOL isValid;
@property (nonatomic, assign, readonly) BOOL isValidWithoutUpstatus;

@property (atomic, assign) BOOL isValidStatus;

@property (nonatomic, assign) BOOL isMyoffer;
@property (nonatomic, assign) BOOL isAdxFallBack;

- (id)identifier;

- (instancetype)initWithAd:(id<ATAd>)ad;

@end

NS_ASSUME_NONNULL_END
