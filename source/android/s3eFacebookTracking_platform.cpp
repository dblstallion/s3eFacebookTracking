/*
 * android-specific implementation of the s3eFacebookTracking extension.
 * Add any platform-specific functionality here.
 */
/*
 * NOTE: This file was originally written by the extension builder, but will not
 * be overwritten (unless --force is specified) and is intended to be modified.
 */
#include "s3eFacebookTracking_internal.h"

#include "s3eEdk.h"
#include "s3eEdk_android.h"
#include <jni.h>
#include "IwDebug.h"

static jobject g_Obj;
static jmethodID g_s3eFBAppEventsActivateApp;

s3eResult s3eFacebookTrackingInit_platform()
{
    // Get the environment from the pointer
    JNIEnv* env = s3eEdkJNIGetEnv();
    jobject obj = NULL;
    jmethodID cons = NULL;

    // Get the extension class
    jclass cls = s3eEdkAndroidFindClass("s3eFacebookTracking");
    if (!cls)
        goto fail;

    // Get its constructor
    cons = env->GetMethodID(cls, "<init>", "()V");
    if (!cons)
        goto fail;

    // Construct the java class
    obj = env->NewObject(cls, cons);
    if (!obj)
        goto fail;

    // Get all the extension methods
    g_s3eFBAppEventsActivateApp = env->GetMethodID(cls, "s3eFBAppEventsActivateApp", "(Ljava/lang/String;)V");
    if (!g_s3eFBAppEventsActivateApp)
        goto fail;



    IwTrace(FACEBOOKTRACKING, ("FACEBOOKTRACKING init success"));
    g_Obj = env->NewGlobalRef(obj);
    env->DeleteLocalRef(obj);
    env->DeleteGlobalRef(cls);

    // Add any platform-specific initialisation code here
    return S3E_RESULT_SUCCESS;

fail:
    jthrowable exc = env->ExceptionOccurred();
    if (exc)
    {
        env->ExceptionDescribe();
        env->ExceptionClear();
        IwTrace(s3eFacebookTracking, ("One or more java methods could not be found"));
    }
    return S3E_RESULT_ERROR;

}

void s3eFacebookTrackingTerminate_platform()
{
    // Add any platform-specific termination code here
}

void s3eFBAppEventsActivateApp_platform(const char* appId)
{
    JNIEnv* env = s3eEdkJNIGetEnv();
    jstring appId_jstr = env->NewStringUTF(appId);
    env->CallVoidMethod(g_Obj, g_s3eFBAppEventsActivateApp, appId_jstr);
}
