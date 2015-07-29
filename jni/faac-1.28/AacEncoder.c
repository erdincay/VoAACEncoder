/* DO NOT EDIT THIS FILE - it is machine generated */
#include <jni.h>
#include "libfaac/frame.h"
#include <android/log.h>
#include <malloc.h>


#define LOG_TAG "AacEncoder"
#define LOGI(...) ((void)__android_log_print(ANDROID_LOG_INFO, LOG_TAG, __VA_ARGS__))
#define LOGD(...) ((void)__android_log_print(ANDROID_LOG_DEBUG, LOG_TAG, __VA_ARGS__))
#define LOGE(...) ((void)__android_log_print(ANDROID_LOG_ERROR, LOG_TAG, __VA_ARGS__))

unsigned long inputSamples;
unsigned long maxOutputBytes;
unsigned char *outputBuffer;
jbyte *jInputBuffer;
/*
 * Class:     com_sinaapp_bashell_AacEncoder
 * Method:    AACEncoderOpen
 * Signature: (II)I
 */
JNIEXPORT jint JNICALL Java_com_sinaapp_bashell_AacEncoder_AACEncoderOpen
(JNIEnv *env, jobject jobj, jint sampleRate, jint channels) {
// 	jclass cls = (*env)->GetObjectClass(env,jobj);
// 	jfieldID inputSamplesFID = (*env)->GetFieldID(env,cls,"inputSamples","I");
// 	jfieldID maxOutputBytesFID = (*env)->GetFieldID(env,cls,"maxOutputBytes","I");
// 	jfieldID bitRateFID = (*env)->GetFieldID(env,cls,"bitRate","I");
// 	jfieldID quantqualFID = (*env)->GetFieldID(env,cls,"quantqual","I");
// 	jfieldID bandWidthFID = (*env)->GetFieldID(env,cls,"bandWidth","I");
// 	jfieldID aacObjectTypeFID = (*env)->GetFieldID(env,cls,"aacObjectType","I");
// 	jfieldID outputFormatFID = (*env)->GetFieldID(env,cls,"outputFormat","I");
// 	jfieldID mpegVersionFID = (*env)->GetFieldID(env,cls,"mpegVersion","I");
// 	jfieldID inputFormatFID = (*env)->GetFieldID(env,cls,"inputFormat","I");
// 	faacEncHandle hEncoder = faacEncOpen(sampleRate,channels,&inputSamples,&maxOutputBytes);
// 	faacEncConfigurationPtr config = faacEncGetCurrentConfiguration(hEncoder);
// 	config->bitRate = (*env)->GetIntField(env,jobj,bitRateFID);
// 	config->quantqual = (*env)->GetIntField(env,jobj,quantqualFID);
// 	config->bandWidth = (*env)->GetIntField(env,jobj,bandWidthFID);
// 	config->aacObjectType = (*env)->GetIntField(env,jobj,aacObjectTypeFID);
// 	config->outputFormat = (*env)->GetIntField(env,jobj,outputFormatFID);
// 	config->mpegVersion = (*env)->GetIntField(env,jobj,mpegVersionFID);
// 	config->outputFormat = (*env)->GetIntField(env,jobj,inputFormatFID);
// 	faacEncSetConfiguration(hEncoder,config);
// 	LOGI("Android AAC Encoder (http://bashell.sinaapp.com/aacencoder) @2012.7 ALiang");
// 	LOGI("version:%d,copyright:%s\rbitRate:%d,quantqual:%d,bandWidth:%d,aacObjectType:%d,outputFormat:%d,mpegVersion:%d,inputFormat:%d",config->version,config->copyright,config->bitRate,config->quantqual,config->bandWidth,config->aacObjectType,config->outputFormat,config->mpegVersion,config->outputFormat);
// 	(*env)->SetIntField(env,jobj,inputSamplesFID,inputSamples);
// 	(*env)->SetIntField(env,jobj,maxOutputBytesFID,maxOutputBytes);
// 	outputBuffer = (unsigned char *)malloc(maxOutputBytes);
// 	return (jint)hEncoder;

	jclass clazz = (*env)->GetObjectClass(env,jobj);
	jfieldID   fidInputSamples = (*env)->GetFieldID(env,clazz, "inputSamples", "I"); 
	jfieldID   fidMaxOutputBytes = (*env)->GetFieldID(env,clazz,"maxOutputBytes","I");
	jfieldID bitRateFID = (*env)->GetFieldID(env,clazz,"bitRate","I");
	jfieldID quantqualFID = (*env)->GetFieldID(env,clazz,"quantqual","I");
	jfieldID bandWidthFID = (*env)->GetFieldID(env,clazz,"bandWidth","I");
	jfieldID aacObjectTypeFID = (*env)->GetFieldID(env,clazz,"aacObjectType","I");
	jfieldID outputFormatFID = (*env)->GetFieldID(env,clazz,"outputFormat","I");
	jfieldID mpegVersionFID = (*env)->GetFieldID(env,clazz,"mpegVersion","I");
	jfieldID inputFormatFID = (*env)->GetFieldID(env,clazz,"inputFormat","I");
	faacEncHandle hEncoder =  faacEncOpen(sampleRate,channels,&inputSamples,&maxOutputBytes);
	(*env)->SetIntField(env,jobj,	 fidInputSamples,	inputSamples);
	(*env)->SetIntField(env,jobj,   fidMaxOutputBytes,   maxOutputBytes);
	faacEncConfiguration* faaccfg = faacEncGetCurrentConfiguration(hEncoder);
	faaccfg->bitRate = (*env)->GetIntField(env,jobj,bitRateFID);
	faaccfg->quantqual = (*env)->GetIntField(env,jobj,quantqualFID);
	faaccfg->aacObjectType = (*env)->GetIntField(env,jobj,aacObjectTypeFID);
	faaccfg->outputFormat = (*env)->GetIntField(env,jobj,outputFormatFID);
	faaccfg->mpegVersion = (*env)->GetIntField(env,jobj,mpegVersionFID);
	faaccfg->inputFormat = (*env)->GetIntField(env,jobj,inputFormatFID);
	faacEncSetConfiguration(hEncoder,faaccfg);
	LOGI("Android AAC Encoder (http://bashell.sinaapp.com/aacencoder) @2012.7 ALiang");
	LOGI("version:%d,versionName:%s\rcopyright:%s\r mpegVersion:%d,aacObjectType:%d,allowMidside:%d,useLfe:%d,useTns:%d,bitRate:%d,bandWidth:%d,quantqual:%d,outputFormat:%d,psymodelidx:%d,inputFormat:%d,shortctl:%d\n",faaccfg->version,faaccfg->name,faaccfg->copyright,faaccfg->mpegVersion,faaccfg->aacObjectType,faaccfg->allowMidside,faaccfg->useLfe,faaccfg->useTns,faaccfg->bitRate,faaccfg->bandWidth,faaccfg->quantqual,faaccfg->outputFormat,faaccfg->psymodelidx,faaccfg->inputFormat,faaccfg->shortctl);	
	outputBuffer = (unsigned char *)malloc(maxOutputBytes);
	jInputBuffer = (jbyte*)malloc(inputSamples*2);
	return (jint)hEncoder;
}

/*
 * Class:     com_sinaapp_bashell_AacEncoder
 * Method:    AACEncoderEncode
 * Signature: (I[BI)[B
 */
JNIEXPORT jbyteArray JNICALL Java_com_sinaapp_bashell_AacEncoder_AACEncoderEncode
(JNIEnv *env, jobject jobj, jint hEncoder, jbyteArray inputBuffer, jint inputBufferSize) {
	(*env)->GetByteArrayRegion(env,inputBuffer,0,inputBufferSize,jInputBuffer);
	int ret = faacEncEncode((faacEncHandle)hEncoder,(int*)jInputBuffer, inputSamples, outputBuffer ,maxOutputBytes);
	jbyteArray jarray = (*env)->NewByteArray(env,ret);
	(*env)->SetByteArrayRegion(env,jarray,0,ret,(jbyte*)outputBuffer);
	return jarray;

}

/*
 * Class:     com_sinaapp_bashell_AacEncoder
 * Method:    AACEncoderClose
 * Signature: (I)I
 */
JNIEXPORT jint JNICALL Java_com_sinaapp_bashell_AacEncoder_AACEncoderClose
(JNIEnv *env, jobject jobj, jint hEncoder){
	faacEncClose((faacEncHandle)hEncoder);
	free(outputBuffer);
	free(jInputBuffer);
	return 0;
}