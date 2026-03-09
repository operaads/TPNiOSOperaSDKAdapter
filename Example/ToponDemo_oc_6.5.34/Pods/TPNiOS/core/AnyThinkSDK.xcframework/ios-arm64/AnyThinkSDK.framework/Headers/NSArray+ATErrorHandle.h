
#import <Foundation/Foundation.h>

@interface NSArray (ATErrorHandle)

/**
 为数组分类添加的方法  可以在应用中直接调用 可以防止数组越界导致的crash

 @param index 传入的取值下标
 @return id类型的数据
 */
- (id)AT_objectAtIndexVerify:(NSUInteger)index;
- (id)AT_objectAtIndexedSubscriptVerify:(NSUInteger)idx;

+ (instancetype)AT_initWithArray:(NSArray *)array;

@end
