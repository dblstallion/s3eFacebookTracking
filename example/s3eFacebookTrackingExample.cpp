#include "s3eOSReadString.h"
#include "s3eFacebookTracking.h"
#include "IwDebug.h"
#include "IwGx.h"
#include "s3eExt.h"
#include "s3ePointer.h"
#include "s3eFile.h"
#include "s3eSurface.h"
#include <string>
#include <sstream>

int32 activateApp(void*, void*)
{
    IW_CALLSTACK("activateApp");

    if (s3eFacebookTrackingAvailable())
    {
        s3eDebugOutputString("Tracking App Activate");
        s3eFBAppEventsActivateApp("607826462593297");
    }
    else
    {
        s3eDebugOutputString("Can't load Facebook");
        s3eDebugOutputString(s3eExtGetErrorString());
    }

    return 0;
}

// Example showing how to use the s3eWwise extension
int main()
{
    IW_CALLSTACK("main");

    s3eDebugOutputString("Booting Facebook Tracking example");

    activateApp(NULL, NULL);
    s3eDeviceRegister(S3E_DEVICE_UNPAUSE, activateApp, NULL);

    IwGxInit();

    IwGxSetColClear(0, 0, 0, 0xff);

    while(!s3eDeviceCheckQuitRequest())
    {
        std::stringstream str;

        IwGxClear();

        IwGxPrintString(100, 100, "s3eFacebookTracking");

        IwGxFlush();
        IwGxSwapBuffers();
        s3eDeviceYield(0);
    }

    IwGxTerminate();

    s3eDeviceUnRegister(S3E_DEVICE_UNPAUSE, activateApp);

    return 0;
}