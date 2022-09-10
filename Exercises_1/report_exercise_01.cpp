/* Report exercise 1 - Image datatypes
 *
 * Compute how many bytes are at minimum needed to store the following images
 * if no compression is used.
 *
 * a) - A single channel 8 bit unsigned integer image with dimensions 1024 x 768
 * Answer:
 *   1024 * 768 * 1 byte = 786432 bytes = 0.787 MB
 *
 * b) - A 3 channel 32 bit floating point image with dimensions 640 x 480.
 * Answer:
 *   640 * 480 * 4 bytes * 3 = 3686400 bytes = 3.687 MB
 *
 * c) - A 2 channel 16 bit signed integer image with dimensions 1280 x 720
 * Answer:
 *   1280 * 720 * 2 bytes * 2 =  3686400 bytes = 3.687 MB
 * 
 * 
 * Write how each of the three images can be initialized and filled with zeros
 * using the OpenCV4 C++ api. Each initialization must be done with a single
 * call to the cv::Mat constructor
 */

#include <opencv2/opencv.hpp>

//a)
cv::Mat imageA = cv::Mat(1024, 768, CV_8U, cv::Scalar(0));

//b)
cv::Mat imageB = cv::Mat(1280, 720, CV_32FC3, cv::Scalar(0.0,0.0,0.0));

//c)
#define CV_16SC2   CV_MAKETYPE(CV_16S,2)
cv::Mat imageB = cv::Mat(1280, 720, CV_16SC2, cv::Scalar(0,0));
