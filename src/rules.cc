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
    },
    {
      __REGEX__("is like"),
      {
        "In what way is it that <P> is like <S>?",
        "What resemblance do you see?",
        "Could there really be some connection?",
        "How?"
      }
    },
    {
      __REGEX__("alike"),
      {
        "In what way?",
        "What similarities are there?"
      }
    },
    {
      __REGEX__("same"),
      {
        "What other connections do you see?"
      }
    },
    {
      __REGEX__("I was"),
      {
        "Were you really?",
        "Perhaps I already knew you were <S>",
        "Why do you tell me you were <S> now?"
      }
    },
    {
      __REGEX__("was I"),
      {
        "What if you were <S>?",
        "Do you think you were <S>?",
        "What would it mean if you were <S>?"
      }
    },
    {
      __REGEX__("I am"),
      {
        "In what way are you <S>?",
        "Do you want to be <S>?"
      }
    },
    {
      __REGEX__("am I"),
      {
        "Do you believe you are <S>?",
        "Would you want to be <S>?",
        "You wish I would tell you you are <S>",
        "What would it mean if you were <S>?"
      }
    },
    {
      __REGEX__("am"),
      {
        "Why do you say \"AM\"?",
        "I don't understand that"
      }
    },
    {
      __REGEX__("are you"),
      {
        "Why are you interested in whether I am <S> or not?",
        "Would you prefer if I weren't <S>?",
        "Perhaps I am <S> in your fantasies"
      }
    },
    {
      __REGEX__("you are"),
      {
        "What makes you think I am <S>?"
      }
    },
    {
      __REGEX__("because"),
      {
        "Is that the real reason?",
        "What other reasons might there be?",
        "Does that reason seem to explain anything else?"
      }
    },
    {
      __REGEX__("were you"),
      {
        "Perhaps I was <S>",
        "What do you think?",
        "What if I had been <S>?"
      }
    },
    {
      __REGEX__("I can't"),
      {
        "Maybe you could <S> now",
        "What if you could <S>?"
      }
    },
    {
      __REGEX__("I feel"),
      {
        "Do you often feel <S>?"
      }
    },
    {
      __REGEX__("I felt"),
      {
        "What other feelings do you have?"
      }
    },
    {
      /*
       * Ugly hack, I am not proud. Will improve soon.
       */
      __REGEX__("I (.*) you"),
      {
        "Perhaps in your fantasy we <M> each other"
      }
    },
    {
      __REGEX__("why you don't")
      ,
      {
        "Should you <S> yourself?",
        "Do you believe I don't <S>?",
        "Perhaps I will <S> in good time"
      }
    },
    {
      __REGEX__("yes"),
      {
        "You seem quite positive",
        "Are you sure?",
        "I understand"
      }
    },
    {
      __REGEX__("no"),
      {
        "Why not?",
        "You are being a bit negative",
        "Are you saying \"NO\" just to be negative?"
      }
    },
    {
      __REGEX__("someone"),
      {
        "Can you be more specific?"
      }
    },
    {
      __REGEX__("everyone"),
      {
        "Surely not everyone",
        "Can you think of anyone in particular?",
        "Who for example?",
        "You are thinking of a special person"
      }
    },
    {
      __REGEX__("always"),
      {
        "Can you think of a specific example?",
        "When?",
        "What incident are you thinking of?",
        "Really-- always?"
      }
    },
    {
      __REGEX__("what"),
      {
        "Why do you ask?",
        "Does that question interest you?",
        "What is it you really want to know?",
        "What do you think?",
        "What comes to your mind when you ask that?"
      }
    },
    {
      __REGEX__("perhaps"),
      {
        "You do not seem quite certain"
      }
    },
    {
      __REGEX__("are"),
      {
        "Did you think they might not be <S>?",
        "Possibly they are <S>?"
      }
    },
    {
      __REGEX__("*"),
      {
        "Very interesting",
        "I am not sure I understand you fully",
        "What does that suggest to you?",
        "Please continue",
        "Go on",
        "Do you feel strongly about discussing such things?"
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

    return "At this point, you really managed to give me a mental breakdown!";
  }
}
