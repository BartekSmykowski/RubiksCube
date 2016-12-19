#version 430 core
layout(location = 0) in vec4 in_position;
layout(location = 1) in vec4 in_color;

uniform mat4 projection_matrix, view_matrix;
uniform vec3 translation;

out vec4 color;

void main()
{

	color = in_color;

	mat4 translate;

	translate = mat4(1.0, 0.0, 0.0, 0.0,
					0.0, 1.0, 0.0, 0.0,
					0.0, 0.0, 1.0, 0.0,
					translation.x, translation.y, translation.z, 1.0);

	gl_Position = projection_matrix * view_matrix * translate *	in_position;

}