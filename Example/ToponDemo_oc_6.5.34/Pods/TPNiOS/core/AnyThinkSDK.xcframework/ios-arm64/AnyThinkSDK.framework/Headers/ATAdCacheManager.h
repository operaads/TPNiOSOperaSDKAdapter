//
//  ATAdCacheManager.h
//  AnyThinkSDK
//
//  Created by li zhixuan on 2022/12/15.
//  Copyright © 2022 AnyThink. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <AnyThinkSDK/ATAdManager+Internal.h>
#import <AnyThinkSDK/ATAdCacheInfo.h>

NS_ASSUME_NONNULL_BEGIN

@interface ATAdCacheManager : NSObject

+ (ATAdCacheManager *)shareInstance;


/// read cache, will filter Caps Pacing, expired and ready, only return showTimes <= 0, if no offer, check myoffer self fill
/// @param placementId placementId
/// @param type type 
- (NSArray<ATAdCacheInfo *> *)adAndMyOfferCacheInfosWithPlacementId:(NSString *)placementId actionType:(ATAdManagerReadyAPICaller)type;

/// default method to find cache, find ad cache, if none, find myoffer cache
/// @param placementId placement id
- (NSArray<id<ATAd>> *)adAndMyOfferAdCacheWithPlacementId:(NSString *)placementId actionType:(ATAdManagerReadyAPICaller)type;
- (BOOL)adAndMyOfferIsReadyWithPlacementId:(NSString *)placementId;

/// save adatper load succeed data(offer), call it ATAd, such as ATBanner...
/// @param ad ad
- (void)saveWithAd:(id<ATAd>)ad;

- (void)removeAllCacheWithPlacementId:(NSString *)placementId unitId:(nullable NSString *)unitId requestId:(nullable NSString *)requestId index:(NSInteger)index queue:(nullable dispatch_queue_t)queue;
- (void)removeAllCacheWithPlacementId:(NSString *)placementId unitId:(NSString *)unitId;
- (void)removeAllCacheWithPlacementId:(NSString *)placementId unitId:(nullable NSString *)unitId requestId:(nullable NSString *)requestId;
- (void)removeAllCacheWithPlacementId:(NSString *)placementId index:(NSInteger)index;
- (void)removeAllCacheWithPlacementId:(NSString *)placementId;
- (void)removeAllCacheWithAd:(id<ATAd>)ad;
- (void)removeAllCache;

/// can show(use) cache
/// @param placementId placement Id
/// @param unitId unit Id 
- (id<ATAd>)anyOneValidAdCacheWithPlacementId:(NSString *)placementId unitId:(nullable NSString *)unitId;
- (NSArray<ATAdCacheInfo *> *)validAdCacheWithPlacementId:(NSString *)placementId unitId:(nullable NSString *)unitId;
- (NSArray<ATAdCacheInfo *> *)validAdCacheWithPlacementId:(NSString *)placementId requestId:(nullable NSString *)requestId;
- (NSArray<ATAdCacheInfo *> *)validAdCacheWithPlacementId:(NSString *)placementId unitId:(nullable NSString *)unitId requestId:(nullable NSString *)requestId;
- (NSArray<id<ATAd>> *)validAdCacheWithPlacementId:(NSString *)placementId;
- (id<ATAd>)validHighestAdCacheWithPlacementId:(NSString *)placementId;

- (NSArray<ATAdCacheInfo *> *)allAdCacheWithPlacementId:(NSString *)placementId unitId:(nullable NSString *)unitId;
/// get highest price priority , in cache
/// @param placementId placementId
/// @param unitId unitId
- (NSInteger)highestPriorityOfhasBeenShownAllCacheWithPlacementId:(NSString*)placementId unitId:(NSString*)unitId;

- (BOOL)hasBeenShownAllCacheWithPlacementId:(NSString *)placementId unitId:(NSString *)unitId;

/// send loss for ad.expired and !.ad.ready cache
/// @param placementId placementId 
- (void)sendLossForExpiredAdWithPlacementId:(NSString *)placementId requestId:(NSString *)requestId;
- (void)sendLossForExpiredAdWithPlacementId:(NSString *)placementId unitId:(NSString *)unitId requestId:(NSString *)requestId preloadModel:(nullable ATMgPreloadModel *)preloadModel;

- (BOOL)checkCanStartAdSourceRequestWithPlacementId:(NSString *)placementId loadingUG:(ATUnitGroupModel *)loadingUG requestId:(NSString *)requestId;

- (NSArray<NSDictionary *> *)infoWithCacheInfoes:(NSArray<ATAdCacheInfo *> *)cacheInfoes;

- (NSArray<ATAdCacheInfo *> *)filterOneUnitGroupOneRquestIdWithAdCacheInfoes:(NSArray<ATAdCacheInfo *> *)offers;

- (ATAdCacheInfo *)preWinnerInfoWithRequestId:(NSString *)requestId placementId:(NSString *)placementId;

#pragma mark - share placement
/// only check sharePlacement
/// @param placementId placementId
- (BOOL)sharePlacementIsReadyWithPlacementId:(NSString *)placementId;

/// check whether share placement Id, if yes, block it
/// @param placementId placementId
- (BOOL)verifyIsSharePlacementId:(NSString *)placementId;

/// only get share placement cache
/// @param placementId placementId
/// @param type type 
- (NSArray<ATAdCacheInfo *> *)sharePlacementOfferCacheInfosWithPlacementId:(NSString *)placementId actionType:(ATAdManagerReadyAPICaller)type;

- (void)exchangePreWinnerInfoToCurWinnerCacheInfoWithPlacementId:(NSString *)placementId;

- (NSDictionary *)extraInfoWithAdxOfferCached:(ATAdCacheInfo *)cache placementID:(NSString *)placementID cacheInfoes:(NSArray<ATAdCacheInfo *> *)cacheInfoes;
@end

NS_ASSUME_NONNULL_END
