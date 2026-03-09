//
//  NSArray+KAKit.h
//  AnyThinkSDK
//
//  Created by Jason on 2020/10/15.
//  Copyright © 2020 AnyThink. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface NSArray (KAKit)

- (instancetype)optional;
- (NSString *)jsonString_anythink;
- (NSArray *)shuffledArray_anythink;
- (NSString *)jsonString_format_debug_anythink;


- (NSArray *)map:(id(^)(id))handle;
- (NSArray *)filter:(BOOL(^)(id))handle;
- (id)reduce:(id(^)(id, id))handle initial:(id)initial;

@end


