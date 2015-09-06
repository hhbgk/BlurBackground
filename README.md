# BlurBackground
A fast and simple blurring background for Android. This is based on [ImageBlurring.](https://github.com/qiujuer/ImageBlurring)

## NDK build in Android Studio
1.Add NDK path to project local.properties<br />

    ndk.dir=~/Library/Android/android-ndk-r10

2.Declare native code to java file <br />

    public static native void blurIntArray(int[] pImg, int w, int h, int r);
    public static native void blurBitMap(Bitmap bitmap, int r);

    static {
        System.loadLibrary("ImageBlur");
    }

3.Open terminal and 'cd' to ../src/main, then input the command below:<br >

    javah -d jni -classpath ~/Library/Android/sdk/platforms/android-22/android.jar:~/AndroidStudioProjects/MyApplication/app/build/intermediates/classes/debug com.example.android.ImageBlur
  A new file 'com_example_android_ImageBlur.h' will be there.
  
4.Add C/C++ files to ../src/main/jni

5.Add some NDK configrations to build.gradle under the module,like:<br />

    defaultConfig {
        applicationId "com.example.android"
        minSdkVersion 15
        targetSdkVersion 22
        versionCode 1
        versionName "1.0"

        ndk{
            moduleName "ImageBlur"
            cFlags "-DANDROID_NDK -D_RELEASE"
            ldLibs "m", "log", "jnigraphics"
            abiFilters "armeabi", "armeabi-v7a"
        }
    }

Finally, just run the project.

## Screenshots

![test](blurringbackground.png)
