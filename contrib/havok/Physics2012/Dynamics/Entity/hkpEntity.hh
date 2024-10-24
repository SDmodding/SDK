#pragma once

class hkpEntity : public hkpWorldObject
{
private:
	u8 _pad[0x208];
public:

	/* Functions */

	hkBool isActive() { return SDK_CALL_FUNC(hkBool, 0xD61300, void*)(this); }

	void activate() { SDK_CALL_FUNC(void, 0xD60FE0, void*)(this); }

	void deactivate() { SDK_CALL_FUNC(void, 0xD610F0, void*)(this); }
};
SDK_ASSERT_SIZEOF(hkpEntity, 0x2D0);