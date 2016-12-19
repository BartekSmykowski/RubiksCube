//RCube.cpp
#include "RCube.h"

using namespace BasicEngine;
using namespace Rendering;
using namespace Models;

#define PI 3.14159265

RCube::RCube()
{
}

RCube::~RCube()
{
}

void RCube::Create()
{
	GLuint vao;
	GLuint vbo;

	time(&timer);

	glGenVertexArrays(1, &vao);
	glBindVertexArray(vao);

	float F[4][3] = { 0.0, 0.0, 0.0,	//czarny
		1.0, 0.0, 0.0,  //czerwony
		1.0, 1.0, 0.0,  //¿ó³ty
		0.0, 1.0, 0.0 };//zielony

	float R[4][3] = { 1.0, 0.0, 1.0,  //magente
		1.0, 0.0, 0.0,  //czerwony
		1.0, 1.0, 0.0,  //zolty
		1.0, 1.0, 1.0 }; //bialy

	float B[4][3] = { 1.0, 0.0, 1.0,  //magente
		0.0, 1.0, 1.0,  //cyan
		0.0, 0.0, 1.0,  //niebieski
		1.0, 1.0, 1.0 }; //bialy

	float L[4][3] = { 0.0, 0.0, 1.0,  //niebieski
		0.0, 0.0, 0.0,  //czarny
		0.0, 1.0, 0.0,  //zielony
		0.0, 1.0, 1.0 };//cyan

	float U[4][3] = { 0.0, 1.0, 0.0,  //zielony
		1.0, 1.0, 0.0,  //zolty
		1.0, 1.0, 1.0,  //bialy
		0.0, 1.0, 1.0 };  //cyan

	float D[4][3] = { 0.0, 0.0, 1.0,  //niebieski
		1.0, 0.0, 1.0,  //cyan
		1.0, 0.0, 0.0,  //czerwony
		0.0, 0.0, 0.0 }; //czarny

	std::vector<VertexFormat> vertices;
	//vertices for the front face of the RCube
	for (double i = 0; i < 3; i++) {
		for (double j = 0; j < 3; j++) {
			vertices.push_back(VertexFormat(glm::vec3(-1.0 + 2 * i / 3, -1.0 + 2 * j / 3, 1.0),
				glm::vec4(F[0][0], F[0][1], F[0][2], 1.0)));
			vertices.push_back(VertexFormat(glm::vec3(-1.0 / 3 + 2 * i / 3, -1.0 + 2 * j / 3, 1.0),
				glm::vec4(F[1][0], F[1][1], F[1][2], 1.0)));
			vertices.push_back(VertexFormat(glm::vec3(-1.0 / 3 + 2 * i / 3, -1.0 / 3 + 2 * j / 3, 1.0),
				glm::vec4(F[2][0], F[2][1], F[2][2], 1.0)));

			vertices.push_back(VertexFormat(glm::vec3(-1.0 / 3 + 2 * i / 3, -1.0 / 3 + 2 * j / 3, 1.0),
				glm::vec4(F[2][0], F[2][1], F[2][2], 1.0)));
			vertices.push_back(VertexFormat(glm::vec3(-1.0 + 2 * i / 3, -1.0 / 3 + 2 * j / 3, 1.0),
				glm::vec4(F[3][0], F[3][1], F[3][2], 1.0)));
			vertices.push_back(VertexFormat(glm::vec3(-1.0 + 2 * i / 3, -1.0 + 2 * j / 3, 1.0),
				glm::vec4(F[0][0], F[0][1], F[0][2], 1.0)));
		}
	}

	//vertices for the right face of the RCube
	for (double i = 0; i < 3; i++) {
		for (double j = 0; j < 3; j++) {
			vertices.push_back(VertexFormat(glm::vec3(1.0, -1.0 / 3 + 2 * i / 3, -1.0 / 3 + 2 * j / 3),
				glm::vec4(R[2][0], R[2][1], R[2][2], 1.0)));
			vertices.push_back(VertexFormat(glm::vec3(1.0, -1.0 / 3 + 2 * i / 3, -1.0 + 2 * j / 3),
				glm::vec4(R[3][0], R[3][1], R[3][2], 1.0)));
			vertices.push_back(VertexFormat(glm::vec3(1.0, -1.0 + 2 * i / 3, -1.0 + 2 * j / 3),
				glm::vec4(R[0][0], R[0][1], R[0][2], 1.0)));

			vertices.push_back(VertexFormat(glm::vec3(1.0, -1.0 / 3 + 2 * i / 3, -1.0 / 3 + 2 * j / 3),
				glm::vec4(R[2][0], R[2][1], R[2][2], 1.0)));
			vertices.push_back(VertexFormat(glm::vec3(1.0, -1.0 + 2 * i / 3, -1.0 + 2 * j / 3),
				glm::vec4(R[0][0], R[0][1], R[0][2], 1.0)));
			vertices.push_back(VertexFormat(glm::vec3(1.0, -1.0 + 2 * i / 3, -1.0 / 3 + 2 * j / 3),
				glm::vec4(R[1][0], R[1][1], R[1][2], 1.0)));
		}
	}

	//vertices for the back face of the RCube
	for (double i = 0; i < 3; i++) {
		for (double j = 0; j < 3; j++) {
			vertices.push_back(VertexFormat(glm::vec3(-1.0 + 2 * i / 3, -1.0 + 2 * j / 3, -1.0),
				glm::vec4(B[2][0], B[2][1], B[2][2], 1.0)));
			vertices.push_back(VertexFormat(glm::vec3(-1.0 / 3 + 2 * i / 3, -1.0 + 2 * j / 3, -1.0),
				glm::vec4(B[0][0], B[0][1], B[0][2], 1.0)));
			vertices.push_back(VertexFormat(glm::vec3(-1.0 / 3 + 2 * i / 3, -1.0 / 3 + 2 * j / 3, -1.0),
				glm::vec4(B[3][0], B[3][1], B[3][2], 1.0)));

			vertices.push_back(VertexFormat(glm::vec3(-1.0 + 2 * i / 3, -1.0 + 2 * j / 3, -1.0),
				glm::vec4(B[2][0], B[2][1], B[2][2], 1.0)));
			vertices.push_back(VertexFormat(glm::vec3(-1.0 / 3 + 2 * i / 3, -1.0 / 3 + 2 * j / 3, -1.0),
				glm::vec4(B[3][0], B[3][1], B[3][2], 1.0)));
			vertices.push_back(VertexFormat(glm::vec3(-1.0 + 2 * i / 3, -1.0 / 3 + 2 * j / 3, -1.0),
				glm::vec4(B[1][0], B[1][1], B[1][2], 1.0)));
		}
	}

	//vertices for the left face of the RCube
	for (double i = 0; i < 3; i++) {
		for (double j = 0; j < 3; j++) {
			vertices.push_back(VertexFormat(glm::vec3(-1.0, -1.0 / 3 + 2 * i / 3, -1.0 / 3 + 2 * j / 3),
				glm::vec4(L[2][0], L[2][1], L[2][2], 1.0)));
			vertices.push_back(VertexFormat(glm::vec3(-1.0, -1.0 / 3 + 2 * i / 3, -1.0 + 2 * j / 3),
				glm::vec4(L[3][0], L[3][1], L[3][2], 1.0)));
			vertices.push_back(VertexFormat(glm::vec3(-1.0, -1.0 + 2 * i / 3, -1.0 + 2 * j / 3),
				glm::vec4(L[0][0], L[0][1], L[0][2], 1.0)));

			vertices.push_back(VertexFormat(glm::vec3(-1.0, -1.0 / 3 + 2 * i / 3, -1.0 / 3 + 2 * j / 3),
				glm::vec4(L[2][0], L[2][1], L[2][2], 1.0)));
			vertices.push_back(VertexFormat(glm::vec3(-1.0, -1.0 + 2 * i / 3, -1.0 + 2 * j / 3),
				glm::vec4(L[0][0], L[0][1], L[0][2], 1.0)));
			vertices.push_back(VertexFormat(glm::vec3(-1.0, -1.0 + 2 * i / 3, -1.0 / 3 + 2 * j / 3),
				glm::vec4(L[1][0], L[1][1], L[1][2], 1.0)));
		}
	}

	//vertices for the upper face of the RCube
	for (double i = 0; i < 3; i++) {
		for (double j = 0; j < 3; j++) {
			vertices.push_back(VertexFormat(glm::vec3(-1.0 / 3 + 2 * i / 3, 1.0, -1.0 / 3 + 2 * j / 3),
				glm::vec4(U[1][0], U[1][1], U[1][2], 1.0)));
			vertices.push_back(VertexFormat(glm::vec3(-1.0 + 2 * i / 3, 1.0, -1.0 / 3 + 2 * j / 3),
				glm::vec4(U[0][0], U[0][1], U[0][2], 1.0)));
			vertices.push_back(VertexFormat(glm::vec3(-1.0 / 3 + 2 * i / 3, 1.0, -1.0 + 2 * j / 3),
				glm::vec4(U[2][0], U[2][1], U[2][2], 1.0)));

			vertices.push_back(VertexFormat(glm::vec3(-1.0 + 2 * i / 3, 1.0, -1.0 / 3 + 2 * j / 3),
				glm::vec4(U[0][0], U[0][1], U[0][2], 1.0)));
			vertices.push_back(VertexFormat(glm::vec3(-1.0 / 3 + 2 * i / 3, 1.0, -1.0 + 2 * j / 3),
				glm::vec4(U[2][0], U[2][1], U[2][2], 1.0)));
			vertices.push_back(VertexFormat(glm::vec3(-1.0 + 2 * i / 3, 1.0, -1.0 + 2 * j / 3),
				glm::vec4(U[3][0], U[3][1], U[3][2], 1.0)));
		}
	}

	//vertices for the bottom face of the RCube
	for (double i = 0; i < 3; i++) {
		for (double j = 0; j < 3; j++) {
			vertices.push_back(VertexFormat(glm::vec3(-1.0 / 3 + 2 * i / 3, -1.0, -1.0 / 3 + 2 * j / 3),
				glm::vec4(D[2][0], D[2][1], D[2][2], 1.0)));
			vertices.push_back(VertexFormat(glm::vec3(-1.0 + 2 * i / 3, -1.0, -1.0 / 3 + 2 * j / 3),
				glm::vec4(D[3][0], D[3][1], D[3][2], 1.0)));
			vertices.push_back(VertexFormat(glm::vec3(-1.0 / 3 + 2 * i / 3, -1.0, -1.0 + 2 * j / 3),
				glm::vec4(D[1][0], D[1][1], D[1][2], 1.0)));

			vertices.push_back(VertexFormat(glm::vec3(-1.0 + 2 * i / 3, -1.0, -1.0 / 3 + 2 * j / 3),
				glm::vec4(D[3][0], D[3][1], D[3][2], 1.0)));
			vertices.push_back(VertexFormat(glm::vec3(-1.0 / 3 + 2 * i / 3, -1.0, -1.0 + 2 * j / 3),
				glm::vec4(D[1][0], D[1][1], D[1][2], 1.0)));
			vertices.push_back(VertexFormat(glm::vec3(-1.0 + 2 * i / 3, -1.0, -1.0 + 2 * j / 3),
				glm::vec4(D[0][0], D[0][1], D[0][2], 1.0)));
		}
	}

	glGenBuffers(1, &vbo);
	glBindBuffer(GL_ARRAY_BUFFER, vbo);

	glBufferData(GL_ARRAY_BUFFER, sizeof(VertexFormat) * 324, &vertices[0], GL_STATIC_DRAW);
	glEnableVertexAttribArray(0);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(VertexFormat), (void*)0);
	glEnableVertexAttribArray(1);
	glVertexAttribPointer(1, 4, GL_FLOAT, GL_FALSE, sizeof(VertexFormat), (void*)(offsetof(VertexFormat, VertexFormat::color)));
	glBindVertexArray(0);
	this->vao = vao;
	this->vbos.push_back(vbo);

	rotation_speed = glm::vec3(5.0, 8.0, 10.0);
	rotation = glm::vec3(0.0, 0.0, 0.0);

}

void RCube::Update()
{

}

void RCube::Draw(const glm::mat4& projection_matrix,
	const glm::mat4& view_matrix)
{
	rotation = 0.01f * rotation_speed + rotation;

	glm::vec3 rotation_sin = glm::vec3(rotation.x * PI / 180, rotation.y * PI / 180, rotation.z * PI / 180);

	glUseProgram(program);
	glUniform3f(glGetUniformLocation(program, "rotation"),
		rotation_sin.x,
		rotation_sin.y,
		rotation_sin.z);
	glUniformMatrix4fv(glGetUniformLocation(program, "view_matrix"), 1,
		false, &view_matrix[0][0]);
	glUniformMatrix4fv(glGetUniformLocation(program, "projection_matrix"), 1, false, &projection_matrix[0][0]);
	glBindVertexArray(vao);
	glDrawArrays(GL_TRIANGLES, 0, 324);
}