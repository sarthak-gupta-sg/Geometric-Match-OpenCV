//***********************************************************************
// Project		    : GeoMatch
// Author           : Shiju P K
// Email			: shijupk@gmail.com
// Created          : 10-01-2010
//
// File Name		: GeoMatch.h
// Last Modified By : Shiju P K
// Last Modified On : 13-07-2010
// Description      : class to implement edge based template matching
//
// Copyright        : (c) . All rights reserved.
//***********************************************************************

#pragma once
#include <opencv2/core.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/imgproc.hpp>

#include <opencv2/highgui.hpp>
#include <math.h>

using namespace cv;

class GeoMatch
{
private:
	int				noOfCordinates;		//Number of elements in coordinate array
	Point			*cordinates;		//Coordinates array to store model points	
	int				modelHeight;		//Template height
	int				modelWidth;			//Template width
	double			*edgeMagnitude;		//gradient magnitude
	double			*edgeDerivativeX;	//gradient in X direction
	double			*edgeDerivativeY;	//radient in Y direction	
	Point			centerOfGravity;	//Center of gravity of template 
	
	bool			modelDefined;
	
	void CreateDoubleMatrix(double **&matrix, Size size);
	void ReleaseDoubleMatrix(double **&matrix, int size);
public:
	GeoMatch(void);
	GeoMatch(const void* templateArr);
	~GeoMatch(void);

	int CreateGeoMatchModel(Mat templateArr, double, double);
	double FindGeoMatchModel(Mat srcarr, double minScore, double greediness, Point * resultPoint);
	void DrawContours(Mat pImage, Point COG, Scalar, int);
	void DrawContours(Mat pImage, Scalar, int);
};
