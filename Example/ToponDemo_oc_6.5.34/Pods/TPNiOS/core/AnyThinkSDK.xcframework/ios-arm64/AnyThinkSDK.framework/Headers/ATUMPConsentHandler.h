//
//  ATUMPConsentHandler.h
//  AnyThinkSDK
//
//  Created by Topon on 12/13/23.
//  Copyright © 2023 AnyThink. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

typedef void(^ConsentGatheringComplete)(NSError *_Nullable);

@interface ATUMPConsentHandler : NSObject

+ (BOOL)canRequestAds;
+ (BOOL)isPrivacyOptionsRequired;
+ (void)gatherConsentFromConsentPresentationViewController:(UIViewController *)viewController
                                  consentGatheringComplete:(void (^)(NSError *_Nullable))consentGatheringComplete;
+ (void)presentPrivacyOptionsFromViewController:(UIViewController *)viewController
                              completionHandler:(void (^)(NSError *_Nullable))completionHandler;

@end

NS_ASSUME_NONNULL_END
