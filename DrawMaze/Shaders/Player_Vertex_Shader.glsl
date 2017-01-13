#version 430 core
layout(location = 0) in vec3 in_position;
layout(location = 1) in vec2 in_texture;

uniform mat4 projection_matrix, view_matrix;
uniform vec3 rotation;
uniform vec3 translation;

out vec2 texcoord;

void main()
{

	texcoord = in_texture;

	mat4 rotate_y;

	rotate_y = mat4(cos(rotation.y), 0.0, -sin(rotation.y), 0.0,
					0.0, 1.0, 0.0, 0.0,
					sin(rotation.y), 0.0, cos(rotation.y), 0.0,
					0.0, 0.0, 0.0, 1.0);
					

	mat4 translate;

	translate = mat4(1.0, 0.0, 0.0, 0.0,
					0.0, 1.0, 0.0, 0.0,
					0.0, 0.0, 1.0, 0.0,
					translation.x, translation.y, translation.z, 1.0);


	gl_Position = projection_matrix * view_matrix * translate * rotate_y * vec4(in_position, 1);
	
}