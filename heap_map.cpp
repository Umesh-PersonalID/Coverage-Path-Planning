#include <iostream>
#include<opencv2/opencv.hpp>


using namespace cv;
using namespace std;

int main()
{
    // Load the image
    Mat img = imread("input_image.jpg");

    // Convert the image to HSV color space
    Mat hsv_img;
    cvtColor(img, hsv_img, COLOR_BGR2HSV);

    // Create a matrix of the same size as the image
    Mat heatmap = Mat::zeros(img.size(), CV_8UC1);

    // Assign intensity values based on color
    for (int i = 0; i < hsv_img.rows; i++) {
        for (int j = 0; j < hsv_img.cols; j++) {
            if (hsv_img.at<Vec3b>(i,j)[0] > 0 && hsv_img.at<Vec3b>(i,j)[0] < 20) {
                heatmap.at<uchar>(i,j) = 4;   // red
            }
            else if (hsv_img.at<Vec3b>(i,j)[0] >= 20 && hsv_img.at<Vec3b>(i,j)[0] < 40) {
                heatmap.at<uchar>(i,j) = 3;   // orange
            }
            else if (hsv_img.at<Vec3b>(i,j)[0] >= 40 && hsv_img.at<Vec3b>(i,j)[0] < 60) {
                heatmap.at<uchar>(i,j) = 2;   // yellow
            }
        }
    }

    // Define the grid parameters
    float grid_length = 10.0f;  // in meters
    float grid_breadth = 8.0f;  // in meters
    float cell_size = 0.5f;     // in meters

    // Resize the heatmap to the desired size
    Mat resized_heatmap;
    cv::resize(heatmap, resized_heatmap, Size(static_cast<int>(grid_breadth/cell_size), static_cast<int>(grid_length/cell_size)), 0, 0, INTER_LINEAR);

    // Generate the grid
    Mat grid = Mat::zeros(static_cast<int>(grid_length/cell_size), static_cast<int>(grid_breadth/cell_size), CV_8UC1);
    for (int i = 0; i < grid.rows; i++) {
        for (int j = 0; j < grid.cols; j++) {
            Mat cell_heatmap = resized_heatmap(Rect(j*cell_size/cell_size, i*cell_size/cell_size, cell_size/cell_size, cell_size/cell_size));
            grid.at<uchar>(i,j) = static_cast<uchar>(mean(cell_heatmap)[0]);
        }
    }

    // Display the grid
    cout << grid << endl;

    return 0;
}
