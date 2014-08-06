#ifndef CONSOLEDISPLAY_H
#define CONSOLEDISPLAY_H

#include <vector>
#include <string>

class ConsoleDisplay {
public:
	typedef std::vector<std::vector<std::string> >::iterator screenIt_t;
	typedef std::vector<std::string>::iterator panelIt_t;

	// Constructor
	ConsoleDisplay(char pCount, char pWidth, char pHeight);

	void clear();
	void refresh();
	void write(const unsigned char panel, const std::string& str);
	void write(const unsigned char panel, const unsigned char row, const std::string& str);
private:
	const char count, width, height;
	char lastRow;
	std::vector< std::vector<std::string> > screen;
};

#endif // CONSOLEDISPLAY_H
