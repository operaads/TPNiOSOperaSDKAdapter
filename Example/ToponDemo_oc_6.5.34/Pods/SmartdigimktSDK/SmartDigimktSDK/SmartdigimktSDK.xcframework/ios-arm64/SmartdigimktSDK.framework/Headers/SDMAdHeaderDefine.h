//
//  SDMAdHeaderDefine.h
//  Pods
//
//  Created by xuejingwei on 2025/8/12.
//

#ifndef SDMAdHeaderDefine_h
#define SDMAdHeaderDefine_h

typedef NS_ENUM(NSInteger, SDMBaseAdInitType) {
    SDMBaseAdInitTypeMyOffer = 1,
    SDMBaseAdInitTypeADX,
    SDMBaseAdInitTypeDirect,
};

typedef NS_ENUM(NSInteger, SDMAdFormat) {
    SDMAdFormatNative = 0,
    SDMAdFormatRewardedVideo = 1,
    SDMAdFormatBanner = 2,
    SDMAdFormatInterstitial = 3,
    SDMAdFormatSplash = 4,
};

typedef NS_ENUM(NSInteger, SDMNativeAdRenderType) {
    SDMNativeAdRenderSelfRender = 1,
    SDMNativeAdRenderExpress = 2,
};

#endif /* SDMAdHeaderDefine_h */
