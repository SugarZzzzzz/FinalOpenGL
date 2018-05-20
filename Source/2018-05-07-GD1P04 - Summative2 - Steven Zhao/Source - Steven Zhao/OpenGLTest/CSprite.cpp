//
// Bachelor of Software Engineering
// Media Design School
// Auckland
// New Zealand
//
// (c) 2005 - 2018 Media Design School
//
// File Name	:	CSprite.cpp
// Description	:	main implementation for CSprite
// Author		:	Steven Zhao
// Mail 		:	steven.zha7447@mediadesign.school.nz
//

// Library Includes //

// Local Includes //

// This Includes //
#include "CSprite.h"

// Types //

using namespace std;

// Constructor //
CSprite::CSprite(const char* _fileName, float fWidth, float fHeight)
{
	GLuint vbo;
	GLuint ebo;
	GLuint tex;

	float HalfWidth = fWidth / 2;
	float HalfHeight = fHeight / 2;
	if (fWidth == 0 || fHeight == 0)
	{
		int nWidth, nHeight;
		unsigned char* image = SOIL_load_image(
			_fileName,				//File path/name
			&nWidth,							//Output for the image width
			&nHeight,						//Output for the image height
			0,								//Output for number of channels
			SOIL_LOAD_RGBA);
		SOIL_free_image_data(image);

		HalfWidth = nWidth;
		HalfHeight = nHeight;
	}
	GLfloat vertices[36] = {
		// Position			 //Colour			 //Tex Coords
		-HalfWidth, HalfHeight, 0.0f,   1.0f, 1.0f, 0.0f,   0.0f, 0.0f,  // Top Left 
		HalfWidth, HalfHeight, 0.0f,   1.0f, 0.0f, 0.0f,   1.0f, 0.0f,  // Top Right 
		HalfWidth, -HalfHeight, 0.0f,  0.0f, 1.0f, 0.0f,   1.0f, 1.0f,  // Bottom Right 
		-HalfWidth, -HalfHeight, 0.0f,  0.0f, 0.0f, 1.0f,   0.0f, 1.0f,  // Bottom Left
	};
	GLuint indices[6] =
	{
		0, 1, 2, // First Triangle 
		0, 2, 3  // Second Triangle

	};
	TextureLoader textureloader;
	glGenVertexArrays(1, &vao);
	glBindVertexArray(vao);
	glGenBuffers(1, &vbo);
	glBindBuffer(GL_ARRAY_BUFFER, vbo);
	glBufferData(GL_ARRAY_BUFFER,
		sizeof(vertices),
		vertices,
		GL_STATIC_DRAW);
	glVertexAttribPointer(
		0,						// Layout location on vertex shader
		3,						// 3 float components (eg position)
		GL_FLOAT,				// Type of data
		GL_FALSE,				// Data Normalised?
		8 * sizeof(GLfloat),	// Stride of the entire single vertex
		(GLvoid*)0);			// Offset

	glEnableVertexAttribArray(0);

	// New AttribPointer for Colour
	glVertexAttribPointer(
		1,									// Layout location on vertex shader
		3,									// 3 float components (eg position)
		GL_FLOAT,							// Type of data
		GL_FALSE,							// Data Normalised?
		8 * sizeof(GLfloat),				// Stride of the entire single vertex
		(GLvoid*)(3 * sizeof(GLfloat)));		// Offset
	glEnableVertexAttribArray(1);

	// EBO
	glGenBuffers(1, &ebo);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ebo);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER,
		sizeof(indices),
		indices,
		GL_STATIC_DRAW);

	glCullFace(GL_BACK); //Cull the back faces (basicly deletes the faces that are going in CCW)
	glFrontFace(GL_CW);  //Front face is Clockwise order
	//glEnable(GL_CULL_FACE);


	glGenTextures(1, &tex);
	glBindTexture(GL_TEXTURE_2D, tex);
	//Texture class to load images.
	textures.push_back(tex);

	textureloader.TexImage2D(CSprite::nWidth, CSprite::nHeight, textureloader.imageloader(_fileName, CSprite::nWidth, CSprite::nHeight));

	//Text Coord attribute pointer
	glVertexAttribPointer(
		2,			//Layout location on vertex shader
		2,			//2 float components for texture coords
		GL_FLOAT,    //Type of data
		GL_FALSE,   //Data normalised?
		8 * sizeof(GLfloat),		//Stride
		(GLvoid*)(6 * sizeof(GLfloat)));
	glEnableVertexAttribArray(2);
}

// Destructor //
CSprite::~CSprite()
{

}

void CSprite::render()
{
	glUseProgram(CUtility::program);
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	// Activating the texture and binding it
	glActiveTexture(GL_TEXTURE0);
	glBindTexture(GL_TEXTURE_2D, textures[iCurrentFrame]);
	glUniform1i(glGetUniformLocation(CUtility::program, "tex"), 0);

	glBindVertexArray(vao);			  // Bind VAO
	
	glm::mat4 MVP = CCamera::InstanceGet()->SetMVP(objPosition,objRotate,objScale);
	GLint MVPLoc = glGetUniformLocation(CUtility::program, "MVP");
	glUniformMatrix4fv(MVPLoc, 1, GL_FALSE, glm::value_ptr(MVP));

	glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);

	glBindVertexArray(0);			  // Unbind VAO
	
}

void CSprite::update()
{
}

void CSprite::addFrame(const char* _filename)
{
	GLuint tex;
	TextureLoader textureloader;

	glGenTextures(1, &tex);
	glBindTexture(GL_TEXTURE_2D, tex);
	//Texture class to load images.

	textureloader.TexImage2D(CSprite::nWidth, CSprite::nHeight, textureloader.imageloader(_filename, CSprite::nWidth, CSprite::nHeight));

	textures.push_back(tex);
}



