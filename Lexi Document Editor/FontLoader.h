#pragma once
#include <string>
#include "SFML/Graphics/Font.hpp"
#include "type.h"
/*
* The fontloader is a class that stores fonts that have been loaded into memory
* The fonts are loaded from the font folder or other specified paths
*
*/
class FontLoader
{
public:
	/*
	*	font loads specified font from memory if the font has not been loaded into memory yet
	*	the font will be loaded from disk. if the font does not exist then the function will return nullptr
	*	
	*	@param font_name is the name of the font being loaded and does not include the parent directory.
	*/
	static Font * Load_Font(std::string font_name);

	/*
	*	retrieves the default font found locally in the project directory
	*/
	static Font * Load_Default_Font();
private:
	FontLoader();
	~FontLoader();
	std::string m_fontsPath;
	std::map<std::string, Font*> m_loadedFonts;
	Font * m_defaultFont;


};

