#include "ConsoleDisplay.h"
#include <cstdlib>
#include <iostream>
#include <stdexcept>

using namespace std;

ConsoleDisplay::ConsoleDisplay(const char widths[], const char panels, const char height) : 
				w(widths, widths + panels), h(height), p(panels), lastRow(0)
{
	for (int i = 0; i < p; ++i)
		screen.push_back(vector<string>());

	for (screenIt_t s_it = screen.begin(); s_it != screen.end(); ++s_it)
		for (int i = 0; i < h; ++i)
			(*s_it).push_back(string());
}

void ConsoleDisplay::clear()
{
	for (screenIt_t s_it = screen.begin(); s_it != screen.end(); ++s_it)
		for (panelIt_t p_it = (*s_it).begin(); p_it != (*s_it).end(); ++p_it)
			(*p_it).clear(); // Clear string

	lastRow = 0;

	stream.clear();
}

void ConsoleDisplay::refresh()
{
	system("clear"); // FIXME: Use curses lib
	
	vector<string> screenOut(lastRow + 1);

	char panel = 0;
	// Build up the output
	for (screenIt_t s_it = screen.begin(); s_it != screen.end(); ++s_it) {
		panelIt_t p_it = (*s_it).begin();
		for (panelIt_t scrOut_it = screenOut.begin(); scrOut_it != screenOut.end(); ++scrOut_it) {
			try {
				// Append panel string plus padding
				(*scrOut_it) += ((*p_it) + string(w[panel] - (*p_it).length(), ' ') + "  ");
			} catch (const length_error& le) {
				(*scrOut_it) += ((*p_it) + "  ");
			}
			++p_it;
		}
		++panel;
	}

	// Output each row of the screen
	for (panelIt_t p_it = screenOut.begin(); p_it != screenOut.end(); ++p_it)
		cout << *p_it << endl;

	// Output stream after panels
	for (panelIt_t st_it = stream.begin(); st_it != stream.end(); ++st_it)
		cout << *st_it << endl;
}

void ConsoleDisplay::write(const unsigned char panel, 
				const unsigned char row, 
				const string& str)
{
	if (panel >= p)
		return;
	else if (row >= h)
		return;
	else if (w[panel] < (screen[panel][row].length() + str.length()))
		return;
	else
		screen[panel][row] += str;

	if (lastRow < row)
		lastRow = row;
}

void ConsoleDisplay::write(const unsigned char panel, const string& str)
{
	if (p <= panel)
		return;
	else if (str.length() > w[panel])
		return;

	char row = 0;
	panelIt_t p_it = screen[panel].begin();
	while ((p_it != screen[panel].end()) && (!(*p_it).empty())) {
		++p_it;
		++row;
	}
	
	if (h <= row)
		return;

	(*p_it) += str;
	
	if (lastRow < row)
		lastRow = row;
}

void ConsoleDisplay::write(const string& str)
{
	stream.push_back(str);
}
