/**
 * Copyright (c) 2015-2022 Brad Bahls.  All Rights Reserved.
 * Unauthorized copying of this file by any medium is strictly prohibited
 * Proprietary and confidential
 *
 * Function definitions for cvbb
 * Date: 11-15-2015
 * Author: Brad Bahls (chembrad@msn.com)
 */

#include <iostream>

#include "cvbb.hpp"
#include "palette.hpp"
#include "video.hpp"

namespace cvbb
{

void colorvec_to_scalar(
     ColorVec &clrv
    ,cv::Scalar &sc
    )
{
    sc[0] = clrv[2];
    sc[1] = clrv[1];
    sc[2] = clrv[0];
}

void scalar_to_colorvec(
     cv::Scalar &sc
    ,ColorVec &clrv
    )
{
    clrv[0] = sc[2];
    clrv[1] = sc[1];
    clrv[2] = sc[0];
}

double color_distance(
     ColorVec &clrv1
    ,ColorVec &clrv2
    )
{
    double dist = 0.0;

    dist = sqrt(
        (clrv1[0] - clrv2[0]) * (clrv1[0] - clrv2[0]) +
        (clrv1[1] - clrv2[1]) * (clrv1[1] - clrv2[1]) +
        (clrv1[2] - clrv2[2]) * (clrv1[2] - clrv2[2])
        );

    return dist;
}

unsigned int smallest_distance(
     ColorVec &vec1
    ,ColPal &palette
    )
{
    unsigned int palettePlace = 0;
    double smallestDist = 1000.0;
    double dist = 0.0;
    
    for (unsigned int i=0; i<palette.size(); i++)
    {
        dist = color_distance(vec1,palette[i]);

        if (dist < smallestDist)
        {
            smallestDist = dist;
            palettePlace = i;
        }
    }

    return palettePlace;
}

void round(
    cv::Scalar &sc
    )
{
    // Round to black.
    if (sc[0] < 10
        && sc[1] < 10 
        && sc[2] < 10 
        )
    {
        sc[0] = 0;
        sc[1] = 0;
        sc[2] = 0;
    }
}

bool load_image_into(
     Image &image
    ,std::string file
    )
{
    image = cv::imread(file);

    if (image.data)
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool save_image_to(
     std::string file
    ,Image &image
    )
{
    bool result = cv::imwrite(file, image);
    return result;
}
   

void display(
     cvbb::Image &image
    ,int time
    ,std::string title = "image"
    )
{
    if (image.data)
    {
        cv::imshow(title,image);
        cv::waitKey(time);
    }
}

cvbb::Image create_image(
	 cvbb::Size size
	,int channels
	)
{
    cvbb::Image image;
    if (channels == 3)
    {
        image = cv::Mat(size,CV_8UC3);
    }
    else
    {
        image = cv::Mat(size,CV_8UC1);
    }
    return image;
}

void pixelate(
     cvbb::Image &src
    ,cvbb::Image &dst
    ,std::string palette
    ,int subSize
    )
{
    Palette pal;

    if (palette == "ec")
    {
        ECPalette ep;
        pal = ep;
    }
    else if (palette == "gb")
    {
        GBPalette gb;
        pal = gb;
    }
    else if (palette == "mc")
    {
        MCPalette mc;
        pal = mc;
    }
    else if (palette == "c64")
    {
        C64Palette c64;
        pal = c64;
    }
    else if (palette == "ds")
    {
        DeepSleepPalette ds;
        pal = ds;
    }
    else
    {
        // Not a recognized palette; let's default to EC.
        ECPalette ep;
        pal = ep;
    }

    ColorVec clrvec(3);


    if (subSize > 0)
    {
        for (int i=0; i<src.rows; i+=subSize)
        {   
            for (int j=0; j<src.cols; j+=subSize)
            {   
                cv::Rect rect = cv::Rect(j,i,subSize,subSize) &
                    cv::Rect(0,0,src.cols,src.rows);

                cvbb::Image sub(dst,rect);
                cv::Scalar sc = cv::mean(src(rect));
                scalar_to_colorvec(sc,clrvec);
                unsigned int p = smallest_distance(clrvec,pal.Palette::palette);
                cv::Scalar newSc;
                colorvec_to_scalar(pal.Palette::palette[p],newSc);
                sub.setTo(newSc);
            }   
        }
    }
}

void resize(
     cvbb::Image &image
    ,cvbb::Image &resizedImage
    ,float resizeFactor
    )
{
    if (resizeFactor > 0)
    {
        cv::resize(
             image
            ,resizedImage
            ,cvbb::Size(
                 image.cols*resizeFactor
                ,image.rows*resizeFactor
                )   
            );
    }
}

void cam_capture()
{
}

} // /namespace
