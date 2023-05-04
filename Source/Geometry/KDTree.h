#pragma once
#include "PointCloud.h"
#include "PointCloud3d.h"
#include "Nodo3d.h"
#include "Nodo2d.h"
#include "SegmentLine.h"



class KDTree{

	private:

		Nodo3d raiz3D;
		Nodo2d raiz2D;

		std::vector<Plane> planos;
		std::vector<SegmentLine> segmentos;

	public:
		/**
		*	@brief Default constructor.
		*/
		KDTree();

		/**
		*	@brief Constructor.
		*/
		KDTree(PointCloud* nP);

		KDTree(PointCloud3d* nP);

		/**
		*	@brief Copy constructor,
		*/
		KDTree(const KDTree& kdTree);

		/**
		*	@brief Destructor.
		*/
		virtual ~KDTree();

		Nodo3d construir3DTree(std::vector<Vect3d> puntos, int nivel);

		Nodo2d construir2DTree(std::vector<Point> puntos, int nivel);

		static bool compX(const Vect3d& v1, const Vect3d& v2);
		static bool compY(const Vect3d& v1, const Vect3d& v2);
		static bool compZ(const Vect3d& v1, const Vect3d& v2);

		static bool comp2X(const Point& v1, const Point& v2);
		static bool comp2Y(const Point& v1, const Point& v2);

		Plane determinarPlanoDiv(int nivel, double coordenada);
		SegmentLine determinarSegmentoDiv(int nivel, double coordenada);

		std::vector<Plane> getPlanos() { return planos; };
		std::vector<SegmentLine> getSegmentos() { return segmentos; };

		Nodo2d* buscarPunto(Point p);
		Nodo3d* buscarPunto(Vect3d p);

		void insertarPunto(Point p);
		void insertarPunto(Vect3d p);

		void eliminarPunto(Point p);
		void eliminarPunto(Vect3d p);

};
