//
//  NSString+KAKit.h
//  Demo
//
//  Created by Martin Lau on 27/03/2018.
//  Copyright © 2018 Martin Lau. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

@interface NSString (KAKit)
- (NSString *)AT_base64EncodingUsingTable:(NSString *)table;
- (NSString *)AT_base64DecodingUsingTable:(NSString *)table;
//- (NSData *)AT_dataByBase64EncodingUsingTable:(NSString *)table;
//- (NSData *)AT_dataByBase64DecodingUsingTable:(NSString *)table;
- (NSString *)AT_md5;
//- (NSString *)AT_stringByAES256EncryptUsingKey:(NSString *)key;
//- (NSString *)AT_stringByAES256DecryptUsingKey:(NSString *)key;
+ (NSString *)AT_stringWithData:(NSData *)data usingEncoding:(NSStringEncoding)encoding;
- (NSString *)stringByBase64Encoding_anythink;
- (NSString *)stringByBase64Decoding_anythink;
- (NSString *)AT_stringUrlEncode;
//- (NSString *)AT_stringUrlDecode;
- (NSMutableAttributedString *)AT_underlineAttributedStringWithColor:(UIColor *)color font:(UIFont *)font;

- (instancetype)optional;
- (NSString *)AT_decimalString;
- (BOOL)AT_judgeIsNumberByRegularExpression;
- (NSString *)at_removeFloatAllZero;
// v5.7.56+
- (NSDictionary *)at_convertToDictionary;
- (NSArray *)at_convertToArray;
- (CGFloat)AT_calculateWidthWithHeight:(CGFloat)height
                                  font:(UIFont *)font;
//- (CGFloat)AT_calculateHeightWithWidth:(CGFloat)width
//                                  font:(UIFont *)font;

//+ (NSString *)AT_specially_url_encode:(NSString *)stringToEncode;

+ (NSString *)AT_specially_url_decode:(NSString *)stringToDecode;

@end
