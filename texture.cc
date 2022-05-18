/*
 * texture.cc
 *
 *  Created on: 18 мая 2022 г.
 *      Author: Vlad
 */

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include "texture.h"
#include <memory>
#include <string>
#include <stdexcept>

#include <GL/gl.h>
#include <GL/glu.h>

texture::texture(const char *filename) {
	auto image = std::shared_ptr<SDL_Surface>(
			IMG_Load(filename),
			SDL_FreeSurface);
	if (image == nullptr)
		throw std::runtime_error(
				std::string("Ошибка при загрузке текстуры: ") +
				std::string(SDL_GetError()));

	auto image2 = std::shared_ptr<SDL_Surface>(SDL_CreateRGBSurface(0,image->w,image->h,32,0x000000ff,0x0000ff00,0x00ff0000,0xff000000),SDL_FreeSurface);
	if (image2 == nullptr)
			throw std::runtime_error(
					std::string("Ошибка при создании текстуры: ") +
					std::string(SDL_GetError()));

	SDL_UpperBlit(image.get(), nullptr, image2.get(), nullptr);

	glGenTextures(1, &_tex);
	glBindTexture(GL_TEXTURE_2D, _tex);
	gluBuild2DMipmaps (GL_TEXTURE_2D, GL_RGBA,
			image2->w, image2->h,
			GL_RGBA, GL_UNSIGNED_BYTE,
			image2->pixels);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);

}

texture::~texture() {
	glDeleteTextures(1, &_tex);
}
