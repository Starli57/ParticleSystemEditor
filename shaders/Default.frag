#version 330 core

in vec4 vertColor;

out vec4 outColor;

void main()
{
    if (vertColor.a  < 0.01) discard;
    outColor = vertColor;
} 