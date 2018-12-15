/*
 *  main.cpp
 *
 *  Copyright (C) 2018  Alexandru N. Onea <alexandru.onea@toporcomputing.com>
 *
 *  This program is free software: you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation, either version 3 of the License, or
 *  (at your option) any later version.
 *
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with this program.  If not, see <https://www.gnu.org/licenses/>.
 */

#include <iostream>
#include <string>
#include <csignal>

#include "rules.h"

static const char* PROMPT = "ELIZA> ";
static       bool  bDone  = false;

void
signalHandler(int signum)
{
  bDone = true;
}

int
main(int argc, const char *argv[])
{
  std::cout << "Welcome to Eliza++ v0.1 Copyright (C) 2018 Alexandru N. Onea\n"
            << "This program comes with ABSOLUTELY NO WARRANTY.\n"
            << "This is free software, and you are welcome to redistribute it\n"
            << "under certain conditions. For more information please contact\n"
            << "Alexandru N. Onea <alexandru.onea@toporcomputing.com>\n\n";

  signal(SIGINT, signalHandler);

  do
  {
    std::cout << PROMPT;

    /*
     * Read a line from standard input.
     */
    std::string sInputLine;
    std::getline(std::cin, sInputLine);

    /*
     * Check for EOF and (possibly) other read errors.
     */
    if (std::cin.bad())
    {
      std::cerr << "Oops! Something bad happened while reading from stdin.\n";
      break;
    }
    else if (std::cin.eof())
    {
      break;
    }

    /*
     * Match the input string and produce a reply.
     */
    std::cout << elizapp::matchInput(sInputLine) << "\n";

  } while (!bDone);

  std::cout << "\nBye.\n";
  return 0;
}
