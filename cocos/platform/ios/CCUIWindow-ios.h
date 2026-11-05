/****************************************************************************
 BingoBoom – UIScene-aware window helpers (iOS 13+).

 With the UIScene life cycle (mandatory for apps built with the iOS 27 SDK)
 the app delegate no longer owns a window and -[UIApplication windows] /
 -[UIApplication keyWindow] are deprecated. Use these helpers to find the
 window / view controller to present UI from.

 Header-only; safe to include from both ARC and MRC Objective-C(++) files.
 ****************************************************************************/
#pragma once

#import <UIKit/UIKit.h>

// Foreground-active window scene; falls back to any foreground-inactive one,
// then to the first connected window scene.
static inline UIWindowScene* CCGetActiveWindowScene(void)
{
    UIWindowScene* inactive = nil;
    UIWindowScene* any = nil;
    for (UIScene* scene in [UIApplication sharedApplication].connectedScenes)
    {
        if (![scene isKindOfClass:[UIWindowScene class]])
            continue;
        UIWindowScene* ws = (UIWindowScene*)scene;
        if (ws.activationState == UISceneActivationStateForegroundActive)
            return ws;
        if (!inactive && ws.activationState == UISceneActivationStateForegroundInactive)
            inactive = ws;
        if (!any)
            any = ws;
    }
    return inactive ? inactive : any;
}

// Key window of the active scene (or its first window).
static inline UIWindow* CCGetKeyWindow(void)
{
    UIWindowScene* ws = CCGetActiveWindowScene();
    if (!ws)
        return nil;
    UIWindow* key = ws.keyWindow; // iOS 15+
    return key ? key : ws.windows.firstObject;
}

// Top-most presented view controller of the key window – use it to present
// alerts, share sheets, etc.
static inline UIViewController* CCGetTopViewController(void)
{
    UIViewController* vc = CCGetKeyWindow().rootViewController;
    while (vc.presentedViewController)
        vc = vc.presentedViewController;
    return vc;
}
