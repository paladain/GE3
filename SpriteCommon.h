#pragma once

#include "DirectXCommon.h"

class SpriteCommon
{
	struct Vertex
	{
		XMFLOAT3 pos;       // xyz���W
		XMFLOAT3 normal;    // �@���x�N�g��
		XMFLOAT2 uv;        // uv���W
	};
public: // �����o�ϐ�
   // ������
	void Initialize(DirectXCommon* dxCommon);

	void Draw(DirectXCommon* dxCommon);

private:
	Vertex vertices[];
};