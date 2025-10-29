#pragma once
#include "Types/AudioFileManager.hpp"
#include "Types/ImageFileManager.hpp"
#include "Types/ModelFileManager.hpp"
#include "Types/SaveFileManager.hpp"

class ResourceManager {
public:
	AudioFileManager* audioFileManager = nullptr;
	ImageFileManager* imageFileManager = nullptr;
	ModelFileManager* modelFileManager = nullptr;
	SaveFileManager* saveFileManager = nullptr;

	ResourceManager();
	~ResourceManager();
};