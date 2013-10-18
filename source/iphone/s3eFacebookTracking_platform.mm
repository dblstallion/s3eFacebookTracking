/*
 * iphone-specific implementation of the s3eFacebookTracking extension.
 * Add any platform-specific functionality here.
 */
/*
 * NOTE: This file was originally written by the extension builder, but will not
 * be overwritten (unless --force is specified) and is intended to be modified.
 */
#include "s3eFacebookTracking_internal.h"

#include "FBSettings.h"
#include "FBAppEvents.h"

s3eResult s3eFacebookTrackingInit_platform()
{
    // Add any platform-specific initialisation code here
    return S3E_RESULT_SUCCESS;
}

void s3eFacebookTrackingTerminate_platform()
{
    // Add any platform-specific termination code here
}

void s3eFBAppEventsActivateApp_platform(const char* appId)
{
    NSString *nsAppId = [[NSString alloc] initWithUTF8String:appId];
    [FBSettings setDefaultAppID:nsAppId];
    [FBAppEvents activateApp];
    [nsAppId release];
}
