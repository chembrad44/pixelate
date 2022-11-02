/**
 * Copyright (c) 2015-2018 Brad Bahls.  All Rights Reserved.
 * Unauthorized copying of this file by any medium is strictly prohibited
 * Proprietary and confidential
 *
 * Accepts an image and pixelates
 * Date: 11-15-2015
 * Author: Brad Bahls (chembrad@msn.com)
 */

// TODO: Color ranges.  I want to limit color counts in pixelated images.
// TODO: Background removal.


#include <stdlib.h>
#include <cstring>
#include <iostream>
#include <vector>

#include "cvbb.hpp"
#include "video.hpp"

#define HELP_TEXT \
"\n"\
"Copyright (c) 2015-2022 Brad Bahls.  All Rights Reserved.\n"\
"\n"\
"Imports an image or video from file or device and applies a pixelation\n"\
"filter.\n"\
"\n"\
"Usage: pixelate -f [FILE] [OPTIONS...]\n"\
"  -?, --help               Print this help text\n"\
"  -c, --cam                Use webcam\n"\
"  --debug                  Switch to debug mode\n"\
"  -f, --file               Image/Video file\n"\
"  --of, --out-file <file>  Save final image to file\n"\
"  -p, --palette            Color palette for image {ec, mc, c64, gb}\n"\
"  --rf, --resize           Image resize factor\n"\
"  --ss, --sub-size         Size of subset square\n"\
"\n"\
"Do not use '-f' and '-c' flags together!\n"\
"\n"\
"\n"

class pixelate_main
{
private:
    bool _showHelp;
    bool _debug;
    int _exitCode;
    std::string _file;
    std::string _outFile;
    unsigned int _subsetSize;
    float _resizeFactor;
    std::string _palette;

public:
    pixelate_main(int argc, char** argv)
    {
        _showHelp = false;
        _debug = false;
        _exitCode = 0;
        _file = "";
        _outFile = "";
        _subsetSize = 1;
        _resizeFactor = 1;
        _palette = "none";

        int argi;
        const char *pszArg;
        for (argi = 1; argi < argc; argi++)
        {
            pszArg = argv[argi];
            if (0 == strcmp("-?", pszArg)
                || 0 == strcmp("--help", pszArg)
                || 0 == strcmp("-h", pszArg)
               )
            {
                _showHelp = true;
            }
            else if (0 == strcmp("--debug", pszArg))
            {
                _debug = true;
            }
            else if (0 == strcmp("-f", pszArg)
                    || 0 == strcmp("--file", pszArg)
                    )
            {
                argi++;
                if (argi < argc)
                {
                    pszArg = argv[argi];
                    _file = pszArg;
                }
            }
            else if(0 == strcmp("--of", pszArg)
                    || 0 == strcmp("--out-file", pszArg)
                    || 0 == strcmp("--out", pszArg)
                    )
            {
                argi++;
                if (argi < argc)
                {
                    pszArg = argv[argi];
                    _outFile = pszArg;
                }

            }
            else if (0 == strcmp("-p", pszArg)
                    || 0 == strcmp("--palette", pszArg)
                    || 0 == strcmp("--color-palette", pszArg)
                    || 0 == strcmp("--cp", pszArg)
                    )
            {
                argi++;
                if (argi < argc)
                {
                    pszArg = argv[argi];
                    _palette = pszArg;
                }
            }
            else if (0 == strcmp("--resize", pszArg)
                    || 0 == strcmp("--resize-factor", pszArg)
                    || 0 == strcmp("--rf", pszArg)
                    )
            {
                argi++;
                if (argi < argc)
                {
                    pszArg = argv[argi];
                    _resizeFactor = atof(pszArg);
                }
            }
            else if (0 == strcmp("--ss", pszArg)
                    || 0 == strcmp("--sub-size", pszArg)
                    || 0 == strcmp("--subset-size", pszArg)
                    || 0 == strcmp("--sq-size", pszArg)
                    || 0 == strcmp("--square-size", pszArg)
                    )
            {
                argi++;
                if (argi < argc)
                {
                    pszArg = argv[argi];
                    _subsetSize = atoi(pszArg);
                }
            }
			else if (0 == strcmp("-c", pszArg)
					|| 0 == strcmp("--cam", pszArg)
					|| 0 == strcmp("--camera", pszArg)
					|| 0 == strcmp("--webcam", pszArg)
					)
			{
			    _file = "webcam";
			}
        }
    }

    void execute()
    {
        if (_showHelp)
        {
            std::cerr << HELP_TEXT << std::endl;
            exit(0);
        }
        else if (_file.empty())
        {
            std::cerr << std::endl;
            std::cerr << "You must supply a file name.  Exiting..." 
                << std::endl;
        }
        else
        {
            execute_into(
                 _debug
                ,_file
                ,_outFile
                ,_palette
                ,_resizeFactor
                ,_subsetSize
                );
        }
    }

    void execute_into(
         bool debug
        ,std::string file
        ,std::string outFile
        ,std::string palette
        ,float resizeFactor
        ,unsigned int subsetSize
        )
    {
		std::string fileExtension = file.substr(file.find_last_of(".") + 1);
		
		if (  fileExtension == "mp4"
		   || file == "webcam"
				)
		{
			std::cerr << "Video detected" << std::endl;
			
			cvbb::cam_capture();
			cvbb::Video vid(file);
			bool bVideoOpened = vid.connect();
			if (bVideoOpened)
			{
				while(1)
				{
					cvbb::Image image;
					vid.get_frame_into(image);
					int subSize = subsetSize;
					cvbb::Image resizedImage;
					cvbb::Image pixelatedImage = cvbb::create_image(image.size());
					cvbb::pixelate(image,pixelatedImage,palette,subSize);
					cvbb::resize(pixelatedImage,resizedImage,resizeFactor);
					cvbb::display(resizedImage,15,"TEST");
				}
			}
		}
		else if (  fileExtension == "jpg"
				|| fileExtension == "png"
				|| fileExtension == "gif"
				)
		{
			std::cerr << "Image detected" << std::endl;
			
			cvbb::Image image;
			cvbb::load_image_into(image,file);
			int subSize = subsetSize;
			cvbb::Image resizedImage;
			cvbb::Image pixelatedImage = cvbb::create_image(image.size());
			cvbb::pixelate(image,pixelatedImage,palette,subSize);
			cvbb::resize(pixelatedImage,resizedImage,resizeFactor);
			cvbb::display(resizedImage,0,"TEST");

            if (outFile != "")
            {
                cvbb::save_image_to(outFile, resizedImage);
            }
		}
	}

    int exit_code() const
    {
        return _exitCode;
    }
}; // /end class

int main(int argc, char** argv)
{
    pixelate_main exe(argc, argv);
    exe.execute();
    return exe.exit_code();
}
