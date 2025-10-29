#version 330 core

out vec4 fragCol;

uniform vec4 color;

void main()
{
	fragCol = color;
}