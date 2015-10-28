#define NONE 					0.0
#define ALPHA_TEST 				1.0
#define ALPHA_BLEND				2.0
#define NOTEXTURE				3.0
#define COLOR_SUM_ALPHA_BLEND	4.0

uniform mat4 projection_matrix;

attribute  vec2  a_Vertex;
attribute  vec2  a_TexCoord;
attribute  vec4  a_Color;
attribute  float a_ShadeType;

varying vec2  texCoord;
varying vec4  color;
varying float shadeType;

void main(void)
{
	texCoord = a_TexCoord;
	color=a_Color;
	shadeType=a_ShadeType;
	
	vec4 pos = vec4(a_Vertex, 1.0, 1.0);
	gl_Position = projection_matrix * pos;
}
