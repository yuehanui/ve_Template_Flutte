//
//  UIButton+BTDAdditions.h
//  Pods
//
//  Created by yanglinfeng on 2019/7/3.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

@interface UIButton (BTDAdditions)

- (void)btd_addActionBlockForTouchUpInside:(void(^)(__kindof UIButton *sender))block;

@end

NS_ASSUME_NONNULL_END
