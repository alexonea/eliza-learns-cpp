/*
 *  replyset.cc
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

#include "replyset.h"
#include "random.h"

#include <stdexcept>

namespace elizapp
{
  ReplySet::ReplySet(std::initializer_list<std::string> data)
  : m_vReplies{data}
  {
    if (m_vReplies.size() == 0)
      throw std::runtime_error("No reply given for reply set.");
  }

  std::string
  ReplySet::chooseReply() const
  {
    return m_vReplies[Random::getNext(m_vReplies.size())];
  }
}
