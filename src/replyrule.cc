/*
 *  replyrule.cc
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

#include "replyrule.h"
#include "utility.h"

#include <functional>

namespace elizapp
{
  ReplyRule::ReplyRule(const std::string &sPattern, ReplySetData replies)
  : m_regex{sPattern, std::regex_constants::icase}
  , m_replies{replies}
  {}

  bool
  ReplyRule::matchInput(const std::string &sInStr, std::string &sOutStr) const
  {
    std::smatch match;

    if (!std::regex_search(sInStr, match, m_regex))
     return false;

    std::string out = m_replies.chooseReply();

    /*
     * If reply contains a placeholder for a prefix, replace it here
     */
    {
      auto it = out.find("<P>");
      if (it != std::string::npos)
      {
        std::string sAppend = ReplyRule::switchViewpoint(match.prefix());
        out.replace(it, 3, sAppend);
      }
    }

    /*
     * If reply contains a placeholder for a suffix, replace it here
     */
    {
      auto it = out.find("<S>");
      if (it != std::string::npos)
      {
        std::string sAppend = ReplyRule::switchViewpoint(match.suffix());
        out.replace(it, 3, sAppend);
      }
    }

    /*
     * If reply contains a placeholder for a middle section, replace it here
     *
     * Note: currently this is an ugly hack because there is no easy way to
     * define patterns with middle groups (i.e. smth X smth Y smth, where X
     * and Y are the patterns)
     */
    {
      auto it = out.find("<M>");
      if (it != std::string::npos)
      {
        if (match.size() > 1)
        {
          std::string sAppend = ReplyRule::switchViewpoint(match[1]);
          out.replace(it, 3, sAppend);
        }
      }
    }

    sOutStr.swap(out);
    return true;
  }

  /*
   * Switch of viewpoint functionality below.
   * Will be moved in its own file at a later point.
   */

  using ReplaceFunc = std::function<void(std::string&)>;

  /*
   * We must give arguments by value here because of the way the functions
   * are created below. Since they are created only once at the first call
   * of the viewport switching method, the parameters used in the creation
   * of the functions are gone and thus, any reference to them is, well,
   * the source of all evil.
   */
  static
  void
  doReplace(std::string &s, std::regex e, std::string r)
  {
    std::string sRes = std::regex_replace(s, e, r);
    s.swap(sRes);
  }

  static
  ReplaceFunc
  __REPLACEMENT__(const std::string &sPattern, const std::string &sReplacement)
  {
    using namespace std::placeholders;

    return std::bind(
        doReplace,
        _1,
        std::regex("(?:^|\\b)" + sPattern + "(?:$|\\b)"),
        sReplacement);
  }

  std::string
  ReplyRule::switchViewpoint(const std::string &sInput)
  {
    /*
     * Add _ before and after the replacement to avoid double replacements
     * caused by consecutive runs of rules replacing same words.
     *
     * We are lucky here that _ is considered a word character and contributes
     * to the regex match.
     */
    static std::vector<ReplaceFunc> s_mViewpoints
    {
      __REPLACEMENT__("you", "_I_"),
      __REPLACEMENT__("I",   "_you_"),
      __REPLACEMENT__("am",  "_are_"),
      __REPLACEMENT__("me",  "_you_")
    };

    std::string sOutput{sInput};
    std::for_each(s_mViewpoints.begin(), s_mViewpoints.end(),
        [&sOutput] (const ReplaceFunc &rfn)
        {
          rfn(sOutput);
        }
    );

    /*
     * Clean up the _ occurrences. See above.
     */

    std::string::size_type pos;
    while ((pos = sOutput.find("_")) != std::string::npos)
    {
      sOutput.erase(pos, 1);
    }

    return sOutput;
  }
}
