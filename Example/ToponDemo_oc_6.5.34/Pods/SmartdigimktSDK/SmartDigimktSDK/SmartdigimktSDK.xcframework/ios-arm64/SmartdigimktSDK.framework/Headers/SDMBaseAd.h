//
//  SDMBaseAd.h
//  SmartdigimktSDK
//
//  Created by xuejingwei on 2025/8/5.
//

#import <Foundation/Foundation.h>
#import <SmartdigimktSDK/SDMPublicLoadingDelegate.h>
#import <SmartdigimktSDK/SDMAdHeaderDefine.h>
#import <SmartdigimktSDK/SDMAdRequest.h>
#import <SmartdigimktSDK/SDMAd.h>
#import <SmartdigimktSDK/SDMWinInfo.h>
#import <SmartdigimktSDK/SDMLossInfo.h>

NS_ASSUME_NONNULL_BEGIN

@class UIViewController;

@interface SDMBaseAd : NSObject

@property (nonatomic, copy) NSString *placementId;
@property (nonatomic, strong) NSDictionary *extra;
@property (nonatomic, weak, nullable) id<SDMPublicLoadingDelegate> loadDelegate;
@property (nonatomic, weak) UIViewController *showViewController;
@property (nonatomic, strong) NSDictionary *adSourceExtra;

@property (nonatomic, strong) SDMAdRequest *adRequest;

/// generate params for adx
+ (void)generateHBParamWithExtraDic:(nullable NSDictionary *)extraDic
                             format:(SDMAdFormat)format
                           complete:(nonnull void(^)(NSDictionary *headerBiddingParams))complete;

+ (void)forceCloseAdIfNeeded;

- (instancetype)initAdWithPlacementId:(nonnull NSString *)placementId;

- (instancetype)initAdWithPlacementId:(nonnull NSString *)placementId extra:(nullable NSDictionary *)extra;

- (void)load;

- (void)loadAdWithExtraDic:(nonnull NSDictionary *)ExtraDic;

/// check ads is ready
- (BOOL)isReady;
/// send win
- (void)notifyWin:(SDMWinInfo *)winInfo;
/// send loss
- (void)notifyLoss:(SDMLossInfo *)lossInfo;
/// destroy show info
- (void)destroy;
/// ads expired time
- (nullable NSDate *)getExpirationTimestamp;

- (nullable SDMAd *)getSDMAd;

- (BOOL)readyFilledWithExtraDic:(NSDictionary *)extraDic;

@end

NS_ASSUME_NONNULL_END
