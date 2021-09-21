// Copyright 2017 Google Inc. All rights reserved.
//
// Use of this source code is governed by a BSD-style
// license that can be found in the LICENSE file or at
// https://developers.google.com/open-source/licenses/bsd

#ifndef PACKAGER_MEDIA_BASE_DISCONTINUITY_TRACKER_H_
#define PACKAGER_MEDIA_BASE_DISCONTINUITY_TRACKER_H_

#include <memory>

namespace shaka {
namespace media {

class DiscontinuityTracker {
 public:
  DiscontinuityTracker() = default;
  virtual ~DiscontinuityTracker() = default;

  void TrackDecoderConfigChange(int64_t dts);
};

}  // namespace media
}  // namespace shaka

#endif  // PACKAGER_MEDIA_BASE_DISCONTINUITY_TRACKER_H_
