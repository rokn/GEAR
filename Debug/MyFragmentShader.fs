#version 330 core

in vec3 Color;
in vec2 TexCoords;

out vec4 outColor;

uniform sampler2D hsTexture;
uniform sampler2D floweyTex;

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
		outColor = mix(texture(hsTexture, InvertFixCoords), texture(floweyTex, InvertFixCoords), blendValue);
	}
}