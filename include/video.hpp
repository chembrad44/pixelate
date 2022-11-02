/**
 * Copyright (c) 2015-2022 Brad Bahls.  All Rights Reserved.
 * Unauthorized copying of this file by any medium is strictly prohibited
 * Proprietary and confidential
 *
 * Video class
 * Date: 11-17-2015
 * Author: Brad Bahls (chembrad@msn.com)
 */

#ifndef __VIDEO_HPP__
#define __VIDEO_HPP__

#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/videoio/videoio.hpp>

namespace cvbb
{
    class Video;
}

class cvbb::Video
{
private:
    std::string _videoSource;
    cv::VideoCapture _videoCapture;
    cv::Mat _frame;

public:
    Video(
        const std::string videoSource
        )
    {
        _videoSource = videoSource;
    }

    bool connect()
    {
		if (_videoSource == "webcam")
		{
			_videoCapture.open(0);
	    }
		else
		{
			_videoCapture.open(_videoSource);
		}

        return _videoCapture.isOpened();
    }

    bool get_frame_into(cv::Mat &frame)
    {
        if (!_videoCapture.read(frame))
        {
            return false;
        }
        return true;
    }
};

#endif /* __VIDEO_HPP__ */
