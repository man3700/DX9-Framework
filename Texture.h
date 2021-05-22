#pragma once

struct Texture
{
public:
	Texture(DXImage _image, DXImageInfo _info) : mImage(_image), mInfo(_info) {}
	~Texture() {}

public:
	DXImage mImage;
	DXImageInfo mInfo;

};
