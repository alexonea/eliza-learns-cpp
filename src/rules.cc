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
#include "replyrule.h"

#include <utility>

namespace elizapp
{
  using RulesMap = std::vector<ReplyRule>;

  static const
  std::string
  __REGEX__(const std::string &sWord)
  {
    return "(?:^|\\W)" + sWord + "(?:$|\\W)";
  }

  static const
  RulesMap s_vElizaRules
  {
    {
      __REGEX__("hello"),
      {
        "How do you do. Please state your problem."
      }
    },
    {
      __REGEX__("computer"),
      {
        "Do computers worry you?",
        "What do you think about machines?",
        "Why do you mention computers?",
        "What do you think machines have to do with your problem?"
      }
    },
    {
      __REGEX__("name"),
      {
        "I am not interested in names"
      }
    },
    {
    __REGEX__("sorry"),
      {
        "Please don't apologize",
        "Apologies are not necessary",
        "What feelings do you have when you apologize"
      }
    }
  };

  std::string
  elizaReply(const std::string &sInputStr)
  {
    std::string sOutputStr;
    for (const auto & rule : s_vElizaRules)
    {
      if (rule.matchInput(sInputStr, sOutputStr))
      {
        return sOutputStr;
      }
    }

    return "What do you mean by that?";
  }
}
