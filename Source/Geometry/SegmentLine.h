/*   Copyright (C) 2023 Lidia Ortega Alvarado, Alfonso Lopez Ruiz
*
*    This program is free software: you can redistribute it and/or modify
*    it under the terms of the GNU General Public License as published by
*    the Free Software Foundation, either version 3 of the License, or
*    (at your option) any later version.
*
*    This program is distributed in the hope that it will be useful,
*    but WITHOUT ANY WARRANTY; without even the implied warranty of
*    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
*    GNU General Public License for more details.
*
*    You should have received a copy of the GNU General Public License
*    along with this program.  If not, see https://github.com/AlfonsoLRz/AG2223.
*/

#pragma once

/* 
 * File:   SegmentLIne.h
 * Author: lidia
 *
 * Created on 17 de enero de 2021, 17:49
 */

#include "Point.h"
#include "Vect2d.h"

class Line;
class RayLine; 

class SegmentLine 
{    
	friend class DrawSegment;        

protected:      
    Point	_orig, _dest; 

protected:
    /**
    *	@brief Returns the parametric value T0 to calculate the distance between a point and any geometric object like lines, segments or raylines.
    */
    float getDistanceT0(Vect2d& point);
    
	/**
	*	@brief Obstaints the parameters t and s where both lines intersects, if they do.
	*/
    bool intersects(const Point& p1,const Point& p2, float& s, float& t);

public:    
    /**
	*	@brief Default constructor.
	*/
	SegmentLine();

	/**
	*	@brief Constructor.
	*/
	SegmentLine(const Point& a, const Point& b);   
        
    /**
	*	@brief Copy constructor.
	*/
	SegmentLine(const SegmentLine& segment);
               
	/**
	*	@brief Constructor.
	*/
	SegmentLine(double ax, double ay, double bx, double by);

	/**
	*	@brief Destructor.
	*/
	virtual ~SegmentLine();
  
	/**
	*	@brief Returns the origin of the segment.
	*/
	Point getA() const{ return _orig; }

	/**
	*	@brief Returns the end of the segment.
	*/
	Point getB() const{ return _dest; }

	/**
	*	@brief Returns the constant of the equation of the implied line: c = y-mx.
	*/
	double getC();
        
    /**
	*	@brief Checks if a segment is different to this one.
	*/
	bool distinct(SegmentLine& segment);
      
	/**
	*	@brief Distance from a point defined by 'vector' to this segment.
	*/
	float distPointSegment(Point& vector);

	/**
	*	@brief Checks if a segment is equal to this one.
	*/
	bool equal(SegmentLine& segment);

	/**
	*	@brief It obtains the point belonging to the segment or colineal to it for a concrete t in the parametric equation: result = a + t (b-a).
	*/
	Point getPoint(double t);

	/**
	*	@brief Determines whether two segments intersect improperly, that is, when one end of a segment is contained in the other. Use integer arithmetic.
	*/
	bool impSegmentIntersection(SegmentLine& segment);

	/**
	*	@brief Determines whether a segment is horizontal or not (using EPSILON).
	*/
	bool isHorizontal();   
	
	/**
	*	@brief Determines whether or not a segment is vertical (using EPSILON).
	*/
	bool isVertical();

	/**
	*	@brief Check if the parameter t is valid to get a point of the segment.
	*/
	virtual bool isTvalid(double t) { return ((t >= 0) && (t <= 1)); }

	/**
	*	@brief Determines whether p is in the left of SegmentLine.
	*/
	bool left(Point& p) { return p.left(_orig, _dest); }

	/**
	*	@brief Returns the length of the segment.
	*/
	double length() { return _orig.distance(_dest); }

	/**
	*	@brief Assignment operator.
	*/
	virtual SegmentLine& operator=(const SegmentLine& segment);

	/**
	*	@brief Overriding cout call.
	*/
	friend std::ostream& operator<<(std::ostream& os, const SegmentLine& segment);

	/**
	*	@brief Determines whether two segments intersect in their own way, that is, when they intersect completely. Use only arithmetic.
	*/
	virtual bool segmentIntersection(SegmentLine& l);

	/**
	*	@brief Modifies the origin of the segment.
	*/
	void setA(Point& p) { _orig = p; }

	/**
	*	@brief Returns the slope of the implied straight line equation: m = (yb-ya) / (xb-xa).
	*/
	double slope();

	/**
	*	@brief Returns the area formed by the triangle composed of the current SegmentLine and the union of its bounds with p.
	*/
	double triangleArea2(Point& p) { return p.triangleArea2(_orig, _dest); } 

	bool intersects(const RayLine& r, Point& res);

	bool intersects(const Line& r, Point& res);

	bool intersects(const SegmentLine& r, Point& res);

};

