//
//  GENi1BLECenterManager.h
//  GENi1BLESDK
//
//  Created by 郭吉成 on 2017/12/12.
//  Copyright © 2017年 KOOSPUR. All rights reserved.
//

@import CoreBluetooth;
#import <UIKit/UIKit.h>
#import "GENi1BLEEnum.h"

#define     kServiceUUID        @"0001"
#define     kWriteUUID          @"0002"
#define     kNotifyUUID         @"0003"
#define     kReadMacUUID        @"0004"

@class GENi1BLECenterManager;

#pragma mark -- GENi1BLECenterManagerDelegate

@protocol GENi1BLECenterManagerDelegate <NSObject>

@optional

/*
 
 BLE center manager operation
 
 */

/*!
 On connecting sensor
 This method is called when the connection sensor started
 */
- (void)onConnect;

/*!
 On connect failed
 This method is called when the connection sensor failed
 */
- (void)onConnectFailError:(NSError *_Nullable)error;

/*!
 Connect sensor succeed
 This method is called when the connection sensor succeed
 */
- (void)onConnectSuccess;

/*!
 Lose connection with sensor
 This method is called when the sensor's connect is lose
 if this method is called:
 1 - you must reconnect sensor
 2 - after you have connected sensor success ,you need enter real time mode
 */
- (void)onDisconnectError:(NSError *_Nullable)error;



/*
 
 sensor data operation
 
 */

/*!
 start hit ball
 This method is called when the sensor check swing action
 */
- (void)startHitBall;

/*!
 on hit ball
 This method is called when the swing is going
 */
- (void)onHitBall;

/*!
 finish hit ball
 This method is called when the swing finishs succeed
 
 @param ballDataDic - ball data
        Key             Type     Format   Unit      Description
    totalDistance     NSString     %d      mm       the ball rolls total distance
    skipDistance      NSString     %d      mm       the distance the ball bounces (360 °from the start to the ball's rotation)
    ballSpeed         NSString     %.1f    km/h     the speed at which the ball starts to roll
    ballRotation      NSString     %.1f    °        turn the ball in the direction of rotation
    initialDirection  NSString     %.1f    °        the initial direction of the ball
 
 @param putterDataDic - putter data
        Key             Type     Format   Unit      Description
    CFA               NSString     %.1f    °        Club Face Angle
    backLength        NSString     %.1f    mm       the length of the club back
    forwardLength     NSString     %.1f    mm       the length of the club forward
    backTime          NSString     %d      ms       the length of the club back time
    forwardTime       NSString     %d      ms       the length of the club forward time
    shaftAngle        NSString     %.1f    °        pitch the ball when the direction of the tilt angle
 */
- (void)onHitBallSuccessForBallDataDic:(NSDictionary *_Nullable)ballDataDic
                         putterDataDic:(NSDictionary *_Nullable)putterDataDic;

/*!
 hit ball failed
 This method is called when the swing is failed
 */
- (void)onHitBallFailError:(NSError *_Nullable)error;

@required

@end









/*
 
 BLE center manager
 
 */
@interface GENi1BLECenterManager : NSObject
@property (nonatomic, weak, nullable) id <GENi1BLECenterManagerDelegate> delegate;

#warning when you Archive, please setup Bitcode is "NO"

+ (nullable GENi1BLECenterManager *) shareCBCentralManager;

/*!
 Conect sensor

 @param timeout              setup connect timeout, default is 10s
 @param mode                 setup connect sensor mode, not allow nil
 @param upperLimitRSSI       setup RSSI, 0 ~ -100dbm, default is -50dbm. When conduct, the test shall prevail
                             if you want connect which sensor is nearby iPhone, you can setup RSSI is close to 0
 
 @param putterLength         setup putter length, default is 35 inch
 */
- (void)connectSensorsWithTimeout:(NSTimeInterval) timeout
           GENi1ConnectSensorMode:(GENi1ConnectSensorMode) mode
                   upperLimitRSSI:(NSNumber *_Nullable) upperLimitRSSI
            GENi1UserPutterLength:(GENi1UserPutterLength) putterLength;

/*!
 Cancel connect
 cancel connect sensor
 */
- (void)cancelConnect;

/*!
 disconnect all sensor
 you will disconnect all sensor
 */
- (void)disconnectAllDevice;

/*!
 enter real time mode
 if sensor check swing action , method -"startHitBall" will called
 */
- (void)enterRealTimeMode;

/*!
 quit real time mode
 you will quit real time mode, sensor will not check swing action until called method -"enterRealTimeMode"
 */
- (void)quitRealTimeMode;


@end
