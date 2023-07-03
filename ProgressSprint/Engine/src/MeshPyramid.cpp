//----------------------------------------------------------------------------
// Copyright 2023, Ed Keenan, all rights reserved.
//----------------------------------------------------------------------------

#include "MeshPyramid.h"
#include "MathEngine.h"

// HACK FEST --- will eventually be in managers/singleton
extern ID3D11Device *pHackDevice;
extern ID3D11DeviceContext *pHackDeviceContext;

using namespace Azul;


VertexPos p_Vertices_pos[] =
{

	//back face
	Vec3(-1.0f, -1.0f, -1.0f), //1
	Vec3(0.0f, 1.0f, 0.0f), //0
	Vec3(+1.0f, -1.0f, -1.0f), //2

	//left face
	Vec3(-1.0f, -1.0f, +1.0f), //4
	Vec3(0.0f, 1.0f, 0.0f), //0
	Vec3(-1.0f, -1.0f, -1.0f), //1

	//right face
	Vec3(+1.0f, -1.0f, -1.0f), //2
	Vec3(0.0f, 1.0f, 0.0f), //0
	Vec3(+1.0f, -1.0f, +1.0f), //3

	//front face
	Vec3(+1.0f, -1.0f, +1.0f), //3
	Vec3(0.0f, 1.0f, 0.0f), //0
	Vec3(-1.0f, -1.0f, +1.0f), //4

	//bottom face
	Vec3(-1.0f, -1.0f, -1.0f), //0
	Vec3(+1.0f, -1.0f, -1.0f), //4
	Vec3(+1.0f, -1.0f, +1.0f), //1
	Vec3(-1.0f, -1.0f, +1.0f) //2
};

VertexColor p_Vertices_color[] =
{
	 Vec3(0.0f, 0.0f, 0.0f) , // 0
	 Vec3(0.0f, 1.0f, 0.0f) , // 1
	 Vec3(1.0f, 1.0f, 0.0f) , // 2
	 Vec3(1.0f, 0.0f, 0.0f) , // 3
	 Vec3(0.0f, 0.0f, 1.0f) , // 4
	 Vec3(0.0f, 1.0f, 1.0f) , // 5
	 Vec3(1.0f, 1.0f, 1.0f) , // 6
	 Vec3(1.0f, 0.0f, 1.0f) , // 7
	 Vec3(0.0f, 0.0f, 1.0f) , // 8
	 Vec3(0.0f, 1.0f, 1.0f) , // 9
	 Vec3(1.0f, 1.0f, 1.0f) , // 10
	 Vec3(1.0f, 0.0f, 1.0f) , // 11
	 Vec3(0.0f, 0.0f, 1.0f) , // 12
	 Vec3(0.0f, 1.0f, 1.0f) , // 13
	 Vec3(1.0f, 1.0f, 1.0f) , // 14
	 Vec3(1.0f, 0.0f, 1.0f)   // 15
};


uint32_t p_Indicies[] =
{
	// Triangle indices... 
	1, 2, 0,
	10, 11, 9,
	7, 8, 6,
	4, 5, 3,
	12, 13, 14,
	12, 14,15

};
unsigned int NumVertsPyr = sizeof(p_Vertices_pos) / sizeof(p_Vertices_pos[0]);
unsigned int NumIndicesPyr = sizeof(p_Indicies) / sizeof(p_Indicies[0]);


MeshPyramid::MeshPyramid()
	: Mesh(NumVertsPyr, NumIndicesPyr)
{
	// Create an initialize the vertex buffer.
	poVertexBuffer_pos = CreateVertexBuffer(sizeof(p_Vertices_pos), p_Vertices_pos);
	poVertexBuffer_color = CreateVertexBuffer(sizeof(p_Vertices_color), p_Vertices_color);

	// Create and initialize the index buffer.
	poIndexBuffer = CreateIndexBuffer(sizeof(p_Indicies), p_Indicies);

	// Create the constant buffers for the variables defined in the vertex shader.
	poConstantBuff_Projection = CreateConstantBuffer(sizeof(Mat4));
	poConstantBuff_View = CreateConstantBuffer(sizeof(Mat4));
	poConstantBuff_World = CreateConstantBuffer(sizeof(Mat4));
}


MeshPyramid::~MeshPyramid()
{
	// remove anything dynamic here
}


// --- End of File ---
