#version 330 core

in vec2 TexCoords;

out vec4 outColor;

uniform sampler2D texture1;
uniform sampler2D texture2;

uniform float blendValue;
uniform int wireframeMode;

void main()
{
	if(wireframeMode == 1)
	{
		outColor = vec4(1.0,1.0,1.0,1.0);
	}
	else
	{
		vec2 InvertFixCoords = vec2(TexCoords.x, 1 - TexCoords.y);
		outColor = mix(texture(texture1, InvertFixCoords), texture(texture2, InvertFixCoords), blendValue);
	}
}