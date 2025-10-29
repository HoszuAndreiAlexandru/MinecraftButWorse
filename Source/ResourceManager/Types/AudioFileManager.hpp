#pragma once
#include "../BaseFileManager/BaseFileManager.hpp"

#include "AL/al.h"
#include "AL/alc.h"

class AudioFileManager : BaseFileManager {
public:
	AudioFileManager();
	~AudioFileManager();
};