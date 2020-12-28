#include "FontLoader.h"
#include <exception>

#include <sys/stat.h>
#define _CRT_SECURE_NO_WARNINGS
#ifdef WIN32


std::string Find_Fonts_Directory() {
	char pathBuf[128];
	struct stat buffer;
	for (char c = 'A'; c <= 'Z'; c++) {
		pathBuf[0] = c;
		pathBuf[1] = 0;
		strcat_s(pathBuf, ":\\Windows\\Fonts\\");
		
		if (stat(pathBuf, &buffer) != -1) return std::string(pathBuf);
	}
	return "";
}
#endif

FontLoader * m_instance;

Font * FontLoader::Load_Font(std::string font_name)
{
	//get instance of FontLoader
	if (m_instance == nullptr) {
		m_instance = new FontLoader();
	}

	Font * font = new Font();
	if (m_instance->m_loadedFonts.count(font_name) == 0 && !font->loadFromFile(m_instance->m_fontsPath + font_name)) {
		return nullptr;
	}
	m_instance->m_loadedFonts[font_name] = font;
	return m_instance->m_loadedFonts[font_name];


}

Font * FontLoader::Load_Default_Font()
{
	if (m_instance == nullptr) {
		m_instance = new FontLoader();
	}
	return m_instance->m_defaultFont;
}

FontLoader::FontLoader()
{
	//find Fonts Directory
	this->m_fontsPath = Find_Fonts_Directory();
	
	//default font must exist in either the os path or the solution dir.
	Font * defaultFont = new Font();
	if (!defaultFont->loadFromFile("arial.ttf")) {
		throw new std::exception("failed to load default font\n");
	}
	this->m_defaultFont = defaultFont;

}

FontLoader::~FontLoader()
{
	delete this->m_defaultFont;
}
