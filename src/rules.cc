/*
 *  rules.cc
 *
 *  Copyright (C) 2018 Alexandru N. Onea <alexandru.onea@toporcomputing.com>
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

#include "rules.h"
#include "replyset.h"

#include <utility>

namespace elizapp
{
  using RulesMap = std::vector<std::pair<std::regex, ReplySet>>;

  static const
  std::regex
  _REGEX_(const std::string &sPattern)
  {
    return std::regex(sPattern, std::regex_constants::icase);
  }

  static const
  RulesMap s_vElizaRules
  {
      {
        _REGEX_("(?:^|\\W)hello(?:$|\\W)"),
        {
          "How do you do. Please state your problem."
        }
      },
      {
        _REGEX_("(?:^|\\W)computer(?:$|\\W)"),
        {
          "Do computers worry you?",
          "What do you think about machines?",
          "Why do you mention computers?",
          "What do you think machines have to do with your problem?"
        }
      }
  };

  std::string
  matchInput(const std::string &sInputStr)
  {
    for (const auto & ex : s_vElizaRules)
    {
      if (std::regex_search(sInputStr, ex.first))
      {
        return ex.second.chooseReply();
      }
    }

    return "What do you mean by that?";
  }
}
