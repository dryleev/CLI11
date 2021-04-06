// Copyright (c) 2017-2020, University of Cincinnati, developed by Henry Schreiner
// under NSF AWARD 1414736 and by the respective contributors.
// All rights reserved.
//
// SPDX-License-Identifier: BSD-3-Clause

#include "app_helper.hpp"

TEST_CASE_METHOD(TApp, "True Bool Option", "[bool][flag]") {
    // Strings needed here due to MSVC 2015.
    auto param = GENERATE("true", "on", "True", "ON");
    bool value{false};  // Not used, but set just in case
    app.add_option("-b,--bool", value);
    args = {"--bool", param};
    run();
    CHECK(app.count("--bool") == 1u);
    CHECK(value);
}

TEST_CASE_METHOD(TApp, "False Bool Option", "[bool][flag]") {
    auto param = GENERATE("false", "off", "False", "OFF");

    bool value{true};  // Not used, but set just in case
    app.add_option("-b,--bool", value);
    args = {"--bool", param};
    run();
    CHECK(app.count("--bool") == 1u);
    CHECK_FALSE(value);
}
