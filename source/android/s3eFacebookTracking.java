/*
java implementation of the s3eFacebookTracking extension.

Add android-specific functionality here.

These functions are called via JNI from native code.
*/
/*
 * NOTE: This file was originally written by the extension builder, but will not
 * be overwritten (unless --force is specified) and is intended to be modified.
 */
import android.content.Context;

import com.ideaworks3d.marmalade.LoaderAPI;
import com.ideaworks3d.marmalade.LoaderActivity;

class s3eFacebookTracking
{
    public void s3eFBAppEventsActivateApp(String appId)
    {
        Context context = LoaderActivity.m_Activity;
        com.facebook.AppEventsLogger.activateApp(context, appId);
    }
}
