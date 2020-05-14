#include "StudentPreProcessing.h"

unsigned char StudentPreProcessing::Max(const unsigned char &a, const unsigned char &b, const unsigned char &c) const {
	int max = (a < b) ? b : a;
	return ((max < c) ? c : max);
}

unsigned char StudentPreProcessing::Min(const unsigned char &a, const unsigned char &b, const unsigned char &c) const {
	int min = (a < b) ? a : b;
	return ((min < c) ? min : c);
}


IntensityImage * StudentPreProcessing::stepToIntensityImage(const RGBImage &image) const {

	// Intensity image aanmaken
	IntensityImageStudent * tempIntensityImage;

	tempIntensityImage->set(image.getWidth(), image.getHeight());

	switch (currentMethod)
	{
		case method::desaturation:
			for (unsigned int i = 0; i < image.getWidth() * image.getHeight(); ++i) {

				tempIntensityImage->setPixel(i, 
					(Max(image.getPixel(i).r, image.getPixel(i).g, image.getPixel(i).b) +
					 Min(image.getPixel(i).r, image.getPixel(i).g, image.getPixel(i).b)) / 2
				);
			}

			break;

		case method::luminosity:
			for (unsigned int i = 0; i < image.getWidth() * image.getHeight(); ++i) {

			}
			break;

	}

	return tempIntensityImage; //  Return intensity image als output
}

IntensityImage * StudentPreProcessing::stepScaleImage(const IntensityImage &image) const {
	return nullptr;
}

IntensityImage * StudentPreProcessing::stepEdgeDetection(const IntensityImage &image) const {
	return nullptr;
}

IntensityImage * StudentPreProcessing::stepThresholding(const IntensityImage &image) const {
	return nullptr;
}