#pragma once

namespace UFG
{
	class UELComponent : public SimComponent, public UpdateInterface, public qNode<UELComponent>
	{
	public:
		enum { _TypeUID = 0xD6000001 };

		UELParameters mParameters;
		RebindingComponentHandle<TriadWarsComponent> mTriadWarsComponent;

		/* Functions */

		UEL::Value GetterGangMember2() { return SDK_CALL_FUNC(UEL::Value, 0x5B7CF0, void*)(this); }
		UEL::Value GetterMeleeWeapon2() { return SDK_CALL_FUNC(UEL::Value, 0x5B7D40, void*)(this); }
		UEL::Value GetterRangedWeapon2() { return SDK_CALL_FUNC(UEL::Value, 0x5B7D90, void*)(this); }
		UEL::Value GetterThrownWeapon2() { return SDK_CALL_FUNC(UEL::Value, 0x5B7DE0, void*)(this); }
		UEL::Value LookupProperties(const qSymbol& symPropertyName) { return SDK_CALL_FUNC(UEL::Value, 0x5BCD20, void*, const qSymbol&)(this, symPropertyName); }
	};
	SDK_ASSERT_SIZEOF(UELComponent, 0x128);
}