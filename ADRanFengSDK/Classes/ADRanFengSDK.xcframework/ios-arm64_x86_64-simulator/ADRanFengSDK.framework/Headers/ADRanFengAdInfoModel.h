//
//  ADRanFengAdInfoModel.h
//  ADRanFengSDK
//
//  Created by 刘娟 on 2024/8/22.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface ADRanFengAdInfoModel : NSObject
/**
 创意ID
 */
@property (nonatomic, copy) NSString *creativeId;

/**
 广告ID
 */
@property (nonatomic, copy) NSString *adId;

/**
 请求ID
 */
@property (nonatomic, copy) NSString *requestId;
/**
 行业
 */
@property (nonatomic, copy) NSString *industry;

/**
 品牌
 */
@property (nonatomic, copy) NSString *brand;

/**
 标题
 */
@property (nonatomic, copy) NSString *title;

/**
 描述
 */
@property (nonatomic, copy) NSString *desc;

/**
 logo
 */
@property (nonatomic, copy) NSString *logoUrl;

/**
 图片
 */
@property (nonatomic, copy) NSString *imageUrl;

/**
 视频
 */
@property (nonatomic, copy) NSString *videoUrl;

/**
 落地页
 */
@property (nonatomic, copy) NSString *landingPageUrl;

/**
 下载链接
 */
@property (nonatomic, copy) NSString *downloadUrl;

/**
 应用名称
 */
@property (nonatomic, copy) NSString *appName;

/**
 广告主名称（开发者名称）
 */
@property (nonatomic, copy) NSString *advertiserName;

/**
 应用版本
 */
@property (nonatomic, copy) NSString *appVersion;

/**
 隐私协议地址
 */
@property (nonatomic, copy) NSString *privacyPolicyUrl;

/**
 隐私权限地址
 */
@property (nonatomic, copy) NSString *privacyAuthUrl;

/**
 应用功能介绍地址
 */
@property (nonatomic, copy) NSString *appIntroductionUrl;

/**
 图片宽度
 */
@property (nonatomic, assign) NSInteger imageWidth;

/**
 图片高度
 */
@property (nonatomic, assign) NSInteger imageHeight;

@end

NS_ASSUME_NONNULL_END
