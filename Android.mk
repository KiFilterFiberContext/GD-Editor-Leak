LOCAL_PATH := $(call my-dir)

include $(CLEAR_VARS)

LOCAL_MODULE          := cocos2dcpp
LOCAL_SRC_FILES := $(LOCAL_PATH)/lib/libcocos2dcpp.so
LOCAL_EXPORT_C_INCLUDES := $(LOCAL_PATH)/includes/cocos2d_x/

include $(PREBUILT_SHARED_LIBRARY)

include $(CLEAR_VARS)

LOCAL_MODULE := saber
LOCAL_C_INCLUDES := $(LOCAL_PATH)/include/ $(LOCAL_PATH)/include/core/ $(LOCAL_PATH)/include/cocos2d_x/ $(LOCAL_PATH)/include/gd/

LOCAL_SRC_FILES:= src/main.cpp
LOCAL_LDLIBS := -llog 
LOCAL_STATIC_LIBRARIES := cocos2dcpp

include $(BUILD_SHARED_LIBRARY)
