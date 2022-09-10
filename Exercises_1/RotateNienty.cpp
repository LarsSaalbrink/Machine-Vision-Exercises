#include <stdio.h>
#include <opencv2/opencv.hpp>

#include <windows.h>

using namespace cv;

int main(int argc, char** argv )
{
    if ( argc != 3 )
    {
        printf("You must provide the path to the image and a rotation direction as arguments\n");
        return -1;
    }

    if(!((argv[2][1] == 'W') || (argv[2][1] == 'C'))){
      printf("%s",argv[2]);
      printf("Please input \"CW\" or \"CCW\" as second argument");
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

    //---Rotate the image 90 degrees CCW---  

      //Determine dimensions of the image you got
      printf("Rows: %d\n",image.rows);
      printf("Columns: %d\n",image.cols);

      //Declare a "Mat" object of the right dimensions (Flipping amount of rows and columns, same amount of channels)
      Mat rotatedImage(image.cols,image.rows,CV_8UC3);   //image.cols, image.rows, CV_8U);

      //Dimensions of the new image
      printf("Rows: %d\n",rotatedImage.rows);
      printf("Columns: %d\n",rotatedImage.cols);

      for(int i = 0; i < rotatedImage.rows; i++){          //for() looping through all original rows
        for(int j = 0; j < rotatedImage.cols; j++){        //for() looping through all original columns
          for(char channel = 0U; channel < 3; channel++){  //for() looping through all color channels
            //Assign pixel from orginal column,row to new row,column for this channel
            if(argv[2][1] == 'W'){  //Option to mirror the output during the process, to produce either CW or CCW output
              rotatedImage.at<cv::Vec3b>(i,(rotatedImage.cols-1)-j)[channel] = image.at<cv::Vec3b>(j,i)[channel];
            }
            else{
              rotatedImage.at<cv::Vec3b>(i,j)[channel] = image.at<cv::Vec3b>(j,i)[channel];
            }
          }
        }
      }
      
      //Display the image
      printf("Rotated Image:\n");
      namedWindow("Display Image", cv::WINDOW_AUTOSIZE );
      imshow("Display Image", rotatedImage);
      waitKey(0);

    return 0;
}
