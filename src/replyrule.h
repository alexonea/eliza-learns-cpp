/*
 *  replyrule.h
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

#ifndef REPLYRULE_H_
#define REPLYRULE_H_

#include "replyset.h"

#include <regex>

namespace elizapp
{
  using ReplySetData = std::initializer_list<std::string>;

  class ReplyRule
  {
  public:
    ReplyRule(const std::string &sPattern, ReplySetData replies);

    bool matchInput(const std::string &sInStr, std::string &sOutStr) const;
  private:
    std::regex  m_regex;
    ReplySet    m_replies;
  };
}

#endif /* REPLYRULE_H_ */
