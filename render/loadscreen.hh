#pragma once

namespace Render
{
	SDK_SINLINE bool IsLoadScreenRendering() { return SDK_CALL_FUNC(bool, 0x48050, )(); }

}