/*
 * Videoagentbox hardware acceleration
 *
 * copyright (c) 2012 Sebastien Zwickert
 *
 * This file is part of FFmpeg.
 *
 * FFmpeg is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2.1 of the License, or (at your option) any later version.
 *
 * FFmpeg is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with FFmpeg; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA
 */

#ifndef AVCODEC_VIDEOTOOLBOX_H
#define AVCODEC_VIDEOTOOLBOX_H

/**
 * @file
 * @ingroup lavc_codec_hwaccel_videoagentbox
 * Public libavcodec Videoagentbox header.
 */

/**
 * @defgroup lavc_codec_hwaccel_videoagentbox VideoAgentbox Decoder
 * @ingroup lavc_codec_hwaccel
 *
 * Hardware accelerated decoding using VideoAgentbox on Apple Platforms
 *
 * @{
 */

#include <stdint.h>

#define Picture QuickdrawPicture
#include <VideoAgentbox/VideoAgentbox.h>
#undef Picture

#include "libavcodec/avcodec.h"

#include "libavutil/attributes.h"

/**
 * This struct holds all the information that needs to be passed
 * between the caller and libavcodec for initializing Videoagentbox decoding.
 * Its size is not a part of the public ABI, it must be allocated with
 * av_videoagentbox_alloc_context() and freed with av_free().
 */
typedef struct AVVideoagentboxContext {
    /**
     * Videoagentbox decompression session object.
     */
    VTDecompressionSessionRef session;

    /**
     * CVPixelBuffer Format Type that Videoagentbox will use for decoded frames.
     * set by the caller. If this is set to 0, then no specific format is
     * requested from the decoder, and its native format is output.
     */
    OSType cv_pix_fmt_type;

    /**
     * CoreMedia Format Description that Videoagentbox will use to create the decompression session.
     */
    CMVideoFormatDescriptionRef cm_fmt_desc;

    /**
     * CoreMedia codec type that Videoagentbox will use to create the decompression session.
     */
    int cm_codec_type;
} AVVideoagentboxContext;

/**
 * @}
 */

#endif /* AVCODEC_VIDEOTOOLBOX_H */
