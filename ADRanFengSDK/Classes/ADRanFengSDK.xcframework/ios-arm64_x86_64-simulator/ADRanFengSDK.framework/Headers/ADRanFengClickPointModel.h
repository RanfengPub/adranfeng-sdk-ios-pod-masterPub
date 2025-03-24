//
//  ADRanFengClickPointModel.h
//  ADRanFengSDK
//
//  Created by 刘娟 on 2022/12/6.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
NS_ASSUME_NONNULL_BEGIN

@interface ADRanFengClickPointModel : NSObject

@property (nonatomic , assign) CGPoint startPoint;/**< 开始位置 */
@property (nonatomic , assign) CGPoint endPoint;/**< 结束位置 */
@property (nonatomic , assign) CGPoint startScreenPoint;/**< 相对于父控制器开始位置 */
@property (nonatomic , assign) CGPoint endScreenPoint;/**< 相对于父控制器结束位置 */

@property (nonatomic , assign) int32_t xMaxAcc;/**< 用户摇动点击时x轴加速度峰值 */
@property (nonatomic , assign) int32_t yMaxAcc;/**< 用户摇动点击时y轴加速度峰值 */
@property (nonatomic , assign) int32_t zMaxAcc;/**< 用户摇动点击时z轴加速度峰值 */

@property (nonatomic , assign) int32_t turnX;/**< 扭动触发点击时的x轴扭动角度 */
@property (nonatomic , assign) int32_t turnY;/**< 扭动触发点击时的y轴扭动角度 */
@property (nonatomic , assign) int32_t turnZ;/**< 扭动触发点击时的z轴扭动角度 */
@property (nonatomic , assign) int32_t turnTime;/**< 扭动触发点击时扭动的总时间（单位毫秒，保留整数）。即最后一次监听到3个方向扭动角度均小于±5度，到点击触发的时间。 */

/// 获取默认值是-999的坐标
+(instancetype)getDefaultPoint999;

@end

NS_ASSUME_NONNULL_END
