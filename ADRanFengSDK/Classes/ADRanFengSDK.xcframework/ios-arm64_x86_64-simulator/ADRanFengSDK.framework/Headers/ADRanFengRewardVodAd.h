//
//  ADRanFengRewardVodAd.h
//  ADRanFengSDK
//
//  Created by Jiangyou on 2021/12/9.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#import <ADRanFengSDK/ADRanFengCommonDefine.h>
#import "ADRanFengAdInfoModel.h"

NS_ASSUME_NONNULL_BEGIN

@class ADRanFengRewardVodAd;

@protocol ADRanFengRewardVodAdDelegate <NSObject>

@optional
/**
 *  激励视频广告数据请求成功
 */
- (void)ranfengRewardVodAdSuccessToLoadAd:(ADRanFengRewardVodAd *)rewardVodAd;

/**
 *  激励视频广告数据请求失败
 */
- (void)ranfengRewardVodAdFailToLoadAd:(ADRanFengRewardVodAd *)rewardVodAd error:(NSError *)error;

/**
 *  激励视频广告视频缓存成功
 */
- (void)ranfengRewardVodAdVideoCacheFinish:(ADRanFengRewardVodAd *)rewardVodAd;

/**
 *  激励视频广告渲染成功
 *  建议在此回调后展示广告
 */
- (void)ranfengRewardVodAdVideoReadyToPlay:(ADRanFengRewardVodAd *)rewardVodAd;

/**
 *  激励视频广告播放失败
 *  
 */
- (void)ranfengRewardVodAdVideoPlayFail:(ADRanFengRewardVodAd *)rewardVodAd error:(NSError *)error;

/**
 *  激励视频视图展示成功回调
 *  激励视频展示成功回调该函数
 */
- (void)ranfengRewardVodAdDidPresentScreen:(ADRanFengRewardVodAd *)rewardVodAd;

/**
 *  激励视频广告视图展示失败回调
 *  激励视频广告展示失败回调该函数
 */
- (void)ranfengRewardVodAdFailToPresent:(ADRanFengRewardVodAd *)rewardVodAd error:(NSError *)error;

/**
 *  激励视频广告曝光回调
 */
- (void)ranfengRewardVodAdWillExposure:(ADRanFengRewardVodAd *)rewardVodAd;

/**
 *  激励视频广告点击回调
 */
- (void)ranfengRewardVodAdClicked:(ADRanFengRewardVodAd *)rewardVodAd;

/**
 *  激励视频广告页关闭
 */
- (void)ranfengRewardVodAdAdDidDismissClose:(ADRanFengRewardVodAd *)rewardVodAd;

/**
 *  激励视频广告达到激励条件
 */
- (void)ranfengRewardVodAdAdDidEffective:(ADRanFengRewardVodAd *)rewardVodAd;

/**
 *  激励视频广告视频播放结束
 */
- (void)ranfengRewardVodAdAdVideoPlayFinish:(ADRanFengRewardVodAd *)rewardVodAd;

/**
 *  激励视频广告关闭落地页
 */
- (void)ranfengRewardVodAdCloseLandingPage:(ADRanFengRewardVodAd *)rewardVodAd;


@end

@interface ADRanFengRewardVodAd : NSObject

/**
 委托对象
 */
@property (nonatomic ,weak) id<ADRanFengRewardVodAdDelegate>  delegate;

/**
 详解：当前ViewController
 */
@property (nonatomic, weak) UIViewController *controller;

/**
 请求超时时间,默认为4s,需要设置3s及以上
 */
@property (nonatomic, assign) NSInteger tolerateTimeout;

/**
 广告位id
*/
@property (nonatomic, copy) NSString *posId;

/**
 是否设置视频静音模式（默认：false）
*/
@property (nonatomic ,assign) BOOL playMute;

/**
 支持屏幕类型，默认竖屏
*/
@property (nonatomic, assign) ADRanFengAdSupportScreenType supportScreenType;

/**
 加载广告数据
*/
- (void)loadAdData;

/**
 广告是否超时
 */
- (bool)isDataTimeout;

/**
 展示广告
*/
- (void)showFromRootViewController:(UIViewController *)viewController;
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

/**
 返回广告的出价，单位：分
 
 @return 成功返回一个大于等于0的值，小于等于0表示广告请求失败或获取eCPM时机不正确(请于请求广告成功后获取)
*/
- (NSInteger)bidPrice;

/**
 返回广告的底价，单位：分
 
 @return 成功返回一个大于等于0的值，小于等于0表示广告请求失败或获取底价时机不正确(请于请求广告成功后获取)
*/
- (NSInteger)bidFloor;

/*
 获取广告相关信息，请一定在广告加载成功后获取
 */
- (ADRanFengAdInfoModel *)getInfoData;
@end

NS_ASSUME_NONNULL_END
