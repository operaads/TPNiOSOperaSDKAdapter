//
//  ATDAParameter.h
//  AnyThinkSDK
//
//  Created by GUO PENG on 2024/3/8.
//  Copyright © 2024 AnyThink. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <AnyThinkSDK/ATUnitGroupModel.h>
#import <AnyThinkSDK/ATPlacementModel.h>

NS_ASSUME_NONNULL_BEGIN

@interface ATDAParameter : NSObject

+ (ATDAParameter *(^)(NSString *))daKey;

- (ATDAParameter *(^)(ATPlacementModel *))placementModel;
- (ATDAParameter *(^)(ATUnitGroupModel *))unitGroupModel;
- (ATDAParameter *(^)(NSInteger))format;
- (ATDAParameter *(^)(NSString *))requsetId;
- (ATDAParameter *(^)(NSString *))placementID;
/// extraDic 信息优先级最高
- (ATDAParameter *(^)(NSDictionary *))extraDic;

- (ATDAParameter *(^)(id))msg;
- (ATDAParameter *(^)(id))msg1;
- (ATDAParameter *(^)(id))msg2;
- (ATDAParameter *(^)(id))msg3;
- (ATDAParameter *(^)(id))msg4;
- (ATDAParameter *(^)(id))msg5;
- (ATDAParameter *(^)(id))msg6;
- (ATDAParameter *(^)(id))msg7;
- (ATDAParameter *(^)(id))msg8;
- (ATDAParameter *(^)(id))msg9;
- (ATDAParameter *(^)(id))msg10;
- (ATDAParameter *(^)(id))msg11;
- (ATDAParameter *(^)(id))msg12;
- (ATDAParameter *(^)(id))msg13;
- (ATDAParameter *(^)(id))msg14;
- (ATDAParameter *(^)(id))msg15;
- (ATDAParameter *(^)(id))msg16;
- (ATDAParameter *(^)(id))msg17;
- (ATDAParameter *(^)(id))msg18;
- (ATDAParameter *(^)(id))msg19;
- (ATDAParameter *(^)(id))msg20;
- (ATDAParameter *(^)(id))msg21;
- (ATDAParameter *(^)(id))msg22;
- (ATDAParameter *(^)(id))msg23;
- (ATDAParameter *(^)(id))msg24;
- (ATDAParameter *(^)(id))msg25;
- (ATDAParameter *(^)(id))msg26;
- (ATDAParameter *(^)(id))msg27;
- (ATDAParameter *(^)(id))msg28;
- (ATDAParameter *(^)(id))msg29;
- (ATDAParameter *(^)(id))msg30;


@property (atomic, strong) NSString *at_daKeyString;
@property (atomic, strong) ATUnitGroupModel *at_unitGroupModel;
@property (nonatomic, assign) NSInteger at_format;
@property (nonatomic, copy) NSString *at_placementID;
//Adapter不设置 ATPlacementModel 设置 format 和 placementID
@property (nonatomic, strong) ATPlacementModel *at_placementModel;
@property (nonatomic, strong) NSString *at_requsetIdString;

- (NSDictionary *)getDASendParameterDic;

@end

NS_ASSUME_NONNULL_END
