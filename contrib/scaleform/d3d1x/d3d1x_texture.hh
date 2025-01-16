#pragma once

namespace Scaleform::Render::D3D1x
{
	// TODO: Implement commented code
	class TextureManager : public Render::TextureManager
	{
	public:
		ID3D11Device* pDevice;
		ID3D11DeviceContext* pDeviceContext;
		//Scaleform::Render::D3D1x::MappedTexture MappedTexture0;
		//Scaleform::ArrayLH<ID3D11Resource*, 72, Scaleform::ArrayConstPolicy<8, 8, 0> > D3DTextureKillList;
		//Scaleform::ArrayLH<ID3D11View*, 72, Scaleform::ArrayConstPolicy<8, 8, 0> > D3DTexViewKillList;
		ID3D11SamplerState* SamplerStates[4];
		ID3D11SamplerState* CurrentSamplers[4];
		ID3D11View* CurrentTextures[4];
	};
}