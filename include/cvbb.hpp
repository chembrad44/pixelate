
/**
 * Copyright (c) 2015-2018 Brad Bahls.  All Rights Reserved.
 * Unauthorized copying of this file by any medium is strictly prohibited
 * Proprietary and confidential
 */

#ifndef __CVBB_HPP__
#define __CVBB_HPP__

#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/objdetect/objdetect.hpp>

namespace cvbb
{

typedef cv::Mat Image;
typedef cv::Size Size;

// Load an image from file into a cv::Mat.
bool load_image_into(
     Image &image
    ,std::string file
    );

// Save an image to file.
bool save_image_to(
     std::string file
    ,Image &image
    );

// Display an image using OpenCV's built-in ability for n-time.
void display(
     cvbb::Image &image
    ,int time
    ,std::string title
    );

cvbb::Image create_image(
     cvbb::Size size = cvbb::Size(0,0)
    ,int channels = 3
    );

// Pixelate the source image and set into the destination image.  Pixellation
// is performed by using (subSize x subSize) rectangles and retrieving the mean
// pixel value from the source rectangles.
void pixelate(
     cvbb::Image &src
    ,cvbb::Image &dst
    ,std::string palette
    ,int subSize
    );

// Resize the given image and return a new resized image.  The resize factor
// must be greater than zero.
void resize(
     cvbb::Image &image
    ,cvbb::Image &resizedImage
    ,float resizeFactor
    );

void cam_capture();

} // /namespace


#endif /* __CVBB_HPP__ */
