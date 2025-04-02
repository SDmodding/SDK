#pragma once

// Unknown file, unused...
class SkookumHookBase
{
public:
	virtual void load_compiled_class_group(SSClass*) = 0;
	virtual void on_init() = 0;
	virtual void on_deinit() = 0;
	virtual u32 get_elapsed_ms() = 0;
	virtual void wait_tenth_second() = 0;
};

namespace UFG
{
	class SkookumMgr : public SkookumHookBase
	{
	public:
		/* Static Functions */

		SDK_SINLINE void ConstructCodeBlockFromScript(AString& destText, const char* scriptText) { SDK_CALL_FUNC(void, 0x4D9930, AString&, const char*)(destText, scriptText); }
		SDK_SINLINE void Deinit() { SDK_CALL_FUNC(void, 0x4DF3C0)(); }
		SDK_SINLINE void EndScene() { SDK_CALL_FUNC(void, 0x4E08A0)(); }
		SDK_SINLINE void Init() { SDK_CALL_FUNC(void, 0x4E1770)(); }
		SDK_SINLINE void InvokeOnLocationChange() { SDK_CALL_FUNC(void, 0x4E20D0)(); }
		SDK_SINLINE void InvokeOnProjectInit() { SDK_CALL_FUNC(void, 0x4E2120)(); }
		SDK_SINLINE void InvokeWorldCoroutine(const qSymbol& coroutineName, SSInstance* pArg) { SDK_CALL_FUNC(void, 0x4E2180, const qSymbol&, SSInstance*)(coroutineName, pArg); }
		SDK_SINLINE bool IsReferencedByScripts(SimObject* pSimObject) { return SDK_CALL_FUNC(bool, 0x4E22D0, SimObject*)(pSimObject); }
		SDK_SINLINE void LoadCompiledBinary() { SDK_CALL_FUNC(void, 0x4E2730)(); }

		SDK_SINLINE SSIExternalMethodCallWrapper* RunExternalCodeBlock(SSCode* pCode, SSClass* pClass, SSInstance* pScope, bool* pFinished, SSInstance** ppResult) {
			return SDK_CALL_FUNC(SSIExternalMethodCallWrapper*, 0x50F670, SSCode*, SSClass*, SSInstance*, bool*, SSInstance**)(pCode, pClass, pScope, pFinished, ppResult);
		}

		SDK_SINLINE void StartScene(bool initialPass) { SDK_CALL_FUNC(void, 0x510530, bool)(initialPass); }
		SDK_SINLINE void Update(f32 simDelta) { SDK_CALL_FUNC(void, 0x5117A0, f32)(simDelta); }
	};
}