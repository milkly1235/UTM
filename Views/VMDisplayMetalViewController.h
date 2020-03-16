//
// Copyright © 2019 osy. All rights reserved.
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.
//

#import <UIKit/UIKit.h>
#import "UTMVirtualMachineDelegate.h"
#import "CSInput.h"

@class UTMVirtualMachine;
@class VMKeyboardView;
@class VMKeyboardButton;

NS_ASSUME_NONNULL_BEGIN

@interface VMDisplayMetalViewController : UIViewController<UTMVirtualMachineDelegate, UIGestureRecognizerDelegate> {
    NSMutableArray<UIKeyCommand *> *_keyCommands;
}

@property (nonatomic, strong) UTMVirtualMachine *vm;
@property (nonatomic, readwrite) BOOL prefersStatusBarHidden;
@property (weak, nonatomic) IBOutlet MTKView *mtkView;
@property (weak, nonatomic) IBOutlet VMKeyboardView *keyboardView;
@property (strong, nonatomic) IBOutlet UIInputView *inputAccessoryView;
@property (strong, nonatomic) IBOutlet UIView *toolbarAccessoryView;
@property (strong, nonatomic) UISelectionFeedbackGenerator *clickFeedbackGenerator;
@property (strong, nonatomic) UIImpactFeedbackGenerator *resizeFeedbackGenerator;
@property (nonatomic, assign) BOOL lastDisplayChangeResize;
@property (weak, nonatomic) IBOutlet UIButton *pauseResumeButton;
@property (weak, nonatomic) IBOutlet UIButton *zoomButton;
@property (weak, nonatomic) IBOutlet UIVisualEffectView *placeholderView;
@property (weak, nonatomic) IBOutlet UIImageView *placeholderImageView;
@property (weak, nonatomic) IBOutlet UIActivityIndicatorView *placeholderIndicator;
@property (weak, nonatomic) IBOutlet UIButton *resumeBigButton;
@property (strong, nonatomic) IBOutletCollection(VMKeyboardButton) NSArray *customKeyButtons;
@property (strong, nonatomic) IBOutletCollection(VMKeyboardButton) NSArray *customKeyModifierButtons;
@property (nonatomic, readonly) BOOL serverModeCursor;
@property (nonatomic, readonly) BOOL touchscreen;

- (void)sendExtendedKey:(SendKeyType)type code:(int)code;

- (CGPoint)clipCursorToDisplay:(CGPoint)pos;
- (CGPoint)moveMouseAbsolute:(CGPoint)location;
- (CGPoint)moveMouseRelative:(CGPoint)translation;

- (IBAction)gesturePan:(UIPanGestureRecognizer *)sender;
- (IBAction)gestureTwoPan:(UIPanGestureRecognizer *)sender;
- (IBAction)gestureTap:(UITapGestureRecognizer *)sender;
- (IBAction)gestureTwoTap:(UITapGestureRecognizer *)sender;
- (IBAction)gestureLongPress:(UILongPressGestureRecognizer *)sender;
- (IBAction)gesturePinch:(UIPinchGestureRecognizer *)sender;
- (IBAction)gestureSwipeUp:(UISwipeGestureRecognizer *)sender;
- (IBAction)gestureSwipeDown:(UISwipeGestureRecognizer *)sender;
- (IBAction)gestureSwipeScroll:(UISwipeGestureRecognizer *)sender;
- (IBAction)changeDisplayZoom:(UIButton *)sender;
- (IBAction)pauseResumePressed:(UIButton *)sender;
- (IBAction)powerPressed:(UIButton *)sender;
- (IBAction)showKeyboardButton:(UIButton *)sender;
- (IBAction)hideToolbarButton:(UIButton *)sender;

@end

NS_ASSUME_NONNULL_END
