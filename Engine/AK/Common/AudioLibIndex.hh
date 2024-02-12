#pragma once

class CAkAudioLibIndex
{
public:
	CAkIndexItem<void*> m_idxAudioNode;
	CAkIndexItem<void*> m_idxBusses;
	CAkIndexItem<void*> m_idxCustomStates;
	CAkIndexItem<CAkEvent*> m_idxEvents;
	CAkIndexItem<CAkAction*> m_idxActions;
	CAkIndexItem<void*> m_idxLayers;
	CAkIndexItem<void*> m_idxAttenuations;
	CAkIndexItem<void*> m_idxDynamicSequences;
	CAkIndexItem<void*> m_idxDialogueEvents;
	CAkIndexItem<void*> m_idxFxShareSets;
	CAkIndexItem<void*> m_idxFxCustom;

	static UFG_INLINE CAkAudioLibIndex* Instance() 
	{
		return *reinterpret_cast<CAkAudioLibIndex**>(UFG_RVA(0x249E9D8));
	}
};
UFG_ASSERT_CLASS(CAkAudioLibIndex, 17512);