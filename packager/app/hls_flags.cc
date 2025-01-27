// Copyright 2016 Google Inc. All rights reserved.
//
// Use of this source code is governed by a BSD-style
// license that can be found in the LICENSE file or at
// https://developers.google.com/open-source/licenses/bsd

#include "packager/app/hls_flags.h"

#include <limits>

DEFINE_string(hls_master_playlist_output,
              "",
              "Output path for the master playlist for HLS. This flag must be"
              "used to output HLS.");
DEFINE_string(hls_base_url,
              "",
              "The base URL for the Media Playlists and media files listed in "
              "the playlists. This is the prefix for the files.");
DEFINE_string(hls_key_uri,
              "",
              "The key uri for 'identity' and 'com.apple.streamingkeydelivery' "
              "key formats. Ignored if the playlist is not encrypted or not "
              "using the above key formats.");
DEFINE_string(hls_playlist_type,
              "VOD",
              "VOD, EVENT, or LIVE. This defines the EXT-X-PLAYLIST-TYPE in "
              "the HLS specification. For hls_playlist_type of LIVE, "
              "EXT-X-PLAYLIST-TYPE tag is omitted.");
DEFINE_int32(hls_media_sequence_number,
              0,
              "Number. This HLS-only parameter defines the initial "
              "EXT-X-MEDIA-SEQUENCE value, which allows continuous media "
              "sequence across packager restarts. See #691 for more "
              "information about the reasoning of this and its use cases.");
DEFINE_double(hls_start_time_offset,
              std::numeric_limits<double>::lowest(),
              "Floating-point number. Sets EXT-X-START on the media playlists "
              "to specify the preferred point at wich the player should start "
              "playing. A positive number indicates a time offset from the "
              "beginning of the playlist. A negative number indicates a "
              "negative time offset from the end of the last media segment "
              "in the playlist.");