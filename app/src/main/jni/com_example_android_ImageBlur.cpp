#include "com_example_android_ImageBlur.h"
#include <ImageBlur.c>
#include <android/log.h>
#include <android/bitmap.h>

/*
 * Class:     com_example_android_ImageBlur
 * Method:    blurIntArray
 * Signature: ([IIII)V
 */
JNIEXPORT void JNICALL Java_com_example_android_ImageBlur_blurIntArray
 (JNIEnv *env, jclass obj, jintArray arrIn, jint w, jint h, jint r)
 {
 	jint *pix;
 	pix = env->GetIntArrayElements(arrIn, 0);
 	if (pix == NULL)
 		return;
 	//Start
 	pix = StackBlur(pix, w, h, r);
 	//End
 	//int size = w * h;
 	//jintArray result = env->NewIntArray(size);
 	//env->SetIntArrayRegion(result, 0, size, pix);
 	env->ReleaseIntArrayElements(arrIn, pix, 0);
 	//return result;
 }

/*
 * Class:     com_example_android_ImageBlur
 * Method:    blurBitMap
 * Signature: (Landroid/graphics/Bitmap;I)V
 */
JNIEXPORT void JNICALL Java_com_example_android_ImageBlur_blurBitMap
  (JNIEnv *env, jclass obj, jobject bitmapIn, jint r)
  {
  	AndroidBitmapInfo infoIn;
  	void* pixelsIn;
  	int ret;

  	// Get image info
  	if ((ret = AndroidBitmap_getInfo(env, bitmapIn, &infoIn)) < 0)
  		return;
  	// Check image
  	if (infoIn.format != ANDROID_BITMAP_FORMAT_RGBA_8888)
  		return;
  	// Lock all images
  	if ((ret = AndroidBitmap_lockPixels(env, bitmapIn, &pixelsIn)) < 0) {
  		//AndroidBitmap_lockPixels failed!
  	}
  	//height width
  	int h = infoIn.height;
  	int w = infoIn.width;

  	//Start
  	pixelsIn = StackBlur((int*)pixelsIn, w, h, r);
  	//End

  	// Unlocks everything
  	AndroidBitmap_unlockPixels(env, bitmapIn);
  }