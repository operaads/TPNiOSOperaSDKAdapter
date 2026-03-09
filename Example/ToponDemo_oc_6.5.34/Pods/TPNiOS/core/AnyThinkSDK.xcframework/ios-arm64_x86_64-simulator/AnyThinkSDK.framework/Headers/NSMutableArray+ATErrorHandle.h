
 
#import <Foundation/Foundation.h>
#import <AnyThinkSDK/NSArray+ATErrorHandle.h>

@interface NSMutableArray (ATErrorHandle)
/**
 数组中插入数据

 @param object 数据
 @param index 下标
 */
- (void)AT_insertObjectVerify:(id)object atIndex:(NSInteger)index;
/**
 数组中添加数据

 @param object 数据
 */
- (void)AT_addObjectVerify:(id)object;

- (void)AT_addObjectFromArray:(NSArray *)array;

- (NSMutableArray *)AT_arrayBySubstractingObjectsFromArray:(NSArray *)objectsToSub;

@end
