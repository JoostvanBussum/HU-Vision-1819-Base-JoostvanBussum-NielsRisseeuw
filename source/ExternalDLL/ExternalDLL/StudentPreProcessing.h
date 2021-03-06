/*
* Copyright (c) 2015 DottedEye Designs, Alexander Hustinx, NeoTech Software, Rolf Smit - All Rights Reserved
* Unauthorized copying of this file, via any medium is strictly prohibited
* Proprietary and confidential
*/

#pragma once
#include "PreProcessing.h"
#include "IntensityImageStudent.h"
#include "ImageFactory.h"


class StudentPreProcessing : public PreProcessing {
private:
	enum method {desaturation, luminosity};
	method currentMethod = method::desaturation;

	unsigned char Max(const unsigned char &a, const unsigned char &b, const unsigned char &c) const;
	unsigned char Min(const unsigned char &a, const unsigned char &b, const unsigned char &c) const;

public:
	IntensityImage * stepToIntensityImage(const RGBImage &image) const;
	IntensityImage * stepScaleImage(const IntensityImage &image) const;
	IntensityImage * stepEdgeDetection(const IntensityImage &image) const;
	IntensityImage * stepThresholding(const IntensityImage &image) const;
};