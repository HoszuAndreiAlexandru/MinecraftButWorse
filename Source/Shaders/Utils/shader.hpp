#pragma once
#include <stdio.h>
#include <string>
#include <vector>
#include <iostream>
#include <fstream>
#include <algorithm>
#include <stdlib.h>
#include <string.h>
#include <sstream>

using namespace std;

// Include GLEW
#include "glew\glew.h"

GLuint LoadShaders(const char * vertex_file_path,const char * fragment_file_path);