#ifndef MPACK_RENDERTEXTURE_HPP
#define MPACK_RENDERTEXTURE_HPP

#include "Texture2D.hpp"

namespace MPACK
{
	namespace Graphics
	{
		class RenderTexture
		{
		public:
			RenderTexture();
			~RenderTexture();

			void Init(GLuint width, GLuint height);
			void Bind();
			void Unbind();

			GLuint		m_FBOId;
			Texture2D	*m_colorTex;
			GLuint 		m_depthRBOId;
		};
	}
}

#endif
