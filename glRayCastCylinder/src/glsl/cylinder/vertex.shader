#version 450 core

layout ( location = 0 ) in vec3  position;
layout ( location = 1 ) in float radius;
layout ( location = 2 ) in float height;
layout ( location = 3 ) in int  sign;

out VS_OUT {

	float radius;
	float height;
	float sign;

} vs_out;

void main() {
	gl_Position   = vec4(position, 1.0f);
	vs_out.radius = radius;
	vs_out.height = height;
	vs_out.sign   = float(sign);
} 