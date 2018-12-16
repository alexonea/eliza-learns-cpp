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
        "What feelings do you have when you apologize?"
      }
    },
    {
      __REGEX__("I remember"),
      {
        "Do you often think of <X>?",
        "Does thinking of <X> bring anything else to mind?",
        "What else do you remember?",
        "Why do you recall <X> right now?",
        "What in the present situation reminds you of <X>?",
        "What is the connection between me and <X>?"
      }
    },
    {
      __REGEX__("do you remember"),
      {
        "Did you think I would forget <X>?",
        "Why do you think I should recall <X> now?",
        "What about <X>?",
        "You mentioned <X>"
      }
    },
    {
      __REGEX__("if"),
      {
        "Do you really think its likely that <X>?",
        "Do you wish that <X>?",
        "What do you think about <X>?",
        "Really-- if <X>?"
      }
    },
    {
      __REGEX__("I dreamt"),
      {
        "Really-- <X>?",
        "Have you ever fantasized <X> while you were awake?",
        "Have you dreamt <X> before?"
      }
    },
    {
      __REGEX__("I dreamed"),
      {
        "Really-- <X>?",
        "Have you ever fantasized <X> while you were awake?",
        "Have you dreamed <X> before?"
      }
    },
    {
      __REGEX__("dream about"),
      {
        "How do you feel about <X> in reality?"
      }
    },
    {
      __REGEX__("dream"),
      {
        "What does this dream suggest to you?",
        "Do you dream often?",
        "What persons appear in your dreams?",
        "Don't you believe that dream has to do with your problem?"
      }
    },
    {
      __REGEX__("my mother"),
      {
        "Who else in your family <X>?",
        "Tell me more about your family"
      }
    },
    {
      __REGEX__("my father"),
      {
        "Your father",
        "Does he influence you strongly?",
        "What else comes to mind when you think of your father?"
      }
    },
    {
      __REGEX__("I want"),
      {
        "What would it mean if you got <X>?",
        "Why do you want <X>?",
        "Suppose you got <X> soon"
      }
    },
    {
      __REGEX__("I am glad"),
      {
        "How have I helped you to be <X>?",
        "What makes you happy just now",
        "Can you explain why you are suddenly <X>?"
      }
    },
    {
      __REGEX__("I am sad"),
      {
        "I am sorry to hear you are depressed",
        "I'm sure its not pleasant to be sad"
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
