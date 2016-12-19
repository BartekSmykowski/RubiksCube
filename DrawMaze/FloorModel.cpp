//RCube.cpp
#include "FloorModel.h"

using namespace BasicEngine;
using namespace Rendering;
using namespace Models;

#define PI 3.14159265

FloorModel::FloorModel() {
}

FloorModel::~FloorModel() {
}

void FloorModel::Create(double height)
{
	GLuint vao;
	GLuint vbo;

	translate = glm::vec3(0, height, 0);

	time(&timer);

	vertices.push_back(VertexFormat(glm::vec4(0, 0, 0, 1), glm::vec4(0, 0, 0, 0)));
	vertices.push_back(VertexFormat(glm::vec4(1, 0, 0, 0), glm::vec4(1, 1, 0, 0)));
	vertices.push_back(VertexFormat(glm::vec4(0, 0, 1, 0), glm::vec4(1, 0, 0, 0)));

	vertices.push_back(VertexFormat(glm::vec4(0, 0, 0,1), glm::vec4(0, 0, 0, 0)));
	vertices.push_back(VertexFormat(glm::vec4(-1, 0, 0,0), glm::vec4(0, 1, 0, 0)));
	vertices.push_back(VertexFormat(glm::vec4(0, 0, -1,0), glm::vec4(0, 0, 0, 0)));

	vertices.push_back(VertexFormat(glm::vec4(0, 0, 0, 1), glm::vec4(0, 0, 0, 0)));
	vertices.push_back(VertexFormat(glm::vec4(-1, 0, 0, 0), glm::vec4(0, 1, 0, 0)));
	vertices.push_back(VertexFormat(glm::vec4(0, 0, 1, 0), glm::vec4(1, 0, 0, 0)));

	vertices.push_back(VertexFormat(glm::vec4(0, 0, 0, 1), glm::vec4(0, 0, 0, 0)));
	vertices.push_back(VertexFormat(glm::vec4(1, 0, 0, 0), glm::vec4(1, 1, 0, 0)));
	vertices.push_back(VertexFormat(glm::vec4(0, 0, -1, 0), glm::vec4(0, 0, 0, 0)));

	glGenVertexArrays(1, &vao);
	glBindVertexArray(vao);

	glGenBuffers(1, &vbo);
	glBindBuffer(GL_ARRAY_BUFFER, vbo);

	glBufferData(GL_ARRAY_BUFFER, sizeof(VertexFormat) * vertices.size(), &vertices[0], GL_STATIC_DRAW);
	glEnableVertexAttribArray(0);
	glVertexAttribPointer(0, 4, GL_FLOAT, GL_FALSE, sizeof(VertexFormat), (void*)(offsetof(VertexFormat, VertexFormat::position4)));
	glEnableVertexAttribArray(1);
	glVertexAttribPointer(1, 4, GL_FLOAT, GL_FALSE, sizeof(VertexFormat), (void*)(offsetof(VertexFormat, VertexFormat::color)));
	glBindVertexArray(0);
	this->vao = vao;
	this->vbos.push_back(vbo);
}

void FloorModel::Draw(const glm::mat4& projection_matrix,
	const glm::mat4& view_matrix)
{

	glUseProgram(program);
	glUniform3f(glGetUniformLocation(program, "translation"),
		translate.x,
		translate.y,
		translate.z);
	glUniformMatrix4fv(glGetUniformLocation(program, "view_matrix"), 1,
		false, &view_matrix[0][0]);
	glUniformMatrix4fv(glGetUniformLocation(program, "projection_matrix"), 1, false, &projection_matrix[0][0]);
	glBindVertexArray(vao);
	glDrawArrays(GL_TRIANGLES, 0, vertices.size());

}

void FloorModel::Update()
{
}
