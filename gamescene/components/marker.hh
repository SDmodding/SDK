#pragma once

namespace UFG
{
	class MarkerBase : public HintComponentBase, public qNodeRB<MarkerBase>
	{
	public:
		TransformNodeComponent* mpXformNode;
	};
	SDK_ASSERT_SIZEOF(MarkerBase, 0x70);
}