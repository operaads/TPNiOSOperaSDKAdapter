//
//  ATAdLogger.h
//  AnyThinkSDK
//
//  Created by Martin Lau on 28/04/2018.
//  Copyright © 2018 Martin Lau. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <AnyThinkSDK/ATAPI.h>

#define ATADPublicLogKEY @"publicLog"
#define AT_AnyThinkAdTrack @"AnyThinkAdTrack"
#define ATNETLog(format, ...) printf("%s\n\n",[[NSString stringWithFormat:(format), ##__VA_ARGS__] UTF8String])

@interface ATAdLogger : NSObject
NS_ASSUME_NONNULL_BEGIN

@property (atomic) BOOL logEnabled;
@property (atomic) BOOL logCacheEnabled;
@property (atomic) BOOL adxLoadToastForbid;

+ (instancetype)sharedManager;

+ (BOOL)shouldLogType:(ATLogType)type;
+ (void)logMessage:(NSString *)message type:(ATLogType)type;
+ (void)logWarning:(NSString *)warning type:(ATLogType)type;
+ (void)logError:(NSString *)error type:(ATLogType)type;
+ (void)logNetworkString:(NSString *)networkString typeString:(NSString *)typeString;
+ (void)logDeviceInfo;

/// for External message
/// @param message pStr
/// @param prefixStr prefix string
+ (void)showExternalLogMessage:(nullable NSString *)message
                     prefixStr:(nullable NSString *)prefixStr;

/// for External warning
/// @param warning pStr
/// @param prefixStr prefix string
+ (void)showExternalLogWarning:(nullable NSString *)warning
                     prefixStr:(nullable NSString *)prefixStr;
NS_ASSUME_NONNULL_END
@end
