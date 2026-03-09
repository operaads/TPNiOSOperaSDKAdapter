//
//  ATTimer.h
//  ATSDK
//
//  Created by 陈俊杰 on 2017/6/6.
//  Copyright © 2017年 AnyThink. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface ATTimer : NSObject

@property (nonatomic, copy) NSString *runLoopMode;

+ (ATTimer *)timerWithTimeInterval:(NSTimeInterval)seconds
                            target:(id)target
                          selector:(SEL)aSelector
                           repeats:(BOOL)repeats;

+ (ATTimer *)timerWithTimeInterval:(NSTimeInterval)seconds
                            target:(id)target
                          selector:(SEL)aSelector
                          userInfo:(nullable id)userInfo
                           repeats:(BOOL)repeats;

- (BOOL)isValid;

// 中断定时器
- (void)invalidate;
// 是否已启动定时器
- (BOOL)isScheduled;
// 启动定时器
- (BOOL)scheduleNow;
- (BOOL)pause;
- (BOOL)resume;

/// 从暂停时间开始计算
- (BOOL)newResume;
- (NSTimeInterval)initialTimeInterval;

@end
