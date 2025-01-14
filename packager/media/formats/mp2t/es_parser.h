// Copyright 2014 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef PACKAGER_MEDIA_FORMATS_MP2T_ES_PARSER_H_
#define PACKAGER_MEDIA_FORMATS_MP2T_ES_PARSER_H_

#include <stdint.h>

#include "packager/base/callback.h"
#include "packager/media/base/discontinuity_tracker.h"

namespace shaka {
namespace media {

class MediaSample;
class StreamInfo;
class TextSample;

namespace mp2t {

class EsParser {
 public:
  typedef base::Callback<void(std::shared_ptr<StreamInfo>)> NewStreamInfoCB;
  typedef base::Callback<void(std::shared_ptr<MediaSample>)> EmitSampleCB;
  typedef base::Callback<void(std::shared_ptr<TextSample>)> EmitTextSampleCB;

  EsParser(uint32_t pid,
      std::shared_ptr<DiscontinuityTracker> discontinuity_tracker)
      : discontinuity_tracker_(discontinuity_tracker), 
        pid_(pid) {}
  virtual ~EsParser() {}

  // ES parsing.
  // Should use kNoTimestamp when a timestamp is not valid.
  virtual bool Parse(const uint8_t* buf,
                     int size,
                     int64_t pts,
                     int64_t dts) = 0;

  // Flush any pending buffer.
  virtual bool Flush() = 0;

  // Reset the state of the ES parser.
  virtual void Reset() = 0;

  uint32_t pid() { return pid_; }

 protected:
  std::shared_ptr<DiscontinuityTracker> discontinuity_tracker_;

 private:
  uint32_t pid_;
};

}  // namespace mp2t
}  // namespace media
}  // namespace shaka

#endif
