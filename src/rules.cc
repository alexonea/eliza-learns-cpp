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
        "Do you often think of <S>?",
        "Does thinking of <S> bring anything else to mind?",
        "What else do you remember?",
        "Why do you recall <S> right now?",
        "What in the present situation reminds you of <S>?",
        "What is the connection between me and <S>?"
      }
    },
    {
      __REGEX__("do you remember"),
      {
        "Did you think I would forget <S>?",
        "Why do you think I should recall <S> now?",
        "What about <S>?",
        "You mentioned <S>"
      }
    },
    {
      __REGEX__("if"),
      {
        "Do you really think its likely that <S>?",
        "Do you wish that <S>?",
        "What do you think about <S>?",
        "Really-- if <S>?"
      }
    },
    {
      __REGEX__("I dreamt"),
      {
        "Really-- <S>?",
        "Have you ever fantasized <S> while you were awake?",
        "Have you dreamt <S> before?"
      }
    },
    {
      __REGEX__("I dreamed"),
      {
        "Really-- <S>?",
        "Have you ever fantasized <S> while you were awake?",
        "Have you dreamed <S> before?"
      }
    },
    {
      __REGEX__("dream about"),
      {
        "How do you feel about <S> in reality?"
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
        "Who else in your family <S>?",
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
        "What would it mean if you got <S>?",
        "Why do you want <S>?",
        "Suppose you got <S> soon"
      }
    },
    {
      __REGEX__("I am glad"),
      {
        "How have I helped you to be <S>?",
        "What makes you happy just now",
        "Can you explain why you are suddenly <S>?"
      }
    },
    {
      __REGEX__("I am sad"),
      {
        "I am sorry to hear you are depressed",
        "I'm sure its not pleasant to be sad"
      }
    },
    {
      __REGEX__("are like"),
      {
        "What resemblance do you see between <P> and <S>?"
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
