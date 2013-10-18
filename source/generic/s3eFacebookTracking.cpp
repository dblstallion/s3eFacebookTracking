/*
Generic implementation of the s3eFacebookTracking extension.
This file should perform any platform-indepedentent functionality
(e.g. error checking) before calling platform-dependent implementations.
*/

/*
 * NOTE: This file was originally written by the extension builder, but will not
 * be overwritten (unless --force is specified) and is intended to be modified.
 */


#include "s3eFacebookTracking_internal.h"
s3eResult s3eFacebookTrackingInit()
{
    //Add any generic initialisation code here
    return s3eFacebookTrackingInit_platform();
}

void s3eFacebookTrackingTerminate()
{
    //Add any generic termination code here
    s3eFacebookTrackingTerminate_platform();
}

void s3eFBAppEventsActivateApp(const char* appId)
{
	s3eFBAppEventsActivateApp_platform(appId);
}
