//
//  HLViewController.m
//  HLPopup
//
//  Created by huangchangweng on 09/15/2023.
//  Copyright (c) 2023 huangchangweng. All rights reserved.
//

#import "HLViewController.h"
#import <HLPopup.h>

@interface HLViewController ()

@end

@implementation HLViewController

- (void)viewDidLoad
{
    [super viewDidLoad];
	// Do any additional setup after loading the view, typically from a nib.
}

- (void)didReceiveMemoryWarning
{
    [super didReceiveMemoryWarning];
    // Dispose of any resources that can be recreated.
}

#pragma mark - Response Event

- (IBAction)showAction:(UIButton *)sender {
    UIView *customView = [[UIView alloc] initWithFrame:CGRectMake(0, 0, 300, 350)];
    customView.backgroundColor = [UIColor whiteColor];
    
    HLPopup *popup = [HLPopup popupWithContentView:customView];
    popup.showType = HLPopupShowTypeFadeIn;
    popup.dismissType = HLPopupDismissTypeFadeOut;
    popup.maskType = HLPopupMaskTypeDimmed;
    popup.shouldDismissOnBackgroundTouch = YES;
    popup.shouldDismissOnContentTouch = NO;
    HLPopupLayout layout = HLPopupLayoutMake(HLPopupHorizontalLayoutCenter, HLPopupVerticalLayoutCenter);
    [popup showWithLayout:layout duration:0];
}

@end
