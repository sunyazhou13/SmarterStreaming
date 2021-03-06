//
//  SmartPublisherSDK.h
//  SmartPublisherSDK
//
//  GitHub: https://github.com/daniulive/SmarterStreaming
//
//  Created by daniulive on 16/3/24.
//  Copyright © 2016年 daniulive. All rights reserved.
//

#import <UIKit/UIKit.h>
#import <Foundation/Foundation.h>
#import <AVFoundation/AVFoundation.h>

/**
 *  错误返回值
 */
typedef enum DNErrorCode{
    DANIULIVE_RETURN_OK = 0,        //!< 返回OK
    DANIULIVE_RETURN_ERROR,         //!< 返回错误
    DANIULIVE_RETURN_SDK_EXPIRED    //!< SDK过期
}DNErrorCode;

/**
 *  推流分辨率选择
 */
typedef enum DNVideoStreamingQuality{
    DN_VIDEO_QUALITY_LOW,           //!< 视频分辨率：低清.
    DN_VIDEO_QUALITY_MEDIUM,        //!< 视频分辨率：标清.
    DN_VIDEO_QUALITY_HIGH           //!< 视频分辨率：高清.
}DNVideoStreamingQuality;

/**
 *  前后置摄像头
 */
typedef enum DNCameraPosition{
    DN_CAMERA_POSITION_BACK,         //!< 后置摄像头.
    DN_CAMERA_POSITION_FRONT         //!< 前置摄像头.
    
} DNCameraPosition;

@interface SmartPublisherSDK : NSObject

/**
 * 初始化Publisher
 * <pre>此接口请第一个调用</pre>
 *
 * @return {0} if successful
 */
- (NSInteger)SmartPublisherInit;

/**
 * 设置video preview
 */
-(NSInteger)SmartPublisherSetVideoPreview:(UIView*)preview;

/**
 * 开始采集音视频数据
 * <pre>resolution：采集分辨率</pre>
 */
-(NSInteger)SmartPublisherStartCapture:(DNVideoStreamingQuality)resolution;

/**
 * 切换前后置摄像头
 * <pre>必须在SmartPublisherStartCapture之后调用</pre>
 */
-(NSInteger)SmartPublisherSwitchCamera;

/**
 * 开始推流
 *
 * <pre>publisherURL：推流地址</pre>
 *
 * @return {0} if successful
 */
- (NSInteger)SmartPublisherStartPublish:(NSString *)publisherURL;

/**
 * 停止推流
 *
 * @return {0} if successful
 */
- (NSInteger)SmartPublisherStopPublish;

/**
 * 停止采集音视频数据
 *
 * @return {0} if successful
 */
- (NSInteger)SmartPublisherStopCaputure;

/**
 * uninit推流SDK
 *
 * @return {0} if successful
 */
- (NSInteger)SmartPublisherUnInit;

/**
 *  获取当前sdk的版本号
 */
-(NSString*) getSDKVersionID;


@end
