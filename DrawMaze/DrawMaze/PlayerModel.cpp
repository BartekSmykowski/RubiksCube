#include "PlayerModel.h"

using namespace BasicEngine;
using namespace Rendering;
using namespace Models;
using namespace DrawMaze;
using namespace MazeModel;

#define PI 3.14159265


PlayerModel::PlayerModel() {
}

PlayerModel::~PlayerModel() {
}

void PlayerModel::Create(Player *player)
{
	GLuint vao;
	GLuint vbo;
	GLuint ibo;


	glGenVertexArrays(1, &vao);
	glBindVertexArray(vao);

	this->player = player;
	this->wspolzedne = player->GetCamera()->GetEyeVector();

	player->GetCamera()->GetEyeVector();

	indices = { 0, 1, 2, 0, 2, 3, //front
		4, 5, 6, 4, 6, 7, //right
		8, 9, 10, 8, 10, 11 , //back
		12, 13, 14, 12, 14, 15 }; //left

	double i = 0;
	double j = 0;
	double k = 0;
	double i_t = i *1.0;
	double j_t = j*1.0 - 0.5;
	double k_t = k*1.0;
	double mjeden = -0.05;
	double ulamek = -0.05 + 0.1;

	//front
	vertices.push_back(VertexFormat(glm::vec3(mjeden + i_t, mjeden + j_t, ulamek + k_t), glm::vec2(1, 1)));
	vertices.push_back(VertexFormat(glm::vec3(ulamek + i_t, mjeden + j_t, ulamek + k_t), glm::vec2(0, 1)));
	vertices.push_back(VertexFormat(glm::vec3(ulamek + i_t, ulamek + j_t, ulamek + k_t), glm::vec2(0, 0)));
	vertices.push_back(VertexFormat(glm::vec3(mjeden + i_t, ulamek + j_t, ulamek + k_t), glm::vec2(1, 0)));

	//right
	vertices.push_back(VertexFormat(glm::vec3(ulamek + i_t, ulamek + j_t, ulamek + k_t), glm::vec2(1, 0)));
	vertices.push_back(VertexFormat(glm::vec3(ulamek + i_t, ulamek + j_t, mjeden + k_t), glm::vec2(0, 0)));
	vertices.push_back(VertexFormat(glm::vec3(ulamek + i_t, mjeden + j_t, mjeden + k_t), glm::vec2(0, 1)));
	vertices.push_back(VertexFormat(glm::vec3(ulamek + i_t, mjeden + j_t, ulamek + k_t), glm::vec2(1, 1)));

	//back
	vertices.push_back(VertexFormat(glm::vec3(mjeden + i_t, mjeden + j_t, mjeden + k_t), glm::vec2(0, 1)));
	vertices.push_back(VertexFormat(glm::vec3(ulamek + i_t, mjeden + j_t, mjeden + k_t), glm::vec2(1, 1)));
	vertices.push_back(VertexFormat(glm::vec3(ulamek + i_t, ulamek + j_t, mjeden + k_t), glm::vec2(1, 0)));
	vertices.push_back(VertexFormat(glm::vec3(mjeden + i_t, ulamek + j_t, mjeden + k_t), glm::vec2(0, 0)));

	//left
	vertices.push_back(VertexFormat(glm::vec3(mjeden + i_t, mjeden + j_t, mjeden + k_t), glm::vec2(1, 1)));
	vertices.push_back(VertexFormat(glm::vec3(mjeden + i_t, mjeden + j_t, ulamek + k_t), glm::vec2(0, 1)));
	vertices.push_back(VertexFormat(glm::vec3(mjeden + i_t, ulamek + j_t, ulamek + k_t), glm::vec2(0, 0)));
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

void PlayerModel::Update()
{
}


void PlayerModel::Draw(const glm::mat4& projection_matrix,
	const glm::mat4& view_matrix)
{
	glUseProgram(program);
	glBindVertexArray(vao);

	glActiveTexture(GL_TEXTURE0);
	glBindTexture(GL_TEXTURE_2D, this->GetTexture("PlayerTexture"));
	unsigned int textureLocation = glGetUniformLocation(program, "texture1");
	glUniform1i(textureLocation, 0);

	glUniform3f(glGetUniformLocation(program, "rotation"),
		0,
		-player->GetCamera()->GetYaw(),
		0);
	glUniform3f(glGetUniformLocation(program, "translation"),
		player->GetCamera()->GetEyeVector().x,
		player->GetCamera()->GetEyeVector().y,
		player->GetCamera()->GetEyeVector().z
		);
	glUniformMatrix4fv(glGetUniformLocation(program, "view_matrix"),
		1, false, &view_matrix[0][0]);
	glUniformMatrix4fv(glGetUniformLocation(program, "projection_matrix"),
		1, false, &projection_matrix[0][0]);

	glDrawElements(GL_TRIANGLES, vertices.size() * 3 / 2, GL_UNSIGNED_INT, 0);

}
