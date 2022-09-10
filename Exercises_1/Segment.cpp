#include <stdio.h>
#include <opencv2/opencv.hpp>
#include <iostream>

#include <windows.h>

using namespace cv;

#define c_blue 0
#define c_green 1
#define c_red 2

int main(int argc, char** argv )
{
    if ( argc != 2 )
    {
        printf("You must provide the path to the image argument\n");
        return -1;
    }

    Mat image;
    image = imread( argv[1], 1 );

    if ( !image.data )
    {
        printf("No image data \n");
        return -1;
    }

    printf("Image you provided:\n");
    namedWindow("Display Image", cv::WINDOW_AUTOSIZE );
    imshow("Display Image", image);
    waitKey(0);
    destroyAllWindows();
    Mat segmentedImage = image.clone(); 

    float desired_redness_ratio = -2.0f;
    while(desired_redness_ratio != -1.0f){
      printf("Input either redness factor or -1 to quit:\n");
      std::cin >> desired_redness_ratio;
      
      segmentedImage = image.clone();
      for(int i = 0; i < segmentedImage.rows; i++){             //for() looping through all original rows
        for(int j = 0; j < segmentedImage.cols; j++){           //for() looping through all original columns
          uint px_red = (segmentedImage.at<cv::Vec3b>(i,j)[c_red]);
          uint px_green = (segmentedImage.at<cv::Vec3b>(i,j)[c_green]);
          uint px_blue = (segmentedImage.at<cv::Vec3b>(i,j)[c_blue]);
          float redness_ratio = ((float)px_red/((float)(px_red + px_green + px_blue)/3));

          if(redness_ratio < desired_redness_ratio){            //if() This pixel is not much more red than it is green or blue,
            for(char channel = 0U; channel < 3; channel++){     //remove the pixel from the image
              segmentedImage.at<cv::Vec3b>(i,j)[channel] = 0U;
            }
          }
        }
      }
      //Display the image
      printf("Segmented Image:\n");
      namedWindow("Display Image", cv::WINDOW_AUTOSIZE );
      imshow("Display Image", segmentedImage);
      waitKey(0);
      destroyAllWindows();
    }
    return 0;
}
