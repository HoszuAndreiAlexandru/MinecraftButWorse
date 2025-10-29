#version 330 core

layout(location = 0) in vec3 vertexPos; 

uniform mat4 transform;

void main(){

    gl_Position.xyz = vertexPos;
    gl_Position.w = 1.0;

	gl_Position = transform * gl_Position;
}

