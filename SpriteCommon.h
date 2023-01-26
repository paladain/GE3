#pragma once

#include "DirectXCommon.h"

class SpriteCommon
{
	struct Vertex
	{
		XMFLOAT3 pos;       // xyz座標
		XMFLOAT3 normal;    // 法線ベクトル
		XMFLOAT2 uv;        // uv座標
	};
public: // メンバ変数
   // 初期化
	void Initialize(DirectXCommon* dxCommon);

	void Draw(DirectXCommon* dxCommon);

private:
	Vertex vertices[];
};