#include <stdio.h>
#include <opencv2/opencv.hpp>

#include <windows.h>

using namespace cv;

int main(int argc, char** argv )
{
    if ( argc != 2 )
    {
        printf("You must provide the path to the image as an argument.\n");
        return -1;
    }

    Mat image;
    image = imread( argv[1], 1 );

    if ( !image.data )
    {
        printf("No image data \n");
        return -1;
    }
    namedWindow("Display Image", cv::WINDOW_AUTOSIZE );
    imshow("Display Image", image);

    waitKey(0);

    return 0;
}
