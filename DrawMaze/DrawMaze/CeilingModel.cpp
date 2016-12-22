#include "CeilingModel.h"

using namespace BasicEngine;
using namespace Rendering;
using namespace Models;
using namespace DrawMaze;
using namespace MazeModel;

#define PI 3.14159265


CeilingModel::CeilingModel() {
}

CeilingModel::~CeilingModel() {
}

void CeilingModel::Create(glm::vec3 wspolzedne, colorT type)
{
	GLuint vao;
	GLuint vbo;
	GLuint ibo;


	glGenVertexArrays(1, &vao);
	glBindVertexArray(vao);

	this->wspolzedne = wspolzedne;
	this->type = type;

	double i = wspolzedne.x;
	double j = wspolzedne.y;
	double k = wspolzedne.z;
	double i_t = i *2.0;
	double j_t = j*2.0;
	double k_t = k*2.0;
	double mjeden = -1.0;
	double ulamek = -1.0 + 2.0;

	std::vector<unsigned int> indices = { 0, 1, 2, 0, 2, 3, //up
		};

	//up
	vertices.push_back(VertexFormat(glm::vec3(mjeden + i_t, ulamek + j_t, ulamek + k_t), glm::vec2(1, 1)));
	vertices.push_back(VertexFormat(glm::vec3(ulamek + i_t, ulamek + j_t, ulamek + k_t), glm::vec2(0, 1)));
	vertices.push_back(VertexFormat(glm::vec3(ulamek + i_t, ulamek + j_t, mjeden + k_t), glm::vec2(0, 0)));
	vertices.push_back(VertexFormat(glm::vec3(mjeden + i_t, ulamek + j_t, mjeden + k_t), glm::vec2(1, 0)));

	glGenBuffers(1, &vbo);
	glBindBuffer(GL_ARRAY_BUFFER, vbo);
	glBufferData(GL_ARRAY_BUFFER, vertices.size() * sizeof(VertexFormat), &vertices[0], GL_STATIC_DRAW);

	glGenBuffers(1, &ibo);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ibo);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, indices.size() * sizeof(unsigned int), &indices[0], GL_STATIC_DRAW);

	glEnableVertexAttribArray(0);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(VertexFormat), (void*)0);
	glEnableVertexAttribArray(1);
	glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, sizeof(VertexFormat), (void*)(offsetof(VertexFormat, VertexFormat::texture)));
	glBindVertexArray(0);
	this->vao = vao;
	this->vbos.push_back(vbo);
	this->vbos.push_back(ibo);

}

void CeilingModel::Update()
{

}

void CeilingModel::Draw(const glm::mat4& projection_matrix,
	const glm::mat4& view_matrix)
{
	glUseProgram(program);
	glBindVertexArray(vao);

	glActiveTexture(GL_TEXTURE0);
	glBindTexture(GL_TEXTURE_2D, this->GetTexture("CeilingTexture"));
	unsigned int textureLocation = glGetUniformLocation(program, "texture1");
	glUniform1i(textureLocation, 0);

	glUniformMatrix4fv(glGetUniformLocation(program, "view_matrix"),
		1, false, &view_matrix[0][0]);
	glUniformMatrix4fv(glGetUniformLocation(program, "projection_matrix"),
		1, false, &projection_matrix[0][0]);

	glDrawElements(GL_TRIANGLES, vertices.size() * 3 / 2, GL_UNSIGNED_INT, 0);

}
