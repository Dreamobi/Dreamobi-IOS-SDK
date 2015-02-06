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


/**
 * Enum for AdSize
 */
typedef enum {
    NOSIZE=0,
    
    ICON_50X50 =1,
    ICON_100X100 =2,
    ICON_175X175 =3,
    BANNER_1200X627 =4,
    BANNER_640X334 =5,
    
}AdSize;


#pragma mark -
#pragma mark DreamobiAdVideoRewardDelegate protocol

/**
 *  Use the DreamobiAdVideoRewardDelegate to receive callbacks when ad availability changes or when a video transaction has completed.
 *  This delegate is passed to Dreamobi during configuration using   [[DreamobiConfigure config]configureWithAppToken: zoneIDs: appBundleId: delegate:];
 */

@protocol  DreamobiAdVideoRewardDelegate<NSObject>
@required


/**
 *  Dreamobi has successfully rewarded. Client-side implementations should increment the user's surrency;
 *  @param  success Whether the transaction succeeded or failed
 *  @param  Identify if the user connect to Internet
 *  @param  Amount of coin grant to user
 */
- (void)dreamobiAdVideoReward :(BOOL)success isConnect:(BOOL)isConnect  getPoint:(long)point;
@end


#pragma mark -
#pragma mark DreamobiAdDelegate protocol

/**
 *  Use the DreamobiAdDelegate to receive callbacks when ads start playing or when an attempt to play
 *  an ad has finished (successfully or not).
 *  This is most frequently used by apps to pause app sound and music during the display of an ad.
 *  This delegate is passed to Dreamobi when you call a method to play an ad.
 */
@protocol DreamobiAdDelegate <NSObject>
@required
/**
 * Notifies your app that an ad will actually play in response to the app's request to play an ad.
 * This method is called when AdColony has taken control of the device screen and is about to begin
 * showing an ad. Apps should implement app-specific code such as pausing a game and turning off app music.
 */
- (void)dreamobiAdVideoStarted;

/**
 * Notifies your app that an ad completed playing (or never played) and control has been returned to the app.
 * If an ad was shown, apps should implement app-specific code such as unpausing a game and restarting app music.
 */
- (void)dreamobiAdVideoFinished;

@end

#pragma mark -
#pragma mark DreamobiNativeAd protocol

@protocol DreamobiNativeAd <NSObject>
@required
- (void)dreamobiNativeAd :(DreamobiNative*)nativeMessage;

@end


#pragma mark - 
#pragma mark Dreamobi interface

/**
 * The Dreamobi class provides methods to start Dreamobi, display ads.
 */
@interface DreamobiConfigure : NSObject


/**
 *  Configures Dreamobi specifically for your app; required for usage of the rest of the API.
 *  This method returns immediately; any long-running work such as network connections are performed in the background.
 *  AdColony does not begin preparing ads for display or performing reporting until after it is configured by your app.
 *  @param appToken For the validation of authority
 *  @param zoneIDs An array of at least one Dreamobi zone ID string.
 *  @param appBundleId For bundle_id of App store
 *  @param del The delegate to receive video and ad availability events. Can be `nil` for apps that do not need these events.
 */

+ (DreamobiConfigure *)config;

- (void)configureWithAppToken :(NSString *)appToken zoneIDs :(NSArray *)zoneIDs appBundleId :(NSString *)bundle_id delegate :(id<DreamobiAdVideoRewardDelegate>)del;

/**   Playing Video Ads  */

/**
 *  Show an Dreamobi WallAd
 * @param zoneID The zone from which the ad should play.
 * @param del The delegate to receive ad events. Can be `nil` for apps that do not need these events.
 */
+ (void)showAdWallWithZone:(NSString *)zoneID withDelegate:(id<DreamobiAdDelegate>)del;
/**
 *  Show an Dreamobi Video
 * @param zoneID The zone from which the ad should play.
 * @param del The delegate to receive ad events. Can be `nil` for apps that do not need these events.
 */
+ (void)showVideoWithZone:(NSString *)zoneID withDelegate:(id<DreamobiAdDelegate>)del;

/**
 *detect if the video is available in the adposition(zoneID)
 */
+ (BOOL)isAvailVideoWithZoneID:(NSString *)zoneID;

/**
 * get Dreamobi NativeAd
 */
+ (void)getNativeAdInfoWithZone:(NSString *)zoneID withIconSize:(AdSize)iconSize withBannerSize:(AdSize)bannerSize  withDelegate:(id<DreamobiNativeAd>)del;

+ (DreamobiVideo *)getVideoInfoWithZoneID:(NSString *)zoneID;



@end


