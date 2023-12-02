#include "PSmile.h"
#include <iostream>

JNIEXPORT void JNICALL Java_pSmile_PSmile_init
  (JNIEnv* env, jobject obj, jint w, jint h)
{
	CPSmile* smile = new CPSmile();
	jclass cls;
	jfieldID fid;

	cls = env->GetObjectClass(obj);
	fid = env->GetFieldID(cls, "ptr", "J");
	env->SetLongField(obj, fid, (jlong) smile);
}

JNIEXPORT jfloat JNICALL Java_pSmile_PSmile_findSmile
  (JNIEnv* env, jobject obj, jfloatArray arr, jint w, jint h)
{
	CPSmile* smile;
	jclass cls;
	jfieldID fid;
	jboolean isCopy;
	jfloat result;

	cls = env->GetObjectClass(obj);
	fid = env->GetFieldID(cls, "ptr", "J");
	smile = (CPSmile *) env->GetLongField(obj, fid);
	jfloat* myPtr;
	myPtr = env->GetFloatArrayElements(arr, &isCopy);
	result = smile->getSmile(myPtr, w, h);
	env->ReleaseFloatArrayElements(arr, myPtr, 0);
	return result;
}
