//--------------------------------------------------------------
// Copyright 2023, Ed Keenan, all rights reserved.
//--------------------------------------------------------------

#ifndef CAMERA_H
#define CAMERA_H

#include "MathEngine.h"

using namespace Azul;

class Camera final : public Align16 
{

public:
	// Default constructor
	Camera();
	Camera(const Camera &) = delete;
	Camera &operator = (const Camera &) = delete;
	~Camera() = default;

	// Setup on single camera
	void setPerspective(const float FieldOfView_Degs, const float AspectRatio, const float NearDist, const float FarDist);
	void setOrientAndPosition(const Vec3 &Up_vect, const Vec3 &inLookAt_pt, const Vec3 &pos_pt);

	// update camera system
	void updateCamera(void);

	// Get the matrices for rendering
	Mat4 &getViewMatrix();
	Mat4 &getProjMatrix();

	// helper functions
	void GetHelper(Vec3 &up, Vec3 &tar, Vec3 &pos, Vec3 &upNorm, Vec3 &forwardNorm, Vec3 &rightNorm);
	void SetHelper(Vec3 &up, Vec3 &tar, Vec3 &pos);

	// accessors
	void getPos(Vec3 &outPos) const;
	void getDir(Vec3 &outDir) const;
	void getUp(Vec3 &outUp) const;
	void getLookAt(Vec3 &outLookAt) const;
	void getRight(Vec3 &outRight) const;

	// Why no SETS for Pos, Dir, Up, LookAt and Right?
	//   They have to be adjusted _together_ in setOrientAndPosition()

private:  // methods should never be public
	void privUpdateProjectionMatrix(void);
	void privUpdateViewMatrix(void);


private:  // data  (Keep it private)

	// Projection Matrix
	Mat4	projMatrix;
	Mat4	viewMatrix;

	// camera unit vectors (up, dir, right)
	Vec3	vUp;
	Vec3	vDir;
	Vec3	vRight;  // derived by up and dir
	Vec3	vPos;
	Vec3	vLookAt;

	// Define the frustum inputs
	float	nearDist;
	float	farDist;
	float	fovy;  // aka view angle along y axis
	float	aspectRatio;
};

#endif

// --- End of File ---