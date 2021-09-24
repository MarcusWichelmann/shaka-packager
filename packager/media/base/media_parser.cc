// Copyright 2014 Google Inc. All rights reserved.
//
// Use of this source code is governed by a BSD-style
// license that can be found in the LICENSE file or at
// https://developers.google.com/open-source/licenses/bsd

#include "packager/media/base/media_parser.h"

namespace shaka {
namespace media {

MediaParser::MediaParser(
    std::shared_ptr<DiscontinuityTracker> discontinuity_tracker)
    : discontinuity_tracker_(discontinuity_tracker) {}

}  // namespace media
}  // namespace shaka
