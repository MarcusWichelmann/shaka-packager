// Copyright 2017 Google Inc. All rights reserved.
//
// Use of this source code is governed by a BSD-style
// license that can be found in the LICENSE file or at
// https://developers.google.com/open-source/licenses/bsd

#include "packager/base/logging.h"
#include "packager/media/base/discontinuity_tracker.h"

namespace shaka {
namespace media {

void DiscontinuityTracker::TrackDecoderConfigChange(int64_t dts) {
  LOG(INFO) << "Tracking discontinuity on dts " << dts;
}

}  // namespace media
}  // namespace shaka
