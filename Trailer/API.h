//
//  API.h
//  Trailer
//
//  Created by Paul Tsochantaris on 20/09/2013.
//  Copyright (c) 2013 HouseTrip. All rights reserved.
//

#define API_SERVER @"api.github.com"

#define RATE_UPDATE_NOTIFICATION @"RateUpdateNotification"
#define RATE_UPDATE_NOTIFICATION_LIMIT_KEY @"RateUpdateNotificationLimit"
#define RATE_UPDATE_NOTIFICATION_REMAINING_KEY @"RateUpdateNotificationRemaining"

#define NETWORK_TIMEOUT 60.0

@interface API : NSObject

@property (nonatomic) NSString *authToken, *localUser, *localUserId, *resetDate;
@property (nonatomic) NSInteger sortMethod;
@property (nonatomic) float refreshPeriod;
@property (nonatomic) Reachability *reachability;
@property (nonatomic) BOOL shouldHideUncommentedRequests, showCommentsEverywhere, sortDescending, showCreatedInsteadOfUpdated, dontKeepMyPrs, hideAvatars;

- (void) fetchRepositoriesAndCallback:(void(^)(BOOL success))callback;

- (void) fetchPullRequestsForActiveReposAndCallback:(void(^)(BOOL success))callback;

- (void) getRateLimitAndCallback:(void(^)(long long remaining, long long limit, long long reset))callback;

- (NSOperation *)getImage:(NSString *)path
				  success:(void(^)(NSHTTPURLResponse *response, NSImage *image))successCallback
				  failure:(void(^)(NSHTTPURLResponse *response, NSError *error))failureCallback;

@end
