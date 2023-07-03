//--------------------------------------------------------------
// Copyright 2023, Ed Keenan, all rights reserved.
//--------------------------------------------------------------

#include <d3d11.h>
#include <d3dcompiler.h>
#include <WinUser.h>
#include "Game.h"
#include "Engine.h"
#include "MathEngine.h"
#include "Camera.h"
#include "Colors.h"
#include "GameObject.h"
#include "ShaderObject.h"
#include "ShaderObject_ColorByVertex.h"
#include "Mesh.h"
#include "MeshCube.h"
#include "MeshPyramid.h"
#include "GraphicsObject_ColorByVertex.h"
#include "GraphicsObject_Wireframe.h"
#include "GameObjectMan.h"
#include "MeshNodeMan.h"
#include "ShaderObjectNodeMan.h"

using namespace Azul;

// HACK FEST --- will eventually be in managers/singleton
ID3D11Device *pHackDevice;
ID3D11DeviceContext *pHackDeviceContext;
Camera *pHackCamera;

// Demo parameters
ShaderObject *poShaderA = nullptr;
//Mesh *poMeshA = nullptr;

// Demo
Vec3 Orig_up;
Vec3 Orig_tar;
Vec3 Orig_pos;
Vec3 Orig_upNorm;
Vec3 Orig_forwardNorm;
Vec3 Orig_RightNorm;


Game::Game(const char *const pName, int width, int height)
	: Engine(pName, width, height)
{
	mTimer.Reset();
}

Game::~Game()
{
}

//-----------------------------------------------------------------------------
// Game::LoadContent()
//		Allows you to load all content needed for your engine,
//	    such as objects, graphics, etc.
//-----------------------------------------------------------------------------
bool Game::LoadContent()
{
	ShaderObjectNodeMan::Create();
	MeshNodeMan::Create();
	GameObjectMan::Create();

	// ---------------------------------
	//  Camera - Setup
	// ---------------------------------
	{
		pHackCamera = new Camera();
		assert(pHackCamera);

		Vec3 camPos(0, 2, 7);
		Vec3 tarVect(0, 0, 0);
		Vec3 upVect(0, 1, 0);

		pHackCamera->setOrientAndPosition(upVect, tarVect, camPos);
		pHackCamera->setPerspective(50.0f, GetAspectRatio(), 0.1f, 1000.0f);
	}

	// ------------------------------------------
	//   Model + Shaders --> GraphicsObject
	// -------------------------------------------
	{
		// ---------------------------------
		//  Model - Cube
		// ---------------------------------

		Mesh *poMeshA = new MeshCube();
		assert(poMeshA);

		MeshNodeMan::Add(Mesh::Name::CUBE, poMeshA);

		// ---------------------------------
		//  Model - Pyramid
		// ---------------------------------

		Mesh* poMeshB = new MeshPyramid();
		assert(poMeshB);

		MeshNodeMan::Add(Mesh::Name::PYRAMID, poMeshB);
		//MeshNodeMan::Dump();

		// --------------------------------
		//  ShaderObject  ColorByVertex
		// --------------------------------
		poShaderA = new ShaderObject_ColorByVertex(ShaderObject::Name::ColorByVertex);

		ShaderObjectNodeMan::Add(ShaderObject::Name::ColorByVertex, poShaderA);
		ShaderObjectNodeMan::Dump();

		// --------------------------------
		//  Graphics Object -- needs model + shader
		// --------------------------------
		GraphicsObject *pGraphicsObject = new GraphicsObject_ColorByVertex(poMeshA,
																		   poShaderA);

		GraphicsObject *pGraphicsObject_wireframe = new GraphicsObject_Wireframe(poMeshA,
																				 poShaderA);

		GraphicsObject* pGraphicsObject2 = new GraphicsObject_ColorByVertex(poMeshB,
																			poShaderA);

		GraphicsObject* pGraphicsObject_wireframe2 = new GraphicsObject_Wireframe(poMeshB,
																					poShaderA);
		// --------------------------------
		// Game Object owns the graphics object
		// --------------------------------
		GameObject *pGameObj = new GameObject(pGraphicsObject);
		pGameObj->SetName("Solid Cube");
		pGameObj->SetPos(Vec3(0, 0, 0));
		pGameObj->SetScale(0.5f);

		GameObject *pGameObj2 = new GameObject(pGraphicsObject_wireframe);
		pGameObj2->SetPos(Vec3(2, 0, 0));
		pGameObj2->SetName("Wireframe Cube");
		pGameObj2->SetRot(Mat4::Rot1::Y, MATH_PI4);
		pGameObj2->SetDeltaRot(0.02f);
		pGameObj2->SetScale(0.5f);

		GameObject* pGameObj3 = new GameObject(pGraphicsObject2);
		pGameObj3->SetPos(Vec3(-4, 0, 0));
		pGameObj3->SetDeltaY(1);
		pGameObj3->SetName("Solid Pyramid");

		GameObject* pGameObj4 = new GameObject(pGraphicsObject_wireframe2);
		pGameObj4->SetPos(Vec3(-2, 0, 0));
		pGameObj4->SetScale(0.25f);
		pGameObj4->SetDeltaX(1);
		pGameObj4->SetDeltaZ(1);
		pGameObj4->SetRot(Mat4::Rot1::Z, MATH_PI4);
		pGameObj4->SetDeltaRot(0.02f);
		pGameObj4->SetName("Wireframe Pyramid");

		GameObjectMan::Add(pGameObj);
		GameObjectMan::Add(pGameObj2);
		GameObjectMan::Add(pGameObj3);
		GameObjectMan::Add(pGameObj4);

	}


	// squirrel for reset
	pHackCamera->updateCamera();
	pHackCamera->GetHelper(Orig_up, Orig_tar, Orig_pos, Orig_upNorm, Orig_forwardNorm, Orig_RightNorm);


	return true;
}

//-----------------------------------------------------------------------------
// Game::Update()
//      Called once per frame, update data, tranformations, etc
//      Use this function to control process order
//      Input, AI, Physics, Animation, and Graphics
//-----------------------------------------------------------------------------

Vec3 obj(0.0f, 0.0f, 0.0f);

void Game::Update(float)
{
	// ------------------------------------
	// Update the camera once per frame
	// ------------------------------------
	mTimer.Tick();
	Camera *pCam = pHackCamera;

	if((GetKeyState('S') & 0x8000))
	{
		// Reset	
		obj.set(0, 0, 0);
		pCam->SetHelper(Orig_up, Orig_tar, Orig_pos);
	}

	if((GetKeyState('W') & 0x8000))
	{
		Vec3 newObj(2, 0, 0);
		Vec3 pos;
		Vec3 tar;
		Vec3 up;
		Vec3 upNorm;
		Vec3 forwardNorm;
		Vec3 rightNorm;

		pCam->GetHelper(up, tar, pos, upNorm, forwardNorm, rightNorm);

		// OK, now 3 points... pos, tar, up
		//     now 3 normals... upNorm, forwardNorm, rightNorm

		Vec3 delta = newObj - obj;

		up += delta;
		tar += delta;
		pos += delta;

		obj = newObj;

		pCam->SetHelper(up, tar, pos);
	}

	if((GetKeyState('E') & 0x8000))
	{
		Vec3 newObj(-2, 0, 0);
		Vec3 pos;
		Vec3 tar;
		Vec3 up;
		Vec3 upNorm;
		Vec3 forwardNorm;
		Vec3 rightNorm;

		pCam->GetHelper(up, tar, pos, upNorm, forwardNorm, rightNorm);

		// OK, now 3 points... pos, tar, up
		//     now 3 normals... upNorm, forwardNorm, rightNorm

		Vec3 delta = newObj - obj;

		up += delta;
		tar += delta;
		pos += delta;

		obj = newObj;

		pCam->SetHelper(up, tar, pos);
	}


	if((GetKeyState('D') & 0x8000))
	{

		Vec3 newObj(0, 0, 0);
		Vec3 pos;
		Vec3 tar;
		Vec3 up;
		Vec3 upNorm;
		Vec3 forwardNorm;
		Vec3 rightNorm;

		pCam->GetHelper(up, tar, pos, upNorm, forwardNorm, rightNorm);

		// OK, now 3 points... pos, tar, up
		//     now 3 normals... upNorm, forwardNorm, rightNorm
		Vec3 delta = newObj - obj;

		up += delta;
		tar += delta;
		pos += delta;

		obj = newObj;

		pCam->SetHelper(up, tar, pos);
	}

	if((GetKeyState('I') & 0x8000))
	{
		Vec3 pos;
		Vec3 tar;
		Vec3 up;
		Vec3 upNorm;
		Vec3 forwardNorm;
		Vec3 rightNorm;

		pCam->GetHelper(up, tar, pos, upNorm, forwardNorm, rightNorm);

		// OK, now 3 points... pos, tar, up
		//     now 3 normals... upNorm, forwardNorm, rightNorm
		//	tar = obj;

		pos = pos + 0.03f * forwardNorm;
		//tar = tar + 0.03f * forwardNorm;
		up = up + 0.03f * forwardNorm;

		pCam->SetHelper(up, tar, pos);
	}

	if((GetKeyState('O') & 0x8000))
	{
		Vec3 pos;
		Vec3 tar;
		Vec3 up;
		Vec3 upNorm;
		Vec3 forwardNorm;
		Vec3 rightNorm;

		pCam->GetHelper(up, tar, pos, upNorm, forwardNorm, rightNorm);

		// OK, now 3 points... pos, tar, up
		//     now 3 normals... upNorm, forwardNorm, rightNorm
		//tar = obj;

		pos = pos - 0.03f * forwardNorm;
		up = up - 0.03f * forwardNorm;

		pCam->SetHelper(up, tar, pos);

	}

	if((GetKeyState(VK_RIGHT) & 0x8000))
	{

		Vec3 pos;
		Vec3 tar;
		Vec3 up;
		Vec3 upNorm;
		Vec3 forwardNorm;
		Vec3 rightNorm;

		pCam->GetHelper(up, tar, pos, upNorm, forwardNorm, rightNorm);

		// OK, now 3 points... pos, tar, up
		//     now 3 normals... upNorm, forwardNorm, rightNorm
	//	tar = obj;

		Mat4 Trans(Mat4::Trans::XYZ, tar);
		Mat4 NegTrans(Mat4::Trans::XYZ, -tar);

		Mat4 Rot;
		Rot.set(Mat4::Rot::AxisAngle, upNorm, +0.03f);

		Mat4 M = NegTrans * Rot * Trans;

		up = Vec4(up, 1) * M;
		pos = Vec4(pos, 1) * M;
		tar = Vec4(tar, 1) * M;

		pCam->SetHelper(up, tar, pos);
	}

	if((GetKeyState(VK_LEFT) & 0x8000))
	{

		Vec3 pos;
		Vec3 tar;
		Vec3 up;
		Vec3 upNorm;
		Vec3 forwardNorm;
		Vec3 rightNorm;

		pCam->GetHelper(up, tar, pos, upNorm, forwardNorm, rightNorm);

		// OK, now 3 points... pos, tar, up
		//     now 3 normals... upNorm, forwardNorm, rightNorm

	//	tar = obj;

		Mat4 Trans(Mat4::Trans::XYZ, tar);
		Mat4 NegTrans(Mat4::Trans::XYZ, -tar);

		Mat4 Rot;
		Rot.set(Mat4::Rot::AxisAngle, upNorm, -0.03f);

		Mat4 M = NegTrans * Rot * Trans;

		up = Vec4(up, 1) * M;
		pos = Vec4(pos, 1) * M;
		tar = Vec4(tar, 1) * M;

		pCam->SetHelper(up, tar, pos);
	}

	if((GetKeyState(VK_DOWN) & 0x8000))
	{
		Vec3 pos;
		Vec3 tar;
		Vec3 up;
		Vec3 upNorm;
		Vec3 forwardNorm;
		Vec3 rightNorm;

		pCam->GetHelper(up, tar, pos, upNorm, forwardNorm, rightNorm);

		//	tar = obj;


			// OK, now 3 points... pos, tar, up
			//     now 3 normals... upNorm, forwardNorm, rightNorm

		Mat4 Trans(Mat4::Trans::XYZ, tar);
		Mat4 NegTrans(Mat4::Trans::XYZ, -tar);
		Mat4 Rot;
		Rot.set(Mat4::Rot::AxisAngle, rightNorm, 0.03f);

		Mat4 M = NegTrans * Rot * Trans;

		up = Vec4(up, 1) * M;
		pos = Vec4(pos, 1) * M;
		tar = Vec4(tar, 1) * M;

		pCam->SetHelper(up, tar, pos);
	}

	if((GetKeyState(VK_UP) & 0x8000))
	{
		Vec3 pos;
		Vec3 tar;
		Vec3 up;
		Vec3 upNorm;
		Vec3 forwardNorm;
		Vec3 rightNorm;

		pCam->GetHelper(up, tar, pos, upNorm, forwardNorm, rightNorm);

		// OK, now 3 points... pos, tar, up
		//     now 3 normals... upNorm, forwardNorm, rightNorm
		//tar = obj;

		Mat4 Trans(Mat4::Trans::XYZ, tar);
		Mat4 NegTrans(Mat4::Trans::XYZ, -tar);
		Mat4 Rot;
		Rot.set(Mat4::Rot::AxisAngle, rightNorm, -0.03f);

		Mat4 M = NegTrans * Rot * Trans;

		up = Vec4(up, 1) * M;
		pos = Vec4(pos, 1) * M;
		tar = Vec4(tar, 1) * M;

		pCam->SetHelper(up, tar, pos);
	}
















	pHackCamera->updateCamera();
	GameObjectMan::Update(mTimer.TotalTime());
}

//-----------------------------------------------------------------------------
// Game::Render()
//		This function is called once per frame
//	    Use this for draw graphics to the screen.
//      Only do rendering here
//-----------------------------------------------------------------------------
void Game::Render()
{
	this->SetDefaultTargetMode();

	GameObjectMan::Draw();
}

//-----------------------------------------------------------------------------
// Game::UnLoadContent()
//       unload content (resources loaded above)
//       unload all content that was loaded before the Engine Loop started
//-----------------------------------------------------------------------------
void Game::UnloadContent()
{
	//delete poMeshA;
	//delete poShaderA;
	delete pHackCamera;

	ShaderObjectNodeMan::Destroy();
	MeshNodeMan::Destroy();
	GameObjectMan::Destroy();
}

//------------------------------------------------------------------
// Game::ClearBufferFunc()
// Allows user to change the way the clear buffer function works
// 
// Clear the color and depth buffers.
//------------------------------------------------------------------
void Game::ClearDepthStencilBuffer()
{
#ifdef _DEBUG
	const Vec4 ClearColor = Azul::Colors::LightGray;
#else
	const Vec4 ClearColor = Azul::Colors::Wheat;
#endif
	float clearDepth = 1.0f;
	uint8_t clearStencil = 0;
	g_d3dDeviceContext->ClearRenderTargetView(g_d3dRenderTargetView, (const float *)&ClearColor);
	g_d3dDeviceContext->ClearDepthStencilView(g_d3dDepthStencilView, D3D11_CLEAR_DEPTH | D3D11_CLEAR_STENCIL, clearDepth, clearStencil);
}

// --- End of File ---
