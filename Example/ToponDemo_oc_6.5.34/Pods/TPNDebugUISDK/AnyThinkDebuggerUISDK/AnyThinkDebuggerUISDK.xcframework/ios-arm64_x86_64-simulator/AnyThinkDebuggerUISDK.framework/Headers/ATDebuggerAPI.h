//
//  ATDebuggerAPI.h
//  DebuggerUISDK
//
//  Created by GUO PENG on 2023/8/8.
//  Copyright © 2023 AnyThink. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>


typedef NS_ENUM(NSInteger,ATShowDebugUIType) {
    ATShowDebugUIPush = 0,
    ATShowDebugUIPresent = 1
};

NS_ASSUME_NONNULL_BEGIN

@interface ATDebuggerAPI : NSObject

@property (nonatomic, strong,readonly) NSString *debugkey;

+ (instancetype)sharedInstance;

// 提供push(需要有navi导航栏层级的VC)或者present两种展示方式
- (void)showDebuggerInViewController:(UIViewController *)viewController showType:(ATShowDebugUIType)type debugkey:(NSString *)debugkey;

+ (NSString *)versionString;

@end

NS_ASSUME_NONNULL_END
