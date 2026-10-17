#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

#include <palerain.h>

#define STBI_MAX_DIMENSIONS 4096
#define STBI_ONLY_BMP
#define STBI_ONLY_JPEG
#define STBI_ONLY_PNG
#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"

#define PONGO_BACKGROUND_MAX_SIDE 1024

uint8_t* pongo_background_rgb;
uint32_t pongo_background_width;
uint32_t pongo_background_height;
uint32_t pongo_background_size;

void pongo_background_free(void)
{
	free(pongo_background_rgb);
	pongo_background_rgb = NULL;
	pongo_background_width = 0;
	pongo_background_height = 0;
	pongo_background_size = 0;
}

int pongo_background_load(const char* path)
{
	int source_width;
	int source_height;
	uint8_t* source;
	uint8_t* scaled;
	uint32_t width;
	uint32_t height;
	uint64_t byte_count;

	pongo_background_free();
	source = stbi_load(path, &source_width, &source_height, NULL, 3);
	if (source == NULL) {
		const char* reason = stbi_failure_reason();
		LOG(LOG_FATAL, "Cannot decode PongoOS background %s: %s", path, reason ? reason : "unsupported image or invalid file");
		return -1;
	}
	if (source_width <= 0 || source_height <= 0) {
		stbi_image_free(source);
		LOG(LOG_FATAL, "PongoOS background has invalid dimensions");
		return -1;
	}

	width = (uint32_t)source_width;
	height = (uint32_t)source_height;
	if (width > PONGO_BACKGROUND_MAX_SIDE || height > PONGO_BACKGROUND_MAX_SIDE) {
		if (width >= height) {
			height = (uint32_t)(((uint64_t)height * PONGO_BACKGROUND_MAX_SIDE) / width);
			width = PONGO_BACKGROUND_MAX_SIDE;
		} else {
			width = (uint32_t)(((uint64_t)width * PONGO_BACKGROUND_MAX_SIDE) / height);
			height = PONGO_BACKGROUND_MAX_SIDE;
		}
		if (width == 0) width = 1;
		if (height == 0) height = 1;
	}

	byte_count = (uint64_t)width * height * 3;
	if (byte_count > UINT32_MAX) {
		stbi_image_free(source);
		LOG(LOG_FATAL, "PongoOS background is too large");
		return -1;
	}
	scaled = malloc((size_t)byte_count);
	if (scaled == NULL) {
		stbi_image_free(source);
		LOG(LOG_FATAL, "Cannot allocate memory for PongoOS background");
		return -1;
	}

	for (uint32_t y = 0; y < height; ++y) {
		uint32_t source_y = (uint32_t)(((uint64_t)y * (uint32_t)source_height) / height);
		for (uint32_t x = 0; x < width; ++x) {
			uint32_t source_x = (uint32_t)(((uint64_t)x * (uint32_t)source_width) / width);
			uint64_t source_index = ((uint64_t)source_y * (uint32_t)source_width + source_x) * 3;
			uint64_t output_index = ((uint64_t)y * width + x) * 3;
			scaled[output_index + 0] = source[source_index + 0];
			scaled[output_index + 1] = source[source_index + 1];
			scaled[output_index + 2] = source[source_index + 2];
		}
	}
	stbi_image_free(source);

	pongo_background_rgb = scaled;
	pongo_background_width = width;
	pongo_background_height = height;
	pongo_background_size = (uint32_t)byte_count;
	return 0;
}
