#pragma once

namespace Illusion
{
	class Factory
	{
	public:
		SDK_SINLINE void Delete(Buffer* buffer, bool wait = 1) { SDK_CALL_FUNC(void, 0xA19960, Buffer*, bool)(buffer, wait); }
		SDK_SINLINE void Delete(Model* model, bool wait = 1) { SDK_CALL_FUNC(void, 0xA19A00, Model*, bool)(model, wait); }
		SDK_SINLINE void Delete(Shader* shader) { SDK_CALL_FUNC(void, 0xA19A50, Shader*)(shader); }
		SDK_SINLINE void Delete(Texture* texture, bool wait = 1) { SDK_CALL_FUNC(void, 0xA19B00, Texture*, bool)(texture, wait); }

		SDK_SINLINE AlphaState* NewAlphaState(const char* name, u32 name_uid, MemImageSchema* schema = 0, UFG::qMemoryPool* memory_pool = 0, u64 allocation_params = 0) {
			return SDK_CALL_FUNC(AlphaState*, 0xA1C900, const char*, u32, MemImageSchema*, UFG::qMemoryPool*, u64)(name, name_uid, schema, memory_pool, allocation_params);
		}

		SDK_SINLINE Buffer* NewBuffer(const char* name, u32 name_uid, u32 byte_size, MemImageSchema* schema, const char* alloc_name, UFG::qLinearAllocator* linear_allocator, u64 allocation_params = 0) {
			return SDK_CALL_FUNC(Buffer*, 0xA1CA70, const char*, u32, u32, MemImageSchema*, const char*, UFG::qLinearAllocator*, u64)(name, name_uid, byte_size, schema, alloc_name, linear_allocator, allocation_params);
		}

		SDK_SINLINE Buffer* NewBuffer(const char* name, u32 name_uid, u32 byte_size, MemImageSchema* schema = 0, const char* alloc_name = 0, UFG::qMemoryPool* memory_pool = 0, u64 allocation_params = 0) {
			return SDK_CALL_FUNC(Buffer*, 0xA1CC00, const char*, u32, u32, MemImageSchema*, const char*, UFG::qMemoryPool*, u64)(name, name_uid, byte_size, schema, alloc_name, memory_pool, allocation_params);
		}

		SDK_SINLINE Material* NewMaterial(const char* name, u32 name_uid, u32 num_params, MemImageSchema* schema = 0, UFG::qMemoryPool* memory_pool = 0, u64 allocation_params = 0) {
			return SDK_CALL_FUNC(Material*, 0x92CB0, const char*, u32, u32, MemImageSchema*, UFG::qMemoryPool*, u64)(name, name_uid, num_params, schema, memory_pool, allocation_params);
		}

		SDK_SINLINE MaterialTable* NewMaterialTable(const char* name, u32 name_uid, u32 num_materials, MemImageSchema* schema = 0, UFG::qMemoryPool* memory_pool = 0, u64 allocation_params = 0) {
			return SDK_CALL_FUNC(MaterialTable*, 0x92EA0, const char*, u32, u32, MemImageSchema*, UFG::qMemoryPool*, u64)(name, name_uid, num_materials, schema, memory_pool, allocation_params);
		}

		SDK_SINLINE Model* NewModel(const char* name, u32 name_uid, u32 num_meshes, MemImageSchema* schema = 0, UFG::qMemoryPool* memory_pool = 0, u64 allocation_params = 0) {
			return SDK_CALL_FUNC(Model*, 0xA1CF40, const char*, u32, u32, MemImageSchema*, UFG::qMemoryPool*, u64)(name, name_uid, num_meshes, schema, memory_pool, allocation_params);
		}

		SDK_SINLINE RasterState* NewRasterState(const char* name, u32 name_uid, MemImageSchema* schema = 0, UFG::qMemoryPool* memory_pool = 0, u64 allocation_params = 0) {
			return SDK_CALL_FUNC(RasterState*, 0xA1D4A0, const char*, u32, MemImageSchema*, UFG::qMemoryPool*, u64)(name, name_uid, schema, memory_pool, allocation_params);
		}

		SDK_SINLINE Shader* NewShader(const char* name, u32 name_uid, MemImageSchema* schema = 0, UFG::qMemoryPool* memory_pool = 0, u64 allocation_params = 0) {
			return SDK_CALL_FUNC(Shader*, 0xA1D620, const char*, u32, MemImageSchema*, UFG::qMemoryPool*, u64)(name, name_uid, schema, memory_pool, allocation_params);
		}

		SDK_SINLINE StateBlock* NewStateBlock(const char* name, u32 name_uid, u32 num_values, u32 byte_size, MemImageSchema* schema = 0, UFG::qMemoryPool* memory_pool = 0, u64 allocation_params = 0) {
			return SDK_CALL_FUNC(StateBlock*, 0x930B0, const char*, u32, u32, u32, MemImageSchema*, UFG::qMemoryPool*, u64)(name, name_uid, num_values, byte_size, schema, memory_pool, allocation_params);
		}

		SDK_SINLINE Texture* NewTexture(const char* name, u32 name_uid, MemImageSchema* schema = 0, UFG::qMemoryPool* memory_pool = 0, u64 allocation_params = 0) {
			return SDK_CALL_FUNC(Texture*, 0xA1D8A0, const char*, u32, MemImageSchema*, UFG::qMemoryPool*, u64)(name, name_uid, schema, memory_pool, allocation_params);
		}

		SDK_SINLINE VertexDecl* NewVertexDecl(VertexStreamDescriptor* descriptor, MemImageSchema* schema = 0, UFG::qMemoryPool* memory_pool = 0, u64 allocation_params = 0) {
			return SDK_CALL_FUNC(VertexDecl*, 0xA1DB40, VertexStreamDescriptor*, MemImageSchema*, UFG::qMemoryPool*, u64)(descriptor, schema, memory_pool, allocation_params);
		}
	};
}