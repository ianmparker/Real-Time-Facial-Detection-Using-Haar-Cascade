#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/objdetect.hpp>
#include <iostream>

using namespace cv;
using namespace std;

// /////////////////  Real-Time Facial Detection Using a Webcam ////////////////

void main() {

	// Create a VideoCapture object and open the camera for video capturing
	VideoCapture cap(0);

	// Create a Mat object to store the video frames
	Mat img;

	// Create an object of CascadeClassifier
	CascadeClassifier faceCascade;

	// Load the Haar cascade XML file for detecting faces
	faceCascade.load("Resources/haarcascade_frontalface_default.xml");

	// Check if the XML file is loaded properly
	if (faceCascade.empty()) {
		cout << "XML file not loaded" << endl;
	}

	// Start an infinite loop
	while (true) {

		// Read the current frame from the video capture object and store it in the Mat object
		cap.read(img);

		// Create a vector to store the detected faces
		vector<Rect> faces;

		// Detect faces in the image and store them in the vector
		faceCascade.detectMultiScale(img, faces, 1.1, 10);

		// Loop through all the detected faces
		for (int i = 0; i < faces.size(); i++)
		{
			// Draw a rectangle around each face
			rectangle(img, faces[i].tl(), faces[i].br(), Scalar(255, 0, 255), 3);
		}

		// Display the current frame with rectangles around detected faces
		imshow("Image", img);

		// Wait for 1 millisecond between each frame
		waitKey(1);
	}
}


/////////////////  Facial Detection Using an Image     //////////////////////

//void main() {
//
//	// Define the path to the image file
//	string path = "Resources/TheGoat.png";
//
//	// Read the image file from the specified path
//	Mat img = imread(path);
//
//	// Create an object of CascadeClassifier
//	CascadeClassifier faceCascade;
//
//	// Load the Haar cascade XML file for detecting faces
//	faceCascade.load("Resources/haarcascade_frontalface_default.xml");
//
//	// Check if the XML file is loaded properly
//	if (faceCascade.empty()) {
//		cout << "XML file not loaded" << endl;
//	}
//
//	// Create a vector to store the detected faces
//	vector<Rect> faces;
//
//	// Detect faces in the image and store them in the vector
//	faceCascade.detectMultiScale(img, faces, 1.1, 10);
//
//	// Loop through all the detected faces
//	for (int i = 0; i < faces.size(); i++)
//	{
//		// Draw a rectangle around each face
//		rectangle(img, faces[i].tl(), faces[i].br(), Scalar(255, 0, 255), 3);
//	}
//
//	// Display the image with rectangles around detected faces
//	imshow("Image", img);
//
//	// Wait for any key press to close the displayed image
//	waitKey(0);
//}




