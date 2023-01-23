#pragma once

#include <d3d12.h>
#include <dxgi1_6.h>
#include <wrl.h>

#include <vector>

#include <chrono>

#include "WinApp.h"

class DirectXCommon
{
public: // �����o�֐�
	// ������
	void Initialize(WinApp* winApp);

	void InitializeDevice();

	void InitializeCommand();

	void InitializeSwapchain();

	void InitializeRenderTargetView();

	void InitializeDepthBuffer();

	void InitializeFence();

	// �`��O(��)����
	void PreDraw();

	void PostDraw();

	/// <summary>
	/// 60FPS�Œ�
	/// </summary>
	void InitializeFixFPS();
	void UpdateFixFPS();

	// �f�o�C�X�擾
	ID3D12Device* GetDevice() const { return device.Get(); }

	ID3D12GraphicsCommandList* GetCommandList() const { return commandList.Get(); }
	
private:

	WinApp* winApp = nullptr;

	Microsoft::WRL::ComPtr<ID3D12Device> device;
	Microsoft::WRL::ComPtr<IDXGIFactory7> dxgiFactory;

	Microsoft::WRL::ComPtr<ID3D12CommandAllocator> commandAllocator;
	Microsoft::WRL::ComPtr<ID3D12GraphicsCommandList> commandList;
	Microsoft::WRL::ComPtr<ID3D12CommandQueue> commandQueue;

	Microsoft::WRL::ComPtr<IDXGISwapChain4> swapChain;

	Microsoft::WRL::ComPtr<ID3D12DescriptorHeap> rtvHeap;
	Microsoft::WRL::ComPtr<ID3D12DescriptorHeap> dsvHeap;
	std::vector<Microsoft::WRL::ComPtr<ID3D12Resource>> backBuffers;
	Microsoft::WRL::ComPtr<ID3D12Resource> depthBuff;

	DXGI_SWAP_CHAIN_DESC1 swapChainDesc{};

	Microsoft::WRL::ComPtr<ID3D12Fence> fence;
	UINT64 fenceVal = 0;

	// �L�^����(FPS�Œ�p)
	std::chrono::steady_clock::time_point reference_;
};