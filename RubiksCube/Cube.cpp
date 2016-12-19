#include "Cube.h"
#include <vector>

using namespace RubiksCube;

Cube::Cube() {

	this->translation = glm::vec3(0, 0, 0);
	bricksContainer = new BricksContainer();
	this->size = 3;
	bricksContainer->fill(3);
};

Cube::Cube(int size) {
	this->translation = glm::vec3(0, 0, 0);
	bricksContainer = new BricksContainer(size);
	this->size = size;
	bricksContainer->fill(size);
}

RubiksCube::Cube::Cube(int size, glm::vec3 translation)
{
	this->translation = translation;
	bricksContainer = new BricksContainer(size, translation);
	this->size = size;
	bricksContainer->fill(size);
}

//zmienia wsp�edne klock�w w kostce jednej �ciany wall po obrocie w kierunku direction
//czyli zgodnie albo przeciwnie do ruchu wskaz�wek zegara
void Cube::rotate_wall(orientation_type wall, rotate_direction_t direction) {
	if (!this->bricksContainer->IsRotating()) {
		//obr�cenie to transformacja p�aszcyzny wystarczy zamieni� odpowiednie osie z innymi, albo je odwr�ci� i przesun��
		//na te osie mo�na wyprowadzi� funkcje, s� one wyznaczane w poni�szym case w zale�no�ci od tego kt�r� �cian� chcemy obraca�
		//i wkt�r� stron�
		int axx = 0, ayx = 0, azx = 0, bx = 0;       //wp�czyniki przy x, y, z i wolny przy obliczaniu wsp�rz�dnej x
		int axy = 0, ayy = 0, azy = 0, by = 0;       //wp�czyniki przy x, y, z i wolny przy obliczaniu wsp�rz�dnej y
		int axz = 0, ayz = 0, azz = 0, bz = 0;       //wp�czyniki przy x, y, z i wolny przy obliczaniu wsp�rz�dnej z
		int iprim = 0;         //wp�rz�dne x po obr�ceniu
		int jprim = 0;         //wp�rz�dne y po obr�ceniu
		int kprim = 0;         //wp�rz�dne z po obr�ceniu
		int iloops = 0, iloope = size;    //p�tla prechodz�ca po wsp�rz�dnej x
		int jloops = 0, jloope = size;    //p�tla prechodz�ca po wsp�rz�dnej y
		int kloops = 0, kloope = size;    //p�tla prechodz�ca po wsp�rz�dnej z

		switch (wall) {                 //ustalanie wsp�czynnik�w funkcji i pocz�tk�w i ko�c�w p�tli
		case DOWN:                      //w zale�no�ci od kierunku i p�aszczyzny obrotu
			azx = -1; bx = size - 1;
			ayy = 1;
			axz = 1;
			jloope = 1;
			break;
		case UP:
			azx = 1;
			ayy = 1;
			axz = -1; bz = size - 1;
			jloops = size - 1;
			break;
		case RIGHT:
			axx = 1;
			azy = -1; by = size - 1;
			ayz = 1;
			iloops = size - 1;
			break;
		case LEFT:
			axx = 1;
			azy = 1;
			ayz = -1; bz = size - 1;
			iloope = 1;
			break;
		case BACK:
			ayx = 1;
			axy = -1; by = size - 1;
			azz = 1;
			kloope = 1;
			break;
		case FRONT:
			ayx = -1; bx = size - 1;
			axy = 1;
			azz = 1;
			kloops = size - 1;
			break;
		}

		int strona = 0;     //jak jest przeciwnie do ruchu wskaz�wek zegara to obr�t nast�puhje 3 razy
		if (direction == CLOCK) {
			strona = 1;
		}
		else {
			strona = 3;
		}

		BricksContainer *bricks_tmp = new BricksContainer(*bricksContainer);
		//inicjacja tablicy pomocniczej do przechowywania aktualnej kostki
		//pomaga to w rozwi�zywaniu przypadku w kt�rym chcemy przepisa� ju� przepisany klocek

		for (; strona > 0; strona--) {  //licznik ile razy obr�ci� �cian�
			for (int i = iloops; i < iloope; i++) {          //p�tla w kt�rej dokonuje si� w�a�ciwy obr�t
				for (int j = jloops; j < jloope; j++) {
					for (int k = kloops; k < kloope; k++) {
						iprim = axx*i + ayx*j + azx*k + bx;
						jprim = axy*i + ayy*j + azy*k + by;
						kprim = axz*i + ayz*j + azz*k + bz;
						bricks_tmp->setBrick(glm::vec3(i, j, k), bricksContainer->getBrick(glm::vec3(iprim, jprim, kprim)));
						if (bricks_tmp->getBrick(glm::vec3(i, j, k)) != nullptr) {
							bricks_tmp->getBrick(glm::vec3(i, j, k))->rotate(wall, direction);
							bricks_tmp->getBrick(glm::vec3(i, j, k))->StartAnimate(wall, direction);
						}
					}
				}
			}
			bricksContainer = bricks_tmp;
		}
	}

};

void Cube::KeyEventCallback(unsigned char key, int x, int y) {
	switch (key) {
	case 'u':
		rotate_wall(UP, CLOCK);
		break;
	}
}

//zwraca klocek o podanych wsp��dych z kostki
Brick *Cube::get_brick(glm::vec3 w) {
	return bricksContainer->getBrick(w);
}

//zwraca kolor nankleki klocka [x][y][z] zwr�conej w kierunku wall
Color_t Cube::get_brick_color(glm::vec3 w, orientation_type which) {
	if (bricksContainer->getBrick(w) != nullptr) {
		return bricksContainer->getBrick(w)->get_color(which);
	}
	return N;
}

void RubiksCube::Cube::setRotation(glm::vec3 rotation)
{
	animator.setRotationAngle(rotation);
}

glm::vec3 RubiksCube::Cube::getRotation()
{
	return animator.GetRotationAngle();
}

int RubiksCube::Cube::getSize()
{
	return size;
}

Cube::~Cube() {
	bricksContainer->~BricksContainer();
}
