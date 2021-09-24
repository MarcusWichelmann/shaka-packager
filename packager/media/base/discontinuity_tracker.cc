// Copyright 2017 Google Inc. All rights reserved.
//
// Use of this source code is governed by a BSD-style
// license that can be found in the LICENSE file or at
// https://developers.google.com/open-source/licenses/bsd

#include "packager/base/logging.h"
#include "packager/media/base/discontinuity_tracker.h"

namespace shaka {
namespace media {

void DiscontinuityTracker::TrackDecoderConfigChange(int64_t pts, int32_t time_scale) {
  base::AutoLock auto_lock(lock_);

  if (pts <= last_discontinuity_pts_ + (time_scale / 1000 * kThrottleThresholdMs)) {
    return;
  }

  LOG(INFO) << "Tracking discontinuity at pts " << pts;
  last_discontinuity_pts_ = pts;
}

int64_t DiscontinuityTracker::GetLastDiscontinuity() {
  base::AutoLock auto_lock(lock_);
  return last_discontinuity_pts_;
}

}  // namespace media
}  // namespace shaka
