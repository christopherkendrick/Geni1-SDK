//
//  GENi1BLEEnum.h
//
//  Created by 郭吉成 on 2017/12/12.
//  Copyright © 2017年 KOOSPUR. All rights reserved.
//

#ifndef GENi1BLE_ENUM_H
#define GENi1BLE_ENUM_H

#import <Foundation/Foundation.h>

/*!
 iPhone BLE state
 */
typedef NS_ENUM(NSInteger, GENi1BLEOpenState) {
    GENi1BLEOpenStateIsOpen = 1,//iPhone BLE open
    GENi1BLEOpenStateIsClosed = 2//iPhone BLE close
};

/*!
 sensor connect state
 */
typedef NS_ENUM(NSInteger, GENi1SensorConnectState) {
    GENi1SensorConnectStateIDE,      //BLE manager IDE
    GENi1SensorConnectStateScanning, //BLE manager scanning
    GENi1SensorConnectStateConnected,//BLE manager connected
    GENi1SensorConnectStateRecover   //un use
};

/*!
 sensor type
 */
typedef NS_ENUM(NSInteger, GENi1SensorType) {
    GENi1SensorTypeGolfBall,    //sensor type of ball
    GENi1SensorTypeGolfPutter,  //sensor type of putter
    GENi1SensorTypeUnknown
};

/*!
 sensor request data state
 */
typedef NS_ENUM(NSInteger, GENi1RequestSensorDataState) {
    GENi1RequestSensorDataStateFail = 0,
    GENi1RequestSensorDataStateSuccess = 1
};

/*!
 BLE manager connect sensor mode
 */
typedef NS_ENUM(NSInteger, GENi1ConnectSensorMode) {
    GENi1ConnectSensorModeOnlyBall = 0,          //only connect sensor of ball
    GENi1ConnectSensorModeOnlyClub = 1,          //only connect sensor of putter
    GENi1ConnectSensorModeBoth                   //both
};

/**
 user putter length
 Unit : inch
 */
typedef NS_ENUM(NSInteger, GENi1UserPutterLength) {
    GENi1UserPutterLength_32_or_less = 32,  //32 inch or less
    GENi1UserPutterLength_33,
    GENi1UserPutterLength_34,
    GENi1UserPutterLength_35,
    GENi1UserPutterLength_36,
    GENi1UserPutterLength_37,
    GENi1UserPutterLength_38,
    GENi1UserPutterLength_39_or_longer    //39 inch or longer
};


//connect sensor time out error code
#define kConnectTimeOut                 1001

//BLE manager error code
#define kBluetoothStateUnknow           1002
#define kBluetoothStateUnsupported      1003
#define kBluetoothStateUnauthorized     1004
#define kBluetoothStateResetting        1005
#define kBluetoothPowerOff              1006

#define kSwingErrorPutter               1007 //The putter putting was not detected effectively!
#define kSwingErrorBallRoll             1008 //The ball was not hit effectively!
#define kSwingErrorBallData             1009 //Ball rolling is timeout!

#endif
