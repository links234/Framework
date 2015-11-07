#include "PNGImage.hpp"

#include <png.h>

#include "Image.hpp"
#include "Resource.hpp"
#include "SDInputFile.hpp"
#include "Asset.hpp"
#include "Misc.hpp"
#include "Log.hpp"

using namespace MPACK::Core;

namespace MPACK
{
	namespace Graphics
	{
		ReturnValue LoadPPM(Image *image, const std::string &path)
		{
			LOGE("LoadPPM() error: not implemented");
			return RETURN_VALUE_KO;
		}

		ReturnValue SavePPM(Image *image, const std::string &path)
		{
			LOGE("SavePPM() error: not implemented");
			return RETURN_VALUE_KO;
		}
	}
}