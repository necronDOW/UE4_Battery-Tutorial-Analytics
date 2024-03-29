#ifndef assetmanager_h_defined
#define assetmanager_h_defined

#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <direct.h>

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

class AssetManager
{
	public:
		/* SINGLETON
		static AssetManager& GetInstance()
		{
			static AssetManager instance;
			return instance;
		}

		AssetManager(AssetManager const&) = delete;
		void operator=(AssetManager const&) = delete;

		void ReadFile(std::string dir, std::string &out);
		void ReadFile(std::string dir, std::string* &out); */

		// NON-SINGLETON
		static void ReadFile(std::string dir, std::string &out);
		static void ReadFile(std::string dir, std::vector<std::string> &out);
		static bool FileExists(std::string dir);
		static std::string GetWorkingPath();
		static bool FindValue(std::string str, char id, float& out);
		static bool IsNum(std::string str);

	private:
		/* SINGLETON
		AssetManager() { } */

		// NON-SINGLETON

};

#endif