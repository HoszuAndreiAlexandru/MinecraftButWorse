// pch.h
#pragma once

// Windows 
#define WIN32_LEAN_AND_MEAN
#define NOMINMAX              // to prevent min/max macro conflicts
#include <windows.h>

#pragma region Standard Libraries
using namespace std;

#include <string>
#include <vector>
#include <iostream>
#include <chrono>
#include <stdio.h>
#include <stdlib.h>
#include <fstream>
#include <algorithm>
#include <string.h>
#include <sstream>
#include <stdexcept>
#include <filesystem>
#pragma endregion

#pragma region Externals
#include "glew/glew.h"
#include "glfw/glfw3.h"

#include "glm/glm.hpp"
#include "glm/gtc/matrix_transform.hpp"
#include "glm/gtc/type_ptr.hpp"

#include "AL/al.h"
#include "AL/alc.h"

#include <assimp/Importer.hpp>
#include <assimp/scene.h>
#include <assimp/postprocess.h>
#pragma endregion