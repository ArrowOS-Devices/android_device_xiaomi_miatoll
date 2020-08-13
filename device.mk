#
# Copyright (C) 2020 The LineageOS Project
#
# SPDX-License-Identifier: Apache-2.0
#

# Inherit from sm6250-common
$(call inherit-product, device/xiaomi/sm6250-common/common.mk)

# Inherit proprietary targets
$(call inherit-product-if-exists, vendor/xiaomi/miatoll/miatoll-vendor.mk)

# Soong namespaces
PRODUCT_SOONG_NAMESPACES += \
    $(LOCAL_PATH)

# Init scripts
PRODUCT_COPY_FILES += \
    $(LOCAL_PATH)/rootdir/etc/init.device.rc:$(TARGET_COPY_OUT_VENDOR)/etc/init/hw/init.device.rc

# Thermal
PRODUCT_COPY_FILES += \
    $(LOCAL_PATH)/thermal/thermal-engine-map.conf:$(TARGET_COPY_OUT_VENDOR)/etc/thermal-engine-map.conf \
    $(LOCAL_PATH)/thermal/thermal-engine-map-curtana.conf:$(TARGET_COPY_OUT_VENDOR)/etc/thermal-engine-map-curtana.conf \
    $(LOCAL_PATH)/thermal/thermal-engine-normal-curtana.conf:$(TARGET_COPY_OUT_VENDOR)/etc/thermal-engine-normal-curtana.conf \
    $(LOCAL_PATH)/thermal/thermal-engine-camera-curtana.conf:$(TARGET_COPY_OUT_VENDOR)/etc/thermal-engine-camera-curtana.conf \
    $(LOCAL_PATH)/thermal/thermal-engine-map-excalibur.conf:$(TARGET_COPY_OUT_VENDOR)/etc/thermal-engine-map-excalibur.conf \
    $(LOCAL_PATH)/thermal/thermal-engine-normal-excalibur.conf:$(TARGET_COPY_OUT_VENDOR)/etc/thermal-engine-normal-excalibur.conf \
    $(LOCAL_PATH)/thermal/thermal-engine-camera-excalibur.conf:$(TARGET_COPY_OUT_VENDOR)/etc/thermal-engine-camera-excalibur.conf \
    $(LOCAL_PATH)/thermal/thermal-engine-map-gram.conf:$(TARGET_COPY_OUT_VENDOR)/etc/thermal-engine-map-gram.conf \
    $(LOCAL_PATH)/thermal/thermal-engine-normal-gram.conf:$(TARGET_COPY_OUT_VENDOR)/etc/thermal-engine-normal-gram.conf \
    $(LOCAL_PATH)/thermal/thermal-engine-camera-gram.conf:$(TARGET_COPY_OUT_VENDOR)/etc/thermal-engine-camera-gram.conf \
    $(LOCAL_PATH)/thermal/thermal-engine-map-joyeuse.conf:$(TARGET_COPY_OUT_VENDOR)/etc/thermal-engine-map-joyeuse.conf \
    $(LOCAL_PATH)/thermal/thermal-engine-normal-joyeuse.conf:$(TARGET_COPY_OUT_VENDOR)/etc/thermal-engine-normal-joyeuse.conf \
    $(LOCAL_PATH)/thermal/thermal-engine-camera-joyeuse.conf:$(TARGET_COPY_OUT_VENDOR)/etc/thermal-engine-camera-joyeuse.conf
