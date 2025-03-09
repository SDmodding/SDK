#pragma once

namespace UFG
{
	class RenderStagePlugin : public SimComponent, public qNode<RenderStagePlugin>
	{
	public:
		enum { _TypeUID = 0x06000001 };

		/* Virtual Functions */

		virtual void _UnkVFunc14() = 0;
		virtual void RenderPostEffect(qList<Illusion::RenderQueue>* serialization_list, RenderContext* render_context, float delta_time, Illusion::Target** curr_target, Illusion::Target** scratch_target) = 0;
		virtual void _UnkVFunc16() = 0;
		virtual void Update(float sim_time_delta) = 0;
	};
}