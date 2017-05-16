LOCAL_PATH := $(call my-dir)

include $(CLEAR_VARS)

LOCAL_MODULE := cocos2dcpp_shared

LOCAL_MODULE_FILENAME := libcocos2dcpp

LOCAL_SRC_FILES := hellocpp/main.cpp \
                   ../../Classes/AppDelegate.cpp \
                   ../../Classes/DataType/MyRectangle.cpp \
                   ../../Classes/DataType/MySprite.cpp \
                   ../../Classes/DataType/MyRect.cpp \
                   ../../Classes/DataType/MyLabel.cpp \
                   ../../Classes/DataType/MyPoint.cpp \
                   ../../Classes/DataType/Queue.cpp \
                   ../../Classes/DataType/Timer.cpp \
                   ../../Classes/GameElement/Attackfield.cpp \
                   ../../Classes/GameElement/Bullet.cpp \
                   ../../Classes/GameElement/Blast.cpp \
                   ../../Classes/GameElement/HelpBar.cpp \
                   ../../Classes/GameElement/Map.cpp \
                   ../../Classes/GameElement/Mine.cpp \
                   ../../Classes/GameElement/Wall.cpp \
                   ../../Classes/GameElement/MainTarget.cpp \
                   ../../Classes/GameElement/ShootFire.cpp \
                   ../../Classes/GameElement/Enemy/Enemy.cpp \
                   ../../Classes/GameElement/Enemy/Runner.cpp \
                   ../../Classes/GameElement/Enemy/Tank.cpp \
                   ../../Classes/GameElement/Enemy/Plane.cpp \
                   ../../Classes/GameElement/Enemy/Flyer.cpp \
                   ../../Classes/GameElement/Tower/Tower.cpp \
                   ../../Classes/GameElement/Tower/Pillbox.cpp \
                   ../../Classes/GameElement/Tower/Rocket.cpp \
                   ../../Classes/GameElement/Tower/SmokeRocket.cpp \
                   ../../Classes/GameManager/PD.cpp \
                   ../../Classes/GameManager/RoundManager.cpp \
                   ../../Classes/GameManager/SpriteManager.cpp \
                   ../../Classes/GameManager/MathMethod.cpp \
                   ../../Classes/GameManager/GameManager.cpp \
                   ../../Classes/GameManager/ObjectManager.cpp \
                   ../../Classes/GameManager/Status.cpp \
                   ../../Classes/GameManager/ResourceManager.cpp \
                   ../../Classes/GameManager/CameraManager.cpp \
                   ../../Classes/GameManager/ProgressMananger.cpp \
                   ../../Classes/Scene/RoundSelectScene.cpp \
                   ../../Classes/Scene/GameScene.cpp \
                   ../../Classes/Scene/HelloWorldScene.cpp

LOCAL_C_INCLUDES := $(LOCAL_PATH)/../../Classes \
                   $(LOCAL_PATH)/../../Classes/DataType \
                   $(LOCAL_PATH)/../../Classes/GameElement \
                   $(LOCAL_PATH)/../../Classes/GameElement/Enemy \
                   $(LOCAL_PATH)/../../Classes/GameElement/Tower \
                   $(LOCAL_PATH)/../../Classes/GameManager \
                   $(LOCAL_PATH)/../../Classes/Scene \
 
LOCAL_WHOLE_STATIC_LIBRARIES += cocos2dx_static
LOCAL_WHOLE_STATIC_LIBRARIES += cocosdenshion_static
LOCAL_WHOLE_STATIC_LIBRARIES += box2d_static
LOCAL_WHOLE_STATIC_LIBRARIES += chipmunk_static
LOCAL_WHOLE_STATIC_LIBRARIES += cocos_extension_static

#APP_CFLAGS += -Wno-error=format-security 
#APP_CPPFLAGS += -Wno-error=format-security

include $(BUILD_SHARED_LIBRARY)

$(call import-module,cocos2dx)
$(call import-module,cocos2dx/platform/third_party/android/prebuilt/libcurl)
$(call import-module,CocosDenshion/android)
$(call import-module,extensions)
$(call import-module,external/Box2D)
$(call import-module,external/chipmunk)
