//
//  BDAutoTrackConstants.h
//  Pods-BDAutoTracker_Example
//
//  Created by bob on 2019/5/16.
//

#import <Foundation/Foundation.h>

#ifndef BDAutoTrackNotifictaion_H
#define BDAutoTrackNotifictaion_H
/*! @abstract UIViewController 切换事件通知
 userInfo
 @{ kBDAutoTrackViewControllerFormer:NSStringFromClass(from.class),
    kBDAutoTrackViewControllerAfter:NSStringFromClass(to.class),
    kBDAutoTrackSwitchIsBack:@(isBack)
 };
@discussion 通知在主线程，一般情况下监听后，请勿同步进行耗时操作
*/
FOUNDATION_EXTERN NSString * const BDAutoTrackVCSwitchEventNotification;

FOUNDATION_EXTERN NSString * const kBDAutoTrackViewControllerFormer;
FOUNDATION_EXTERN NSString * const kBDAutoTrackViewControllerAfter;
FOUNDATION_EXTERN NSString * const kBDAutoTrackSwitchIsBack;

/*! @abstract SDK 注册成功通知
 userInfo
 @{ kBDAutoTrackNotificationAppID                       :appID,
    kBDAutoTrackNotificationRangersDeviceID    :did,
    kBDAutoTrackNotificationSSID                        :ssid,
    kBDAutoTrackNotificationInstallID                   :iid
    kBDAutoTrackNotificationUserUniqueID          :uuid
    kBDAutoTrackNotificationDataSource:  BDAutoTrackNotificationDataSourceLocalCache | BDAutoTrackNotificationDataSourceServer
    kBDAutoTrackNotificationIsNewUser : 1 | 0
 };
@discussion 通知在子线程，uuid可能为 nil.
@discussion 初始化 SDK 的时候，如果本地已经有 ID 值，会有一次通知
 触发重新注册请求后，请求成功会有另一次通知
 触发条件：
    1. -[BDAuTrack startTrack]
    2. -[BDAuTrack setCurrentUserUniqueID:] 且与上次不一致，包括 nil
    3. -[BDAuTrack setServiceVendor:] 且与上次不一致
*/
FOUNDATION_EXTERN NSString * const BDAutoTrackNotificationRegisterSuccess;

/*!
 @abstract SDK 注册请求失败通知。SDK在注册阶段默认有3次重试策略。每一次注册请求的失败都会触发此通知，并携带剩余的重试次数。
 userInfo
 @{
     @"message": @"register request failure",
     @"remainingRetry": 剩余重试机会(次数)
 };
 */
FOUNDATION_EXTERN NSString * const BDAutoTrackNotificationRegisterFailure;

/*! @abstract SDK 激活成功通知
 userInfo
 @{ kBDAutoTrackNotificationAppID           :appID,
 };
@discussion 通知在子线程，每次触发注册成功后，会触发激活请求
*/
FOUNDATION_EXTERN NSString * const BDAutoTrackNotificationActiveSuccess;

/*! @abstract SDK ABTest配置拉取成功通知
 userInfo
 @{ kBDAutoTrackNotificationAppID           :appID,
    kBDAutoTrackNotificationData            :data,
 };
@discussion 通知在子线程，每次触发注册成功后，且该 App ID 配置了 ABTest 功能，会触发 ABTest 配置拉取。
 收到通知成功后，则可以开始读取 ABTest 值，如果未收到通知，则读取的 ABTest 为上次拉取成功的值。
 这里重点说明不需要去解析data的结构，简单check一下data.count == 0 即可
 如果需要获取所有的ABTest配置，请使用 -[BDAutoTrack allABTestConfigs] 接口
*/
FOUNDATION_EXTERN NSString * const BDAutoTrackNotificationABTestSuccess;

/*! @abstract SDK通知的userInfo的 key 定义
 若无特别说明，值类型为NSString。
*/
FOUNDATION_EXTERN NSString * const kBDAutoTrackNotificationAppID;
FOUNDATION_EXTERN NSString * const kBDAutoTrackNotificationRangersDeviceID;
FOUNDATION_EXTERN NSString * const kBDAutoTrackNotificationSSID;
FOUNDATION_EXTERN NSString * const kBDAutoTrackNotificationInstallID;
FOUNDATION_EXTERN NSString * const kBDAutoTrackNotificationUserUniqueID;
FOUNDATION_EXTERN NSString * const kBDAutoTrackNotificationData;
FOUNDATION_EXTERN NSString * const kBDAutoTrackNotificationIsNewUser;   // 设备注册服务返回，标识是否是新设备. 值为NSNumber(1/0)。

FOUNDATION_EXTERN NSString * const kBDAutoTrackNotificationDataSource;  // 通知来源

typedef NSString * const BDAutoTrackNotificationDataSource NS_TYPED_ENUM;
FOUNDATION_EXTERN BDAutoTrackNotificationDataSource BDAutoTrackNotificationDataSourceLocalCache;  // 通知的数据来自于恢复本地缓存
FOUNDATION_EXTERN BDAutoTrackNotificationDataSource BDAutoTrackNotificationDataSourceServer;      // 通知的数据来自于服务器响应

FOUNDATION_EXTERN NSString * const kBDAutoTrackNotificationDataSourceURL;  // 若通知的数据来自于服务器响应，则userInfo会含有此键。其值是请求URL

/*! @abstract SDK ABTestVid发生变化时候的通知
 userInfo
 @{ kBDAutoTrackNotificationAppID           :appID,
    kBDAutoTrackNotificationABTestVids            :vids,
    kBDAutoTrackNotificationABTestExternalVids:externalVids
 };
@discussion 通知在子线程，每次Vid发生变化时触发。需要该 App ID 配置了 ABTest 功能，否则不会有通知。
*/
FOUNDATION_EXTERN NSString * const BDAutoTrackNotificationABTestVidsChanged;
FOUNDATION_EXTERN NSString * const kBDAutoTrackNotificationABTestVids;
FOUNDATION_EXTERN NSString * const kBDAutoTrackNotificationABTestExternalVids;

#endif
