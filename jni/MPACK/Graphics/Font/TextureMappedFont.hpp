/*
	This file is owned by Murtaza Alexandru and may not be distributed, edited or used without written permission of the owner
	When using this work you accept to keep this header
	E-mails from murtaza_alexandru73@yahoo.com with permissions can be seen as valid.
*/



#ifndef MPACK_TEXTUREMAPPEDFONT_HPP
#define MPACK_TEXTUREMAPPEDFONT_HPP

#include "Texture2D.hpp"
#include "Vertex.hpp"
#include "Debug.hpp"
#include "Math.hpp"
#include "Sprite.hpp"

#include <vector>
#include <string>

namespace MPACK
{
	namespace Graphics
	{
		struct CellSpacing
		{
			GLfloat top,bottom,left,right;
		};

		enum Align
		{
			ALIGN_LEFT_TOP,
			ALIGN_CENTER
		};

		class TextureMappedFont
		{
		public:
			TextureMappedFont();

			enum CaseType{NONE, UPPERCASE, LOWERCASE};

			void SetFontSize(GLfloat fontSize);
			void SetCharSpacing(GLfloat charSpacing=0.0f);
			void SetMonospaced(bool monospaced=true);
			void SendString(std::string str, GLfloat x, GLfloat y, Align alignType=ALIGN_LEFT_TOP, std::vector<Math::Vector4f> *colorPattern=NULL);

			void SetCase(CaseType caseType);
			CaseType GetCase() const;

			bool 		Load(const std::string& textureName);

			Texture2D* 	GetTexturePointer();

			GLfloat 	GetFontSize() const;
			GLfloat 	GetTextWidth(const std::string &str);

			GLfloat 		m_layer;

		private:
			Texture2D		m_texture;

			GLfloat			m_fontSize;
			GLfloat			m_charSpacing;
			bool			m_monospaced;

			CellSpacing		m_cellSpacing[16][16];

			CaseType		m_caseType;
		};
	}
}

#endif
