//
//  ADRanFengSplashAd.h
//  ADRanFengSDK
//
//  Created by 陈则富 on 2021/9/16.
//

#import <UIKit/UIKit.h>
#import <ADRanFengSDK/ADRanFengSplashSkipViewProtocol.h>
#import <ADRanFengSDK/ADRanFengCommonDefine.h>
#import "ADRanFengAdInfoModel.h"

NS_ASSUME_NONNULL_BEGIN

@class ADRanFengSplashAd;

@protocol ADRanFengSplashAdDelegate <NSObject>

@optional
/**
 *  开屏广告请求成功
 */
- (void)ranfengSplashAdSuccessLoad:(ADRanFengSplashAd *)splashAd;

/**
 *  开屏广告请求失败
 */
- (void)ranfengSplashAdFailLoad:(ADRanFengSplashAd *)splashAd withError:(NSError *)error;

/**
 *  开屏广告素材渲染成功
 */
- (void)ranfengSplashAdDidLoad:(ADRanFengSplashAd *)splashAd;

/**
 *  开屏广告渲染失败
 */
- (void)ranfengSplashAdRenderFaild:(ADRanFengSplashAd *)splashAd withError:(NSError *)error;

/**
 *  开屏广告展示成功
 */
- (void)ranfengSplashAdDidPresent:(ADRanFengSplashAd *)splashAd;

/**
 *  开屏广告展示失败
 */
- (void)ranfengSplashAdFailToShow:(ADRanFengSplashAd *)splashAd error:(NSError *)error;

/**
 *  开屏广告曝光回调
 */
- (void)ranfengSplashAdExposured:(ADRanFengSplashAd *)splashAd;

/**
 *  开屏广告点击回调
 */
- (void)ranfengSplashAdClicked:(ADRanFengSplashAd *)splashAd;

/**
 *  开屏广告倒计时结束回调
 */
- (void)ranfengSplashAdCountdownToZero:(ADRanFengSplashAd *)splashAd;

/**
 *  开屏广告点击跳过回调
 */
- (void)ranfengSplashAdSkiped:(ADRanFengSplashAd *)splashAd;

/**
 *  开屏广告关闭回调 & 若打开落地页，请结合使用 ranfengSplashAdCloseLandingPage 回调
 */
- (void)ranfengSplashAdClosed:(ADRanFengSplashAd *)splashAd;

/**
 *  开屏广告关闭落地页回调
 */
- (void)ranfengSplashAdCloseLandingPage:(ADRanFengSplashAd *)splashAd;

@end

@interface ADRanFengSplashAd : NSObject

/**
 * 广告id
 */
@property (nonatomic ,copy) NSString  *posId;

/**
 *  委托对象
 */
@property (nonatomic ,weak) id<ADRanFengSplashAdDelegate>  delegate;

/**
 用于开屏请求过渡，可将启动图转为color传入，默认为透明
 例如：_splashAd.backgroundColor = [UIColor adrf_getColorWithImage:[UIImage imageNamed:@"750x1334.png"] withNewSize:[UIScreen mainScreen].bounds.size];
*/
@property (nonatomic, copy, nullable) UIColor *backgroundColor;

/**
 * 跳过按钮的类型，可以通过此接口替换开屏广告的跳过按钮样式
 */
@property (nonatomic, strong, null_resettable) UIView<ADRanFengSplashSkipViewProtocol> *skipView;

/**
 * 不使用自带跳过视图
 */
@property (nonatomic, readwrite, assign) BOOL hiddenSkipView;

/**
 使用 controller present 落地页，默认获取当前window最上层控制器
 */
@property (nonatomic, weak) UIViewController *viewController;

/// 屏蔽摇一摇、晃一晃
@property (nonatomic, assign) bool disableMotion;

/**
 设置视频是否有声音（默认：false）
*/
@property (nonatomic ,assign) BOOL playLoud;

/**
加载并展示开屏
如果全屏广告bottomView设置为nil
@param window 开屏广告展示的window，若为自定义window需设置viewController
@param bottomView 底部logo视图, 高度不能超过屏幕的25%
*/
- (void)loadAndShowInWindow:(UIWindow *)window withBottomView:(nullable UIView *)bottomView;


/**
 加载开屏广告（不会自动调用展示方法，需开发者于成功回调后调用showAdInWindow:）
 建议竞价广告询价使用
 */
- (void)loadAd RFDeprecated("接口即将废弃，请使用loadAdWithBottomView:");

/**
加载开屏广告 （不会自动调用展示方法，需开发者于成功回调后调用showAdInWindow:）
建议竞价广告询价使用
如果全屏广告bottomView设置为nil
@param bottomView 底部logo视图, 高度不能超过屏幕的25%
*/
- (void)loadAdWithBottomView:(nullable UIView *)bottomView;

/**
 展示开屏广告（与loadAd或loadAdWithBottomView:一同使用，于成功回调后调用）
 @param window 开屏广告展示的window，若为自定义window需设置viewController
 @param bottomView 底部logo视图, 高度不能超过屏幕的25%
 */
- (void)showInWindow:(UIWindow *)window withBottomView:(nullable UIView *)bottomView RFDeprecated("接口即将废弃，请使用showInWindow:");
- (void)showInWindow:(UIWindow *)window;

/// 广告是否超时
- (bool)isDataTimeout;

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

/*
 获取广告相关信息，请一定在广告加载成功后获取
 */
- (ADRanFengAdInfoModel *)getInfoData;
@end

NS_ASSUME_NONNULL_END
