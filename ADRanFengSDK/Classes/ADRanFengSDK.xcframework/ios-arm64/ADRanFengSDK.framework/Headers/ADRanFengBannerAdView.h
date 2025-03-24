//
//  ADRanFengBannderAdView.h
//  ADRanFengSDK
//
//  Created by 陈则富 on 2021/9/26.
//

#import <UIKit/UIKit.h>
#import <ADRanFengSDK/ADRanFengCommonDefine.h>
#import "ADRanFengAdInfoModel.h"
NS_ASSUME_NONNULL_BEGIN
@class ADRanFengBannerAdView;

@protocol ADRanFengBannerAdViewDelegate <NSObject>

@optional
/**
 *  请求成功
 */
- (void)ranfengBannerSuccessLoad:(ADRanFengBannerAdView *)ranfengBannerView;

/**
 *  请求失败
 */
- (void)ranfengBannerViewFailedToLoadWithError:(NSError *)error;
/**
 *  展示回调
 */
- (void)ranfengBannerViewDidPresent:(ADRanFengBannerAdView *)ranfengBannerView;
/**
 *  曝光回调
 */
- (void)ranfengBannerViewWillExpose:(ADRanFengBannerAdView *)ranfengBannerView;

/**
 *  点击回调
 */
- (void)ranfengBannerViewClicked:(ADRanFengBannerAdView *)ranfengBannerView;

/**
 *  被用户关闭时调用
 */
- (void)ranfengBannerViewWillClose:(ADRanFengBannerAdView *)ranfengBannerView;

/**
 *  被用户关闭广告落地页调用
 */
- (void)ranfengBannerViewCloseLandingPage:(ADRanFengBannerAdView *)ranfengBannerView;


@end

@interface ADRanFengBannerAdView : UIView

/**
 *  委托 
 */
@property (nonatomic ,weak) id<ADRanFengBannerAdViewDelegate>  delegate;

/*
 详解：当前ViewController[必传]
 */
@property (nonatomic ,weak) UIViewController  *viewController;

/**
 *  构造方法
 *  详解：frame - banner 展示的位置和大小
 *       postId - 广告位 ID
 */
- (instancetype)initWithFrame:(CGRect)frame posId:(NSString *)posId;

/*
 获取广告相关信息，请一定在广告加载成功后获取
 */
- (ADRanFengAdInfoModel *)getInfoData;

/**
 *  开始请求广告
 */
- (void)loadRequest;

/**
 广告是否超时
 */
- (bool)isDataTimeout;

- (void)timerInvalidate;

/**
 返回广告的eCPM，单位：分
 
 @return 成功返回一个大于等于0的值，小于等于0表示广告请求失败或获取eCPM时机不正确(请于请求广告成功后获取)
*/
- (NSInteger)bidPrice;

/**
 返回广告的底价，单位：分
 
 @return 成功返回一个大于等于0的值，小于等于0表示广告请求失败或获取底价时机不正确(请于请求广告成功后获取)
*/
- (NSInteger)bidFloor;

/**
 *  竞赢上报，竞价广告位必须在展示前上报
 *  @param price 回传广告返回的出价，bidPrice(ecpm)，单位: 分
 */
- (void)sendWinNotificationWithPrice:(NSInteger)price;

/**
 *  竞败之后调用,
 *  @param reason 竞价失败原因
 *  @param winnerPirce 竟赢者价格，单位：分
 */
- (void)sendWinFailNotificationReason:(ADRanFengBiddingLossReason)reason winnerPirce:(NSInteger)winnerPirce;

@end

NS_ASSUME_NONNULL_END
