//
//  UIPrintInfo.h
//  UIKit
//
//  Copyright 2010-2012 Apple Inc. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <CoreGraphics/CoreGraphics.h>
#import <UIKit/UIKitDefines.h>

NS_ASSUME_NONNULL_BEGIN

typedef NS_ENUM(NSInteger, UIPrintInfoOutputType) {
    UIPrintInfoOutputGeneral,           // B&W or color, normal quality output for mixed text, graphics, and images
    UIPrintInfoOutputPhoto,             // B&W or color, best quality output for images
    UIPrintInfoOutputGrayscale,         // B&W content only
    UIPrintInfoOutputPhotoGrayscale NS_ENUM_AVAILABLE_IOS(7_0),    // B&W only, best quality output for images
 };

typedef NS_ENUM(NSInteger, UIPrintInfoOrientation) {
    UIPrintInfoOrientationPortrait,
    UIPrintInfoOrientationLandscape,
};

typedef NS_ENUM(NSInteger, UIPrintInfoDuplex) {
    UIPrintInfoDuplexNone,
    UIPrintInfoDuplexLongEdge,       // flip back page along long edge (same orientation in portrait, flipped for landscape)
    UIPrintInfoDuplexShortEdge,      // flip back page along short edge (flipped orientation for portrait, same in landscape)
};

NS_CLASS_AVAILABLE_IOS(4_2) @interface UIPrintInfo : NSObject <NSCopying, NSCoding>

- (instancetype)initWithCoder:(NSCoder *)aDecoder NS_DESIGNATED_INITIALIZER;

+ (UIPrintInfo *)printInfo;
+ (UIPrintInfo *)printInfoWithDictionary:(nullable NSDictionary *)dictionary;

- (NSDictionary *)dictionaryRepresentation;

@property(nullable,nonatomic,copy)     NSString                *printerID;         // default is nil. set after user selects printer
@property(nonatomic,copy)     NSString                *jobName;           // default is application name
@property(nonatomic)          UIPrintInfoOutputType    outputType;        // default is UIPrintInfoOutputGeneral
@property(nonatomic)          UIPrintInfoOrientation   orientation;       // default is UIPrintInfoOrientationPortrait
@property(nonatomic)          UIPrintInfoDuplex        duplex;            // default is based on document type (none for photo, long edge for other)

@end

NS_ASSUME_NONNULL_END