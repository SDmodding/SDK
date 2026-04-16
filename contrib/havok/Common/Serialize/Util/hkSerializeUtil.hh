#pragma once

namespace hkSerializeUtil
{
	struct ErrorDetails
	{
		/// ErrorDetails constructor.
		ErrorDetails() : id(ERRORID_NONE) {}

		/// Error ids for loading packfile/tagfile.
		enum ErrorID
		{
			/// No errors reading from stream.
			ERRORID_NONE,
			/// Failed to read from stream.
			ERRORID_READ_FAILED,
			/// Unsupported file format.
			ERRORID_UNSUPPORTED_FORMAT,
			/// Packfile cannot be read on this platform.
			ERRORID_PACKFILE_PLATFORM,
			/// Versioning cannot be applied to loaded objects.
			ERRORID_VERSIONING_FAILED,
			/// Found object with members that cannot clean up memory when destroyed.
			ERRORID_NONHEAP_OBJECT,
			/// Stream was ok but some error in the data.
			ERRORID_LOAD_FAILED,
			/// The file contains deprecated format but hkFeature_serializeDeprecatedPre700() was not called
			ERRORID_DEPRECATED_NOT_INITIALIZED,
			/// Max error ID
			ERRORID_MAX_ID,

		};

		/// Error id. Default is ErrorDetails::ERROR_NOT_FOUND.
		hkEnum<ErrorID, int> id;
		/// Detailed error message, if error id is not ErrorDetails::ERROR_NOT_FOUND.
		hkStringPtr defaultMessage;
	};

	/// Option bits for saving.
	enum SaveOptionBits
	{
		SAVE_DEFAULT					= 0x00,		///< All flags default to OFF; enable whichever are needed
		SAVE_TEXT_FORMAT				= 0x01,		///< Use text (usually XML) format; default is binary format if available.
		SAVE_SERIALIZE_IGNORED_MEMBERS	= 0x02,		///< Write members which are usually ignored; default is to skip SERIALIZE_IGNORED members.
		SAVE_WRITE_ATTRIBUTES			= 0x04,		///< Include extended attributes in metadata; default is to write minimum metadata.
		SAVE_CONCISE					= 0x08,		///< Doesn't provide any extra information which would make the file easier to interpret. E.g. additionally write hex floats as text comments.
		SAVE_TEXT_NUMBERS				= 0x10,		///< Floating point numbers output as text, not as binary. Makes them easily readable/editable, but values may not be exact.
	};

	struct SaveOptions : public hkFlags<SaveOptionBits, int>
	{
		SaveOptions(SaveOptionBits b = SAVE_DEFAULT) : hkFlags<SaveOptionBits, int>(b) {}
	};

	enum LoadOptionBits
	{
		LOAD_DEFAULT			= 0x00,	///< All flags default to OFF, enable whichever are needed
		LOAD_FAIL_IF_VERSIONING = 0x01,	///< Allows a way to skip versioning paths (if current version needs to be enforced)
		LOAD_FORCED				= 0x02, ///< Force load.
	};

	/// Options for loading.
	struct LoadOptions : public hkFlags<LoadOptionBits, int>
	{
		const class hkClassNameRegistry* m_classNameReg;
		const class hkTypeInfoRegistry* m_typeInfoReg;

		LoadOptions(LoadOptionBits b = LOAD_DEFAULT) : hkFlags<LoadOptionBits, int>(b), m_classNameReg(0), m_typeInfoReg(0) {}
	};

	SDK_SINLINE hkResource* load(const char* filename, ErrorDetails* detailsOut = 0, LoadOptions options = LOAD_DEFAULT) { 
		return SDK_CALL_FUNC(hkResource*, 0xE3A030, const char*, ErrorDetails*, LoadOptions*)(filename, detailsOut, &options);
	}

	SDK_SINLINE hkResult save(const void* object, hkClass* klass, hkStreamWriter* writer, SaveOptions options = SAVE_DEFAULT)
	{
		hkResult res;
		return *SDK_CALL_FUNC(hkResult*, 0xE3A920, hkResult*, const void*, hkClass*, hkStreamWriter*, SaveOptions)(&res, object, klass, writer, options);
	}

	SDK_SINLINE hkResult savePackfile(const void* object, hkClass* klass, hkStreamWriter* writer, const hkPackfileWriter::Options& packFileOptions, void* userListener = 0, SaveOptions options = SAVE_DEFAULT)
	{
		hkResult res;
		return *SDK_CALL_FUNC(hkResult*, 0xE3A590, hkResult*, const void*, hkClass*, hkStreamWriter*, const hkPackfileWriter::Options&, void*, SaveOptions)(&res, object, klass, writer, packFileOptions, userListener, options);
	}
}