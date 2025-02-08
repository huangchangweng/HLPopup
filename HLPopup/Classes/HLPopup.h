//
//  HLPopup.h
//  HLPopup
//
//  Created by hcw on 2023/9/15.
//  Copyright © 2023年 hcw. All rights reserved.
//

#import <UIKit/UIKit.h>

/**
 HLPopupShowType
 Controlled how the popup will be presented.
 */
typedef NS_ENUM(NSUInteger, HLPopupShowType) {
    HLPopupShowTypeNone NS_SWIFT_NAME(none),
    HLPopupShowTypeFadeIn NS_SWIFT_NAME(fadeIn),
    HLPopupShowTypeGrowIn NS_SWIFT_NAME(growIn),
    HLPopupShowTypeShrinkIn NS_SWIFT_NAME(shrinkIn),
    HLPopupShowTypeSlideInFromTop NS_SWIFT_NAME(slideInFromTop),
    HLPopupShowTypeSlideInFromBottom NS_SWIFT_NAME(slideInFromBottom),
    HLPopupShowTypeSlideInFromLeft NS_SWIFT_NAME(slideInFromLeft),
    HLPopupShowTypeSlideInFromRight NS_SWIFT_NAME(slideInFromRight),
    HLPopupShowTypeBounceIn NS_SWIFT_NAME(bounceIn),
    HLPopupShowTypeBounceInFromTop NS_SWIFT_NAME(bounceInFromTop),
    HLPopupShowTypeBounceInFromBottom NS_SWIFT_NAME(bounceInFromBottom),
    HLPopupShowTypeBounceInFromLeft NS_SWIFT_NAME(bounceInFromLeft),
    HLPopupShowTypeBounceInFromRight NS_SWIFT_NAME(bounceInFromRight)
} NS_SWIFT_NAME(HLPopup.ShowType);

/**
 HLPopupDismissType
 Controlled how the popup will be dismissed.
 */
typedef NS_ENUM(NSUInteger, HLPopupDismissType) {
    HLPopupDismissTypeNone NS_SWIFT_NAME(none),
    HLPopupDismissTypeFadeOut NS_SWIFT_NAME(fadeOut),
    HLPopupDismissTypeGrowOut NS_SWIFT_NAME(growOut),
    HLPopupDismissTypeShrinkOut NS_SWIFT_NAME(shrinkOut),
    HLPopupDismissTypeSlideOutToTop NS_SWIFT_NAME(slideOutToTop),
    HLPopupDismissTypeSlideOutToBottom NS_SWIFT_NAME(slideOutToBottom),
    HLPopupDismissTypeSlideOutToLeft NS_SWIFT_NAME(slideOutToLeft),
    HLPopupDismissTypeSlideOutToRight NS_SWIFT_NAME(slideOutToRight),
    HLPopupDismissTypeBounceOut NS_SWIFT_NAME(bounceOut),
    HLPopupDismissTypeBounceOutToTop NS_SWIFT_NAME(bounceOutToTop),
    HLPopupDismissTypeBounceOutToBottom NS_SWIFT_NAME(bounceOutToBottom),
    HLPopupDismissTypeBounceOutToLeft NS_SWIFT_NAME(bounceOutToLeft),
    HLPopupDismissTypeBounceOutToRight NS_SWIFT_NAME(bounceOutToRight)
} NS_SWIFT_NAME(HLPopup.DismissType);

/**
 HLPopupHorizontalLayout
 Controlled the layout of the popup in the horizontal direction.
 */
typedef NS_ENUM(NSUInteger, HLPopupHorizontalLayout) {
    HLPopupHorizontalLayoutCustom NS_SWIFT_NAME(custom),
    HLPopupHorizontalLayoutLeft NS_SWIFT_NAME(left),
    HLPopupHorizontalLayoutLeftOfCenter NS_SWIFT_NAME(leftOfCenter),
    HLPopupHorizontalLayoutCenter NS_SWIFT_NAME(center),
    HLPopupHorizontalLayoutRightOfCenter NS_SWIFT_NAME(rightOfCenter),
    HLPopupHorizontalLayoutRight NS_SWIFT_NAME(right)
} NS_SWIFT_NAME(HLPopup.HorizontalLayout);

/**
 HLPopupVerticalLayout
 Controlled the layout of the popup in the vertical direction.
 */
typedef NS_ENUM(NSUInteger, HLPopupVerticalLayout) {
    HLPopupVerticalLayoutCustom NS_SWIFT_NAME(custom),
    HLPopupVerticalLayoutTop NS_SWIFT_NAME(top),
    HLPopupVerticalLayoutAboveCenter NS_SWIFT_NAME(aboveCenter),
    HLPopupVerticalLayoutCenter NS_SWIFT_NAME(center),
    HLPopupVerticalLayoutBelowCenter NS_SWIFT_NAME(belowCenter),
    HLPopupVerticalLayoutBottom NS_SWIFT_NAME(bottom)
} NS_SWIFT_NAME(HLPopup.VerticalLayout);

/**
 HLPopupMaskType
 Controlled whether to allow interaction with the underlying view.
 */
typedef NS_ENUM(NSUInteger, HLPopupMaskType) {
    /// Allow interaction with underlying view.
    HLPopupMaskTypeNone NS_SWIFT_NAME(none),
    /// Don't allow interaction with underlying view.
    HLPopupMaskTypeClear NS_SWIFT_NAME(clear),
    /// Don't allow interaction with underlying view, dim background.
    HLPopupMaskTypeDimmed NS_SWIFT_NAME(dimmed)
} NS_SWIFT_NAME(HLPopup.MaskType);

/** HLPopupLayout */
struct HLPopupLayout {
    HLPopupHorizontalLayout horizontal;
    HLPopupVerticalLayout vertical;
};

typedef struct HLPopupLayout HLPopupLayout;

extern HLPopupLayout HLPopupLayoutMake(HLPopupHorizontalLayout horizontal, HLPopupVerticalLayout vertical) NS_SWIFT_NAME(HLPopupLayout(horizontal:vertical:));

extern HLPopupLayout const HLPopupLayoutCenter NS_SWIFT_NAME(HLPopupLayout.Center);

NS_ASSUME_NONNULL_BEGIN

@interface HLPopup : UIView

/**
 The view you want to appear in popup.
 
 Must provide contentView before or in `-willStartShowing`.
 Must set size of contentView before or in `-willStartShowing`.
 */
@property (nonatomic, strong) UIView *contentView;

/**
 Animation transition for presenting contentView.
 
 @discussion The default value is `HLPopupShowTypeFadeIn`.
 */
@property (nonatomic, assign) HLPopupShowType showType;

/**
 Animation transition for dismissing contentView.
 
 @discussion The default value is `HLPopupDismissTypeFadeOut`.
 */
@property (nonatomic, assign) HLPopupDismissType dismissType;

/**
 Mask prevents background touches from passing to underlying views.
 
 @discussion The default value is `HLPopupMaskTypeDimmed`.
 */
@property (nonatomic, assign) HLPopupMaskType maskType;

/**
 Overrides alpha value for dimmed mask.
 
 @discussion The default value is `0.5`.
 */
@property (nonatomic, assign) CGFloat dimmedMaskAlpha;

/**
 Overrides animation duration for show in.
 
 @discussion The default value is `0.15`.
 */
@property (nonatomic, assign) CGFloat showInDuration;

/**
 Overrides animation duration for dismiss out.
 
 @discussion The default value is `0.15`.
 */
@property (nonatomic, assign) CGFloat dismissOutDuration;

/**
 If `YES`, the popup will dismiss when background is touched.
 
 @discussion The default value is `YES`.
 */
@property (nonatomic, assign) BOOL shouldDismissOnBackgroundTouch;

/**
 If `YES`, the popup will dismiss when content view is touched.
 
 @discussion The default value is `NO`.
 */
@property (nonatomic, assign) BOOL shouldDismissOnContentTouch;

/**
 A block to be executed when showing animation started.
 The default value is nil.
 */
@property (nonatomic, copy, nullable) void(^willPresentBlock)(HLPopup *popup);

/**
 A block to be executed when showing animation finished.
 The default value is nil.
 */
@property (nonatomic, copy, nullable) void(^didPresentBlock)(HLPopup *popup);

/**
 A block to be executed when dismissing animation started.
 The default value is nil.
 */
@property (nonatomic, copy, nullable) void(^willDismissBlock)(HLPopup *popup);

/**
 A block to be executed when dismissing animation finished.
 The default value is nil.
 */
@property (nonatomic, copy, nullable) void(^didDismissBlock)(HLPopup *popup);

/**
 Adjust the spacing between with the keyboard.
 @discussion The default value is `0`.
 */
@property (nonatomic, assign) CGFloat keyboardOffsetSpacing;

/// default is NO. if YES, Will adjust view position when keyboard changes
@property (nonatomic, assign) BOOL keyboardChangeFollowed;

/**
 Convenience Initializers
 Create a new popup with `contentView`.
 */
+ (HLPopup *)popupWithContentView:(UIView *)contentView NS_SWIFT_NAME(init(contentView:));

/**
 Convenience Initializers
 Create a new popup with custom values.
 
 @param contentView The view you want to appear in popup.
 @param showType    The default value is `HLPopupShowTypeBounceInFromTop`.
 @param dismissType The default value is `HLPopupDismissTypeBounceOutToBottom`.
 @param maskType    The default value is `HLPopupMaskTypeDimmed`.
 @param shouldDismissOnBackgroundTouch  The default value is `YES`.
 @param shouldDismissOnContentTouch     The default value is `NO`.
 */
+ (HLPopup *)popupWithContentView:(UIView *)contentView
                         showType:(HLPopupShowType)showType
                      dismissType:(HLPopupDismissType)dismissType
                         maskType:(HLPopupMaskType)maskType
         dismissOnBackgroundTouch:(BOOL)shouldDismissOnBackgroundTouch
            dismissOnContentTouch:(BOOL)shouldDismissOnContentTouch NS_SWIFT_NAME(init(contentView:showType:dismissType:maskType:dismissOnBackgroundTouch:dismissOnContentTouch:));

/**
 Dismiss all the popups in the app.
 */
+ (void)dismissAllPopups NS_SWIFT_NAME(dismissAll());

/**
 Dismiss the popup for contentView.
 */
+ (void)dismissPopupForView:(UIView *)view animated:(BOOL)animated NS_SWIFT_NAME(dismiss(contentView:animated:));

/**
 Dismiss super popup.
 Iterate over superviews until you find a `HLPopup` and dismiss it.
 */
+ (void)dismissSuperPopupIn:(UIView *)view animated:(BOOL)animated NS_SWIFT_NAME(dismissSuperPopup(inView:animated:));

/**
 Show popup with center layout.
 `HLPopupVerticalLayoutCenter` & `HLPopupHorizontalLayoutCenter`
 Showing animation is determined by `showType`.
 */
- (void)show;

/**
 Show popup with specified layout.
 Showing animation is determined by `showType`.
 */
- (void)showWithLayout:(HLPopupLayout)layout NS_SWIFT_NAME(show(layout:));

/**
 Show and then dismiss popup after `duration`.
 If duration is `0.0` or `less`, it will be considered infinity.
 */
- (void)showWithDuration:(NSTimeInterval)duration NS_SWIFT_NAME(show(duration:));

/**
 Show popup with specified `layout` and then dismissed after `duration`.
 If duration is `0.0` or `less`, it will be considered infinity.
 */
- (void)showWithLayout:(HLPopupLayout)layout duration:(NSTimeInterval)duration NS_SWIFT_NAME(show(layout:duration:));

/**
 Show popup at point in view's coordinate system.
 If view is nil, will use screen base coordinates.
 */
- (void)showAtCenterPoint:(CGPoint)point inView:(UIView *)view NS_SWIFT_NAME(show(center:inView:));

/**
 Show popup at point in view's coordinate system and then dismissed after duration.
 If view is nil, will use screen base coordinates.
 If duration is `0.0` or `less`, it will be considered infinity.
 */
- (void)showAtCenterPoint:(CGPoint)point inView:(UIView *)view duration:(NSTimeInterval)duration NS_SWIFT_NAME(show(center:inView:duration:));

/**
 Dismiss popup.
 */
- (void)dismiss;

/**
 Dismiss popup.
 Use `dismissType` if animated is `YES`.
 */
- (void)dismissAnimated:(BOOL)animated NS_SWIFT_NAME(dismiss(animated:));

#pragma mark - ReadOnly Properties
@property (nonatomic, strong, readonly) UIView *backgroundView;
@property (nonatomic, strong, readonly) UIView *containerView;
@property (nonatomic, assign, readonly) BOOL isBeingShown;
@property (nonatomic, assign, readonly) BOOL isShowing;
@property (nonatomic, assign, readonly) BOOL isBeingDismissed;

@end

NS_ASSUME_NONNULL_END
