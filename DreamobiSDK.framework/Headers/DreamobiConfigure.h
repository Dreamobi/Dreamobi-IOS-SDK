//
//  DreamobiConfigure.h
//  DreamobiDemo1.6
//
//  Created by Dreamobi on 15/1/26.
//  Copyright (c) 2015年 Dreamobi. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "DreamobiNative.h"
#import "DreamobiVideo.h"

typedef enum {
    
    NOSIZE=0,
    
    ICON_50X50 =1,
    ICON_100X100 =2,
    ICON_175X175 =3,
    BANNER_1200X627 =4,
    BANNER_640X334 =5,
    
}AdSize;

@protocol DreamobiAdVideoRewardDelegate;
@protocol DreamobiNativeAd;
@protocol DreamobiAdDelegate;


@interface DreamobiConfigure : NSObject

+ (void)isTest;

+ (DreamobiConfigure *)config;

- (void)configureWithAppToken :(NSString *)appToken zoneIDs :(NSArray *)zoneIDs appBundleId :(NSString *)bundle_id delegate :(id<DreamobiAdVideoRewardDelegate>)del;

+ (BOOL)isNoVideoWithZoneID:(NSString *)zoneID;

+ (void)getNativeAdWithZone:(NSString *)zoneID withIconSize:(AdSize)iconSize withBannerSize:(AdSize)bannerSize  withDelegate:(id<DreamobiNativeAd>)del;

+ (DreamobiVideo *)getVideoMessageWithZoneID:(NSString *)zoneID;

+ (void)showAdWallWithZone:(NSString *)zoneID withDelegate:(id<DreamobiAdDelegate>)del;

+ (void)showVideoWithZone:(NSString *)zoneID withDelegate:(id<DreamobiAdDelegate>)del;

@end

@protocol  DreamobiAdVideoRewardDelegate<NSObject>
@required
- (void)dreamobiAdVideoReward :(BOOL)success isConnect:(BOOL)isConnect  getPoint:(long)point;
@end

@protocol DreamobiAdDelegate <NSObject>
@required
- (void)dreamobiAdVideoStarted;

- (void)dreamobiAdVideoFinished;

@end

@protocol DreamobiNativeAd <NSObject>
@required
- (void)dreamobiNativeAd :(DreamobiNative*)nativeMessage;

@end
