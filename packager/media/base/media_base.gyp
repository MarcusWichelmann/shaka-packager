# Copyright 2014 Google Inc. All rights reserved.
#
# Use of this source code is governed by a BSD-style
# license that can be found in the LICENSE file or at
# https://developers.google.com/open-source/licenses/bsd

{
  'variables': {
    'shaka_code': 1,
  },
  'targets': [
    {
      'target_name': 'media_base',
      'type': '<(component)',
      'sources': [
        'aes_cryptor.cc',
        'aes_cryptor.h',
        'aes_decryptor.cc',
        'aes_decryptor.h',
        'aes_encryptor.cc',
        'aes_encryptor.h',
        'aes_pattern_cryptor.cc',
        'aes_pattern_cryptor.h',
        'audio_stream_info.cc',
        'audio_stream_info.h',
        'audio_timestamp_helper.cc',
        'audio_timestamp_helper.h',
        'bit_reader.cc',
        'bit_reader.h',
        'bit_writer.cc',
        'bit_writer.h',
        'buffer_reader.cc',
        'buffer_reader.h',
        'buffer_writer.cc',
        'buffer_writer.h',
        'byte_queue.cc',
        'byte_queue.h',
        'cc_stream_filter.cc',
        'cc_stream_filter.h',
        'closure_thread.cc',
        'closure_thread.h',
        'common_pssh_generator.cc',
        'common_pssh_generator.h',
        'container_names.cc',
        'container_names.h',
        'decrypt_config.cc',
        'decrypt_config.h',
        'decryptor_source.cc',
        'decryptor_source.h',
        'discontinuity_tracker.cc',
        'discontinuity_tracker.h',
        'encryption_config.h',
        'fourccs.h',
        'http_key_fetcher.cc',
        'http_key_fetcher.h',
        'id3_tag.cc',
        'id3_tag.h',
        'key_fetcher.cc',
        'key_fetcher.h',
        'key_source.cc',
        'key_source.h',
        'language_utils.cc',
        'language_utils.h',
        'limits.h',
        'macros.h',
        'media_handler.cc',
        'media_handler.h',
        'media_parser.cc',
        'media_parser.h',
        'media_sample.cc',
        'media_sample.h',
        'muxer.cc',
        'muxer.h',
        'muxer_options.cc',
        'muxer_options.h',
        'muxer_util.cc',
        'muxer_util.h',
        'network_util.cc',
        'network_util.h',
        'offset_byte_queue.cc',
        'offset_byte_queue.h',
        'playready_key_source.cc',
        'playready_key_source.h',
        'playready_pssh_generator.cc',
        'playready_pssh_generator.h',
        'producer_consumer_queue.h',
        'protection_system_ids.h',
        'protection_system_specific_info.cc',
        'protection_system_specific_info.h',
        'proto_json_util.cc',
        'proto_json_util.h',
        'pssh_generator.cc',
        'pssh_generator.h',
        'pssh_generator_util.cc',
        'pssh_generator_util.h',
        'range.h',
        'raw_key_source.cc',
        'raw_key_source.h',
        'rcheck.h',
        'request_signer.cc',
        'request_signer.h',
        'rsa_key.cc',
        'rsa_key.h',
        'stream_info.cc',
        'stream_info.h',
        'text_muxer.cc',
        'text_muxer.h',
        'text_sample.cc',
        'text_sample.h',
        'text_stream_info.cc',
        'text_stream_info.h',
        'text_track.h',
        'text_track_config.cc',
        'text_track_config.h',
        'timestamp.h',
        'video_stream_info.cc',
        'video_stream_info.h',
        'video_util.cc',
        'video_util.h',
        'widevine_key_source.cc',
        'widevine_key_source.h',
        'widevine_pssh_generator.cc',
        'widevine_pssh_generator.h'
      ],
      'dependencies': [
        'widevine_common_encryption_proto',
        'widevine_pssh_data_proto',
        '../../base/base.gyp:base',
        '../../packager.gyp:status',
        '../../third_party/boringssl/boringssl.gyp:boringssl',
        '../../third_party/curl/curl.gyp:libcurl',
        '../../third_party/gflags/gflags.gyp:gflags',
        '../../third_party/libxml/libxml.gyp:libxml',
        '../../version/version.gyp:version',
      ],
    },
    {
      'target_name': 'widevine_pssh_data_proto',
      'type': '<(component)',
      'sources': ['widevine_pssh_data.proto'],
      'variables': {
        'proto_in_dir': '.',
        'proto_out_dir': 'packager/media/base',
      },
      'includes': [
        '../../protoc.gypi',
      ],
    },
    {
      'target_name': 'widevine_common_encryption_proto',
      'type': '<(component)',
      'sources': ['widevine_common_encryption.proto'],
      'variables': {
        'proto_in_dir': '.',
        'proto_out_dir': 'packager/media/base',
      },
      'includes': [
        '../../protoc.gypi',
      ],
    },
    {
      'target_name': 'media_handler_test_base',
      'type': '<(component)',
      'sources': [
        'media_handler_test_base.cc',
        'media_handler_test_base.h',
      ],
      'dependencies': [
        '../../testing/gmock.gyp:gmock',
        '../../testing/gtest.gyp:gtest',
      ],
    },
    {
      'target_name': 'media_base_unittest',
      'type': '<(gtest_target_type)',
      'sources': [
        'aes_cryptor_unittest.cc',
        'aes_pattern_cryptor_unittest.cc',
        'audio_timestamp_helper_unittest.cc',
        'bit_reader_unittest.cc',
        'bit_writer_unittest.cc',
        'buffer_writer_unittest.cc',
        'closure_thread_unittest.cc',
        'container_names_unittest.cc',
        'decryptor_source_unittest.cc',
        'http_key_fetcher_unittest.cc',
        'id3_tag_unittest.cc',
        'muxer_util_unittest.cc',
        'offset_byte_queue_unittest.cc',
        'producer_consumer_queue_unittest.cc',
        'protection_system_specific_info_unittest.cc',
        'pssh_generator_unittest.cc',
        'raw_key_source_unittest.cc',
        'rsa_key_unittest.cc',
        'status_test_util_unittest.cc',
        'test/fake_prng.cc',  # For rsa_key_unittest
        'test/fake_prng.h',   # For rsa_key_unittest
        'test/rsa_test_data.cc',  # For rsa_key_unittest
        'test/rsa_test_data.h',   # For rsa_key_unittest
        'video_util_unittest.cc',
        'widevine_key_source_unittest.cc',
      ],
      'dependencies': [
        '../../file/file.gyp:file',
        '../../testing/gmock.gyp:gmock',
        '../../testing/gtest.gyp:gtest',
        '../../third_party/boringssl/boringssl.gyp:boringssl',
        '../test/media_test.gyp:media_test_support',
        'media_base',
      ],
    },
  ],
}
