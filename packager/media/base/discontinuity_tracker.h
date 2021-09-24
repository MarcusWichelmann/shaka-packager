// Copyright 2017 Google Inc. All rights reserved.
//
// Use of this source code is governed by a BSD-style
// license that can be found in the LICENSE file or at
// https://developers.google.com/open-source/licenses/bsd

#ifndef PACKAGER_MEDIA_BASE_DISCONTINUITY_TRACKER_H_
#define PACKAGER_MEDIA_BASE_DISCONTINUITY_TRACKER_H_

#include <memory>

#include "packager/base/synchronization/lock.h"
#include "packager/media/base/timestamp.h"

namespace shaka {
namespace media {

const int32_t kThrottleThresholdMs = 1000;

class DiscontinuityTracker {
 public:
  DiscontinuityTracker() = default;
  virtual ~DiscontinuityTracker() = default;

  void TrackDecoderConfigChange(int64_t pts, int32_t time_scale);

  int64_t GetLastDiscontinuity();

 private:
  base::Lock lock_;

  int64_t last_discontinuity_pts_ = kNoTimestamp;
};

}  // namespace media
}  // namespace shaka

#endif  // PACKAGER_MEDIA_BASE_DISCONTINUITY_TRACKER_H_
