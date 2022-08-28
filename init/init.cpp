/*
 * Copyright (C) 2020 The LineageOS Project
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#include <cstdlib>
#include <cstring>
#include <sys/sysinfo.h>
#include <vector>

#include <android-base/properties.h>
#define _REALLY_INCLUDE_SYS__SYSTEM_PROPERTIES_H_
#include <sys/_system_properties.h>

#include "init_common.h"
#include "vendor_init.h"

using android::base::GetProperty;

std::vector<std::string> ro_props_default_source_order = {
    "",
    "odm.",
    "product.",
    "system.",
    "vendor.",
    "system_ext.",
};

void set_ro_build_prop(const std::string &source, const std::string &prop,
        const std::string &value, bool product = false) {
    std::string prop_name;

    if (product) {
        prop_name = "ro.product." + source + prop;
    } else {
        prop_name = "ro." + source + "build." + prop;
    }

    property_override(prop_name.c_str(), value.c_str(), false);
}

void set_device_props(const std::string fingerprint, const std::string description,
        const std::string brand, const std::string device, const std::string model) {
    for (const auto &source : ro_props_default_source_order) {
        set_ro_build_prop(source, "fingerprint", fingerprint);
        set_ro_build_prop(source, "brand", brand, true);
        set_ro_build_prop(source, "device", device, true);
        set_ro_build_prop(source, "model", model, true);
    }

    property_override("ro.build.fingerprint", fingerprint.c_str());
    property_override("ro.build.description", description.c_str());
}

void load_device_properties() {
    std::string hwname = GetProperty("ro.boot.hwname", "");
    std::string region = GetProperty("ro.boot.hwc", "");

    if (hwname == "curtana") {
        if (region == "Global_TWO") {
            set_device_props(
                    "Redmi/curtana_global/curtana:12/RKQ1.211019.001/V13.0.2.0.SJWMIXM:user/release-keys",
                    "curtana_global-user 12 RKQ1.211019.001 V13.0.2.0.SJWMIXM release-keys",
                    "Redmi", "curtana", "Redmi Note 9S");
        } else if (region == "Global_PA") {
            set_device_props(
                    "Redmi/curtana_global/curtana:12/RKQ1.211019.001/V13.0.2.0.SJWMIXM:user/release-keys",
                    "curtana_global-user 12 RKQ1.211019.001 V13.0.2.0.SJWMIXM release-keys",
                    "Redmi", "curtana", "Redmi Note 9S");
        } else if (region == "India") {
            set_device_props(
                    "Redmi/curtana/curtana:11/RKQ1.200826.002/V12.5.5.0.RJWINXM:user/release-keys",
                    "curtana_in-user 11 RKQ1.200826.002 V12.5.5.0.RJWINXM release-keys",
                    "Redmi", "curtana", "Redmi Note 9 Pro");
        } else if (region == "Japan") {
            set_device_props(
                    "Redmi/curtana_global/curtana:12/RKQ1.211019.001/V13.0.2.0.SJWMIXM:user/release-keys",
                    "curtana_global-user 12 RKQ1.211019.001 V13.0.2.0.SJWMIXM release-keys",
                    "Redmi", "curtana", "Redmi Note 9S");
        }
    } else if (hwname == "excalibur") {
        set_device_props(
                "Redmi/excalibur_in/excalibur:11/RKQ1.200826.002/V12.5.6.0.RJXINXM:user/release-keys",
                "excalibur_in-user 11 RKQ1.200826.002 V12.5.6.0.RJXINXM release-keys",
                "Redmi", "excalibur", "Redmi Note 9 Pro Max");
    } else if (hwname == "gram") {
        set_device_props(
                "POCO/gram_in/gram:11/RKQ1.200826.002/V12.5.6.0.RJPINXM:user/release-keys",
                "gram_in-user 11 RKQ1.200826.002 V12.5.6.0.RJPINXM release-keys",
                "POCO", "gram", "POCO M2 Pro");
    } else if (hwname == "joyeuse") {
        set_device_props(
                "Redmi/joyeuse_global/joyeuse:11/RKQ1.200826.002/V12.5.7.0.RJZMIXM:user/release-keys",
                "joyeuse_global-user 11 RKQ1.200826.002 V12.5.7.0.RJZMIXM release-keys",
                "Redmi", "joyeuse", "Redmi Note 9 Pro");
    }
}

void vendor_load_properties() {
    load_common_properties();
    load_device_properties();
}
