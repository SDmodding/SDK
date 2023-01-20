#pragma once
#include <d3d11.h>
#pragma comment(lib, "d3d11.lib")

#include "3rdParty/ImGui/imgui.h"
#include "3rdParty/ImGui/imgui_internal.h"
#include "3rdParty/ImGui/imgui_impl_dx11.h"
#include "3rdParty/ImGui/imgui_impl_win32.h"

#include "../Callbacks/OnRender.hpp"

namespace Hook
{
	namespace ImGuiRender
	{
		ID3D11DeviceContext* m_pDeviceContext		= nullptr;
		ID3D11RenderTargetView* m_pRenderTargetView = nullptr;

        void InitColors()
        {
            ImGuiStyle& m_iStyle = ImGui::GetStyle();

			m_iStyle.Colors[ImGuiCol_Text] = ImVec4(1.000f, 1.000f, 1.000f, 1.000f);
			m_iStyle.Colors[ImGuiCol_TextDisabled] = ImVec4(0.500f, 0.500f, 0.500f, 1.000f);
			m_iStyle.Colors[ImGuiCol_WindowBg] = ImVec4(0.180f, 0.180f, 0.180f, 1.000f);
			m_iStyle.Colors[ImGuiCol_ChildBg] = ImVec4(0.280f, 0.280f, 0.280f, 0.000f);
			m_iStyle.Colors[ImGuiCol_PopupBg] = ImVec4(0.160f, 0.160f, 0.160f, 1.000f);
			m_iStyle.Colors[ImGuiCol_Border] = ImVec4(0.266f, 0.266f, 0.266f, 1.000f);
			m_iStyle.Colors[ImGuiCol_BorderShadow] = ImVec4(0.000f, 0.000f, 0.000f, 0.000f);
			m_iStyle.Colors[ImGuiCol_FrameBg] = ImVec4(0.160f, 0.160f, 0.160f, 1.000f);
			m_iStyle.Colors[ImGuiCol_FrameBgHovered] = ImVec4(0.200f, 0.200f, 0.200f, 1.000f);
			m_iStyle.Colors[ImGuiCol_FrameBgActive] = ImVec4(0.280f, 0.280f, 0.280f, 1.000f);
			m_iStyle.Colors[ImGuiCol_TitleBg] = ImVec4(0.148f, 0.148f, 0.148f, 1.000f);
			m_iStyle.Colors[ImGuiCol_TitleBgActive] = ImVec4(0.148f, 0.148f, 0.148f, 1.000f);
			m_iStyle.Colors[ImGuiCol_TitleBgCollapsed] = ImVec4(0.148f, 0.148f, 0.148f, 1.000f);
			m_iStyle.Colors[ImGuiCol_MenuBarBg] = ImVec4(0.195f, 0.195f, 0.195f, 1.000f);
			m_iStyle.Colors[ImGuiCol_ScrollbarBg] = ImVec4(0.160f, 0.160f, 0.160f, 1.000f);
			m_iStyle.Colors[ImGuiCol_ScrollbarGrab] = ImVec4(0.277f, 0.277f, 0.277f, 1.000f);
			m_iStyle.Colors[ImGuiCol_ScrollbarGrabHovered] = ImVec4(0.300f, 0.300f, 0.300f, 1.000f);
			m_iStyle.Colors[ImGuiCol_ScrollbarGrabActive] = ImVec4(1.000f, 0.391f, 0.000f, 1.000f);
			m_iStyle.Colors[ImGuiCol_CheckMark] = ImVec4(1.000f, 1.000f, 1.000f, 1.000f);
			m_iStyle.Colors[ImGuiCol_SliderGrab] = ImVec4(0.391f, 0.391f, 0.391f, 1.000f);
			m_iStyle.Colors[ImGuiCol_SliderGrabActive] = ImVec4(1.000f, 0.391f, 0.000f, 1.000f);
			m_iStyle.Colors[ImGuiCol_Button] = ImVec4(1.000f, 1.000f, 1.000f, 0.000f);
			m_iStyle.Colors[ImGuiCol_ButtonHovered] = ImVec4(1.000f, 1.000f, 1.000f, 0.156f);
			m_iStyle.Colors[ImGuiCol_ButtonActive] = ImVec4(1.000f, 1.000f, 1.000f, 0.391f);
			m_iStyle.Colors[ImGuiCol_Header] = ImVec4(0.313f, 0.313f, 0.313f, 1.000f);
			m_iStyle.Colors[ImGuiCol_HeaderHovered] = ImVec4(0.469f, 0.469f, 0.469f, 1.000f);
			m_iStyle.Colors[ImGuiCol_HeaderActive] = ImVec4(0.469f, 0.469f, 0.469f, 1.000f);
			m_iStyle.Colors[ImGuiCol_Separator] = m_iStyle.Colors[ImGuiCol_Border];
			m_iStyle.Colors[ImGuiCol_SeparatorHovered] = ImVec4(0.391f, 0.391f, 0.391f, 1.000f);
			m_iStyle.Colors[ImGuiCol_SeparatorActive] = ImVec4(1.000f, 0.391f, 0.000f, 1.000f);
			m_iStyle.Colors[ImGuiCol_ResizeGrip] = ImVec4(1.000f, 1.000f, 1.000f, 0.250f);
			m_iStyle.Colors[ImGuiCol_ResizeGripHovered] = ImVec4(1.000f, 1.000f, 1.000f, 0.670f);
			m_iStyle.Colors[ImGuiCol_ResizeGripActive] = ImVec4(1.000f, 0.391f, 0.000f, 1.000f);
			m_iStyle.Colors[ImGuiCol_Tab] = ImVec4(0.098f, 0.098f, 0.098f, 1.000f);
			m_iStyle.Colors[ImGuiCol_TabHovered] = ImVec4(0.352f, 0.352f, 0.352f, 1.000f);
			m_iStyle.Colors[ImGuiCol_TabActive] = ImVec4(0.195f, 0.195f, 0.195f, 1.000f);
			m_iStyle.Colors[ImGuiCol_TabUnfocused] = ImVec4(0.098f, 0.098f, 0.098f, 1.000f);
			m_iStyle.Colors[ImGuiCol_TabUnfocusedActive] = ImVec4(0.195f, 0.195f, 0.195f, 1.000f);
			m_iStyle.Colors[ImGuiCol_PlotLines] = ImVec4(0.469f, 0.469f, 0.469f, 1.000f);
			m_iStyle.Colors[ImGuiCol_PlotLinesHovered] = ImVec4(1.000f, 0.391f, 0.000f, 1.000f);
			m_iStyle.Colors[ImGuiCol_PlotHistogram] = ImVec4(0.586f, 0.586f, 0.586f, 1.000f);
			m_iStyle.Colors[ImGuiCol_PlotHistogramHovered] = ImVec4(1.000f, 0.391f, 0.000f, 1.000f);
			m_iStyle.Colors[ImGuiCol_TextSelectedBg] = ImVec4(1.000f, 1.000f, 1.000f, 0.156f);
			m_iStyle.Colors[ImGuiCol_DragDropTarget] = ImVec4(1.000f, 0.391f, 0.000f, 1.000f);
			m_iStyle.Colors[ImGuiCol_NavHighlight] = ImVec4(1.000f, 0.391f, 0.000f, 1.000f);
			m_iStyle.Colors[ImGuiCol_NavWindowingHighlight] = ImVec4(1.000f, 0.391f, 0.000f, 1.000f);
			m_iStyle.Colors[ImGuiCol_NavWindowingDimBg] = ImVec4(0.000f, 0.000f, 0.000f, 0.586f);
			m_iStyle.Colors[ImGuiCol_ModalWindowDimBg] = ImVec4(0.000f, 0.000f, 0.000f, 0.586f);

			m_iStyle.ChildRounding = 4.0f;
			m_iStyle.FrameBorderSize = 1.0f;
			m_iStyle.FrameRounding = 2.0f;
			m_iStyle.GrabMinSize = 7.0f;
			m_iStyle.PopupRounding = 2.0f;
			m_iStyle.ScrollbarRounding = 12.0f;
			m_iStyle.ScrollbarSize = 13.0f;
			m_iStyle.TabBorderSize = 1.0f;
			m_iStyle.TabRounding = 0.0f;
			m_iStyle.WindowRounding = 4.0f;
        }

		bool m_bInit = true;
		void Init(IDXGISwapChain* m_pSwap)
		{
			m_bInit = !m_bInit;

			ImGui::CreateContext();

			ID3D11Device* m_pDevice = nullptr;
			m_pSwap->GetDevice(__uuidof(m_pDevice), reinterpret_cast<void**>(&(m_pDevice)));
			m_pDevice->GetImmediateContext(&m_pDeviceContext);

			ID3D11Texture2D* m_pRenderTargetTexture = nullptr;
			if (SUCCEEDED(m_pSwap->GetBuffer(0, __uuidof(ID3D11Texture2D), reinterpret_cast<LPVOID*>(&m_pRenderTargetTexture))))
			{
				D3D11_RENDER_TARGET_VIEW_DESC m_dRenderTargetVD;
				memset(&m_dRenderTargetVD, 0, sizeof(m_dRenderTargetVD));
				m_dRenderTargetVD.Format = DXGI_FORMAT_R8G8B8A8_UNORM;
				m_dRenderTargetVD.ViewDimension = D3D11_RTV_DIMENSION_TEXTURE2D;

				m_pDevice->CreateRenderTargetView(m_pRenderTargetTexture, &m_dRenderTargetVD, &m_pRenderTargetView);
				m_pRenderTargetTexture->Release();
			}

			ImGui_ImplWin32_Init(*UFG::Global::m_hWindow);
			ImGui_ImplDX11_Init(m_pDevice, m_pDeviceContext);
			ImGui_ImplDX11_CreateDeviceObjects();

			InitColors();

			ImGuiIO& m_IO = ImGui::GetIO();
			{
				m_IO.IniFilename = 0;
				m_IO.LogFilename = 0;

				m_IO.ConfigFlags |= ImGuiConfigFlags_NoMouseCursorChange;
			}

			if (m_IO.DisplaySize.y > 1080.f)
			{
				Callback::m_UseBiggerWindow = true;

				ImFontConfig m_FontConfig = ImFontConfig();
				m_FontConfig.OversampleH = m_FontConfig.OversampleV = 1;
				m_FontConfig.PixelSnapH = true;
				m_FontConfig.SizePixels = 26.f;

				m_IO.FontDefault = m_IO.Fonts->AddFontDefault(&m_FontConfig);
				m_IO.Fonts->Build();
				ImGui_ImplDX11_InvalidateDeviceObjects();
			}
		}
	}

	typedef long(__stdcall* m_tPresent)(IDXGISwapChain*, UINT, UINT); 
	m_tPresent m_oPresent;

	long __stdcall Present(IDXGISwapChain* m_pSwap, UINT m_uSync, UINT m_uFlags)
	{
		if (ImGuiRender::m_bInit)
			ImGuiRender::Init(m_pSwap);

		ImGui_ImplDX11_NewFrame();
		ImGui_ImplWin32_NewFrame();
		ImGui::NewFrame();

		Callback::OnRender();

		ImGui::EndFrame();
		ImGui::Render();
		ImGuiRender::m_pDeviceContext->OMSetRenderTargets(1, &ImGuiRender::m_pRenderTargetView, 0);
		ImGui_ImplDX11_RenderDrawData(ImGui::GetDrawData());

		return m_oPresent(m_pSwap, m_uSync, m_uFlags);
	}

	void PresentCleanup()
	{
		ImGuiRender::m_pDeviceContext->Release();
		ImGuiRender::m_pRenderTargetView->Release();

		ImGui_ImplDX11_Shutdown();
		ImGui_ImplWin32_Shutdown();
		ImGui::DestroyContext();
	}
}