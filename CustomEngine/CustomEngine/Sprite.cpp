#include "Sprite.h"



Sprite::Sprite()
{
	_vboID = 0;
}


Sprite::~Sprite()
{
	if (_vboID != 0)
	{
		glDeleteBuffers(1, &_vboID);
	}
}

void Sprite::init(float x, float y, float width, float height)
{
	_x = x;
	_y = y;
	_width = width;
	_height = height;

	if (_vboID == 0)
	{
		glGenBuffers(1, &_vboID);
	}

	float vertexData[12];
	 
	//topright
	vertexData[0] = x + width;
	vertexData[1] = y + height;

	//topleft
	vertexData[2] = x;
	vertexData[3] = y + height;

	//bottomleft
	vertexData[4] = x;
	vertexData[5] = y;

	//bottomleft
	vertexData[6] = x;
	vertexData[7] = y;

	//bottomright
	vertexData[8] = x + width;
	vertexData[9] = y;

	//topright
	vertexData[10] = x + width;
	vertexData[11] = y + height;

	glBindBuffer(GL_ARRAY_BUFFER, _vboID);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertexData), vertexData, GL_STATIC_DRAW);

	glBindBuffer(GL_ARRAY_BUFFER, 0);
}

void Sprite::draw()
{
	glBindBuffer(GL_ARRAY_BUFFER, _vboID);

	glEnableVertexAttribArray(0);
	glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 0, 0);
	glDrawArrays(GL_TRIANGLES, 0, 6);

	glDisableVertexAttribArray(0);
	glBindBuffer(GL_ARRAY_BUFFER, 0);
}
