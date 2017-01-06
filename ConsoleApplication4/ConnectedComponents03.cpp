//#include <iostream>
//#include <opencv2/core/utility.hpp>
//#include "opencv2/imgproc.hpp"
//#include "opencv2/imgcodecs.hpp"
//#include "opencv2/highgui.hpp"
//#include <opencv2/opencv.hpp>
//#include <math.h>
//#include <fstream>
//
//using namespace cv;
//using namespace std;
//
//const std::string keys =
//"{help      |             | print this message    }"
//"{@image    |contours     | load image            }"
//"{j         |j.png        | j image        }"
//"{contours  |contours.png | contours image        }"
//;
//
//int threshval = 60;
//int bw_constant = 128;
//
//int main(int argc, char *argv[])
//{
//	ofstream myConnectedComponents03file;
//	myConnectedComponents03file.open("myConnectedComponents03file.txt");
//
//	cv::CommandLineParser parser(argc, argv, keys);
//	parser.about("");
//	if (parser.has("help")) {
//		parser.printMessage();
//		return 0;
//	}
//
//	cv::Mat srcImg;
//	std::string file = parser.get<std::string>(0);
//	if (file == "j") {
//		file = parser.get<std::string>("j");
//	}
//	else if (file == "contours") {
//		file = parser.get<std::string>("contours");
//	}
//	srcImg = cv::imread("20161215 02.33_368L.jpg", CV_LOAD_IMAGE_UNCHANGED);
//	if (srcImg.empty()) {
//		return -1;
//	}
//
//	//Apply bilateral filter
//	Mat srcImg11;
//	bilateralFilter(srcImg, srcImg11, 15, 80, 80);
//	imshow("source", srcImg);
//	imshow("bilateralFilter result", srcImg11);
//	//Apply median filter
//	Mat srcImg22;
//	blur(srcImg, srcImg22, Size(5, 5), Point(-1, -1));
//	imshow("median filter result", srcImg22);
//
//	cv::Mat grayImg;
//	cv::Mat grayImg11;
//	cv::Mat grayImg22;
//	cv::cvtColor(srcImg, grayImg, cv::COLOR_BGR2GRAY);
//	cv::cvtColor(srcImg11, grayImg11, cv::COLOR_BGR2GRAY);
//	cv::cvtColor(srcImg22, grayImg22, cv::COLOR_BGR2GRAY);
//
//	cv::Mat binaryImg = threshval < 128 ? (grayImg < threshval) : (grayImg > threshval);
//	cv::Mat binaryImg11 = threshval < 128 ? (grayImg11 < threshval) : (grayImg11 > threshval);
//	cv::Mat binaryImg22 = threshval < 128 ? (grayImg22 < threshval) : (grayImg22 > threshval);
//	cv::Mat labelImage, labelImage11,labelImage22;
//	cv::Mat stats,stats11, centroids, centroids11, stats22, centroids22;
//	//    int nLabels = cv::connectedComponents(bw, labelImage, 8);
//	int nLabels = cv::connectedComponentsWithStats(binaryImg, labelImage, stats, centroids, 8, CV_32S);
//	int nLabels11 = cv::connectedComponentsWithStats(binaryImg11, labelImage11, stats11, centroids11, 8, CV_32S);
//	int nLabels22 = cv::connectedComponentsWithStats(binaryImg22, labelImage22, stats22, centroids22, 8, CV_32S);
//	std::vector<cv::Vec3b> colors(nLabels);
//	std::vector<cv::Vec3b> colors11(nLabels11);
//	std::vector<cv::Vec3b> colors22(nLabels22);
//	colors[0] = cv::Vec3b(0, 0, 0);
//	colors11[0] = cv::Vec3b(0, 0, 0);
//	colors22[0] = cv::Vec3b(0, 0, 0);
//	myConnectedComponents03file << "Number of connected components = " << nLabels << std::endl << std::endl;
//	myConnectedComponents03file << "(11) Number of connected components = " << nLabels11 << std::endl << std::endl;
//	myConnectedComponents03file << "(22) Number of connected components = " << nLabels22 << std::endl << std::endl;
//
//	for (int label = 1; label < nLabels; ++label) {
//		colors[label] = cv::Vec3b((std::rand() & 255), (std::rand() & 255), (std::rand() & 255));
//		myConnectedComponents03file << "Component " << label << std::endl;
//		myConnectedComponents03file << "CC_STAT_LEFT   = " << stats.at<int>(label, cv::CC_STAT_LEFT) << std::endl;
//		myConnectedComponents03file << "CC_STAT_TOP    = " << stats.at<int>(label, cv::CC_STAT_TOP) << std::endl;
//		myConnectedComponents03file << "CC_STAT_WIDTH  = " << stats.at<int>(label, cv::CC_STAT_WIDTH) << std::endl;
//		myConnectedComponents03file << "CC_STAT_HEIGHT = " << stats.at<int>(label, cv::CC_STAT_HEIGHT) << std::endl;
//		myConnectedComponents03file << "CC_STAT_AREA   = " << stats.at<int>(label, cv::CC_STAT_AREA) << std::endl;
//		myConnectedComponents03file << "CENTER   = (" << centroids.at<double>(label, 0) << "," << centroids.at<double>(label, 1) << ")" << std::endl << std::endl;
//	}
//	for (int label11 = 1; label11 < nLabels11; ++label11) {
//		colors11[label11] = cv::Vec3b((std::rand() & 255), (std::rand() & 255), (std::rand() & 255));
///*		myConnectedComponents03file << "Component " << label11 << std::endl;
//		myConnectedComponents03file << "CC_STAT_LEFT   = " << stats.at<int>(label, cv::CC_STAT_LEFT) << std::endl;
//		myConnectedComponents03file << "CC_STAT_TOP    = " << stats.at<int>(label, cv::CC_STAT_TOP) << std::endl;
//		myConnectedComponents03file << "CC_STAT_WIDTH  = " << stats.at<int>(label, cv::CC_STAT_WIDTH) << std::endl;
//		myConnectedComponents03file << "CC_STAT_HEIGHT = " << stats.at<int>(label, cv::CC_STAT_HEIGHT) << std::endl;
//		myConnectedComponents03file << "CC_STAT_AREA   = " << stats.at<int>(label, cv::CC_STAT_AREA) << std::endl;
//		myConnectedComponents03file << "CENTER   = (" << centroids.at<double>(label, 0) << "," << centroids.at<double>(label, 1) << ")" << std::endl << std::endl;*/
//	}
//	for (int label22 = 1; label22 < nLabels22; ++label22) {
//		colors22[label22] = cv::Vec3b((std::rand() & 255), (std::rand() & 255), (std::rand() & 255));
//	}
//	cv::Mat dst(grayImg.size(), CV_8UC3);
//	for (int r = 0; r < dst.rows; ++r) {
//		for (int c = 0; c < dst.cols; ++c) {
//			int label = labelImage.at<int>(r, c);
//			cv::Vec3b &pixel = dst.at<cv::Vec3b>(r, c);
//			pixel = colors[label];
//		}
//	}
//	cv::Mat dst11(grayImg11.size(), CV_8UC3);
//	for (int r = 0; r < dst11.rows; ++r) {
//		for (int c = 0; c < dst11.cols; ++c) {
//			int label11 = labelImage11.at<int>(r, c);
//			cv::Vec3b &pixel11 = dst11.at<cv::Vec3b>(r, c);
//			pixel11 = colors11[label11];
//		}
//	}
//	cv::Mat dst22(grayImg22.size(), CV_8UC3);
//	for (int r = 0; r < dst22.rows; ++r) {
//		for (int c = 0; c < dst22.cols; ++c) {
//			int label22 = labelImage22.at<int>(r, c);
//			cv::Vec3b &pixel22 = dst22.at<cv::Vec3b>(r, c);
//			pixel22 = colors22[label22];
//		}
//	}
//	//cv::imshow("Source", srcImg);
//	//cv::imshow("B&W" , binaryImg);
//	cv::imshow("Connected Components", dst);
//	//cv::imshow("Source11", dst11);
//	//cv::imshow("B&W11", binaryImg11);
//	cv::imshow("bilateralFilter Connected Components", dst11);
//	cv::imshow("median filter Connected Components", dst11);
//	myConnectedComponents03file.close();
//
//	waitKey(0);
//
//
//	return 0;
//}