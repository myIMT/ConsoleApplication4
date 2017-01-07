#include "opencv2/core/core.hpp"
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include "iostream"
using namespace cv;
using namespace std;
int main()
{		
	Mat image;
	Mat gray;				
	vector<vector<Point> > contours;
	vector<Vec4i> hierarchy;
	//namedWindow("Display window", CV_WINDOW_AUTOSIZE);
		
	for (int j = 1; j < 773; j++)
	{

		std::string s = std::to_string(j);
		image = imread("mask_i_" + s + ".jpg", 1);
		cout << "image file name= " << "mask_i_" + s + ".jpg" << "\n";

		cvtColor(image, gray, CV_BGR2GRAY);
		Canny(gray, gray, 100, 200, 3);
		/// Find contours   

		RNG rng(12345);
		findContours(gray, contours, hierarchy, CV_RETR_TREE, CV_CHAIN_APPROX_SIMPLE, Point(0, 0));
		/// Draw contours
		Mat drawing = Mat::zeros(gray.size(), CV_8UC3);
		for (int i = 0; i < contours.size(); i++)
		{
			Scalar color = Scalar(rng.uniform(0, 255), rng.uniform(0, 255), rng.uniform(0, 255));
			drawContours(drawing, contours, i, color, 2, 8, hierarchy, 0, Point());
		}

		imwrite("contour_" + s + ".jpg", drawing);
		//imshow("Result window", drawing);
		//imshow("Display window", image);
	}

		

	waitKey(0);
	return 0;
}







//#include "opencv2/core/core.hpp"
//#include "opencv2/highgui/highgui.hpp""
//#include "opencv2/imgproc/imgproc.hpp"
//#include "iostream"
//using namespace cv;
//using namespace std;
//int main()
//{
//	Mat src;
//	src = imread("mask_i.jpg", CV_LOAD_IMAGE_COLOR);
//	Mat gray;
//	cvtColor(src, gray, CV_BGR2GRAY);
//	threshold(gray, gray, 200, 255, THRESH_BINARY_INV); //Threshold the gray
//	imshow("gray", gray); int largest_area = 0;
//	int largest_contour_index = 0;
//	Rect bounding_rect;
//	vector<vector<Point>> contours; // Vector for storing contour
//	vector<Vec4i> hierarchy;
//	findContours(gray, contours, hierarchy, CV_RETR_CCOMP, CV_CHAIN_APPROX_SIMPLE);
//	// iterate through each contour.
//	for (int i = 0; i< contours.size(); i++)
//	{
//		//  Find the area of contour
//		double a = contourArea(contours[i], false);
//		std::string s = std::to_string(i);
//		string name = "contour-" + s;
//		cout << "name= " << name << "\n";
//		int myR = 255 - i;
//		int myG = i + i;
//		int myB = 10 * i;
//		Scalar color(myB, myG, myR);  // color of the contour in the
//		drawContours(src, contours, largest_contour_index, color, CV_FILLED, 8, hierarchy);
//		rectangle(src, bounding_rect, Scalar(0, 255, 0), 2, 8, 0);
//		//namedWindow(name, CV_WINDOW_AUTOSIZE);
//		imshow(name, src);
//		//imwrite(name + ".jpg", src);
//		if (a>largest_area) {
//			largest_area = a; cout << i << " area  " << a << endl;
//			// Store the index of largest contour
//			largest_contour_index = i;
//			// Find the bounding rectangle for biggest contour
//			bounding_rect = boundingRect(contours[i]);
//
//		}
//	}
//	//Scalar color(255, 255, 255);  // color of the contour in the
//	//							  //Draw the contour and rectangle
//	//drawContours(src, contours, largest_contour_index, color, CV_FILLED, 8, hierarchy);
//	//rectangle(src, bounding_rect, Scalar(0, 255, 0), 2, 8, 0);
//	//namedWindow("Display window", CV_WINDOW_AUTOSIZE);
//	//imshow("Display window", src);
//	waitKey(0);
//	return 0;
//}