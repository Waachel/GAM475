//----------------------------------------------------------------------------
// Copyright 2023, Ed Keenan, all rights reserved.
//----------------------------------------------------------------------------

#ifndef MESH_H
#define MESH_H

#include <d3d11.h>
#include "DLink.h"
#include "MathEngine.h"
#include "Camera.h"

using namespace Azul;

// Vertex data for a colored cube.
struct VertexColor
{
	Vec3 Color;
};

struct VertexPos
{
	Vec3 Position;
};

struct VertexNorm
{
	Vec3 Norm;
};

//struct VertexTextCoord
//{
//	Vec2 TextCoord;
//};

enum class VertexSlot : uint32_t
{
	Position,
	Color,
	Norm,
	TextCoord
};

enum class ConstantBufferSlot : uint32_t
{
	Projection,
	View,
	World
};

class Mesh
{
public:
	enum class Name
	{
		CUBE,
		PYRAMID,
		NULL_MESH,
		NOT_INITIALIZED
	};

public:
	Mesh() = delete;
	Mesh(Mesh &copyMesh) = delete;
	Mesh &operator = (Mesh &copyMesh) = delete;
	virtual ~Mesh();

	Mesh(unsigned int numVerts, unsigned int numTriangles);

	ID3D11Buffer *CreateVertexBuffer(unsigned int NumBytes, void *pData);
	ID3D11Buffer *CreateIndexBuffer(unsigned int NumBytes, void *pData);
	ID3D11Buffer *CreateConstantBuffer(unsigned int NumBytes);

	void Wash();
	bool Compare(DLink *pTarget);
	char *GetName();
	void SetName(Mesh::Name _name);

	void ActivateMesh();
	void TransferConstantBuffer(Camera *pCam, Mat4 *pWorld);
	void RenderIndexBuffer();

	// ---------------------------------------------
	// 	   Data:
	// ---------------------------------------------

	Name name;

	unsigned int numVerts;
	unsigned int numIndices;

	// Vertex buffer data
	ID3D11Buffer *poVertexBuffer_pos;
	ID3D11Buffer *poVertexBuffer_color;
	ID3D11Buffer *poVertexBuffer_norm;
	ID3D11Buffer *poVertexBuffer_texCoord;

	ID3D11Buffer *poIndexBuffer;

	// Shader resources
	ID3D11Buffer *poConstantBuff_Projection;
	ID3D11Buffer *poConstantBuff_World;
	ID3D11Buffer *poConstantBuff_View;

};

#endif

// --- End of File ---
